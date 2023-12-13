/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:31:12 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/12/02 03:51:36 by yeonwkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_philo(t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&philo->data->same_start_lock);
	philo->data->start_time = get_time(philo->data);
	while (i < philo[0].data->arg.num)
	{
		pthread_create(&philo[i].thread, 0, run_philo, &philo[i]);
		i++;
	}
	pthread_mutex_unlock(&philo->data->same_start_lock);
	death(philo[0].data, philo);
	join_all_thread(philo);
	pthread_mutex_unlock(&philo->data->print_lock);
}

void	*run_philo(void *philo)
{
	t_philo	*p;

	p = philo;
	pthread_mutex_lock(&p->data->same_start_lock);
	pthread_mutex_unlock(&p->data->same_start_lock);
	print_think(p->data, p->idx);
	if (p->idx % 2)
		usleep(1000 * p->data->arg.to_eat / 2);
	while (1)
	{
		if (check_death(p))
			return (0);
		if (philo_cycle(p))
			return (0);
	}
	return (0);
}

int	philo_cycle(t_philo *p)
{
	if (take_fork(p))
	{
		print_eat(p->data, p->idx);
		usleep_ph(p->data, p->data->arg.to_eat);
		drop_fork(p);
		reduce_left_eat(p);
		get_last_eat_time(p);
		if (!p->left_eat)
			return (1);
		print_sleep(p->data, p->idx);
		usleep_ph(p->data, p->data->arg.to_sleep);
		usleep(200 + 1000 * \
			abs(p->data->arg.to_eat - p->data->arg.to_sleep));
		print_think(p->data, p->idx);
	}
	return (0);
}
