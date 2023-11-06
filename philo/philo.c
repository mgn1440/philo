/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:31:12 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/11/07 04:12:29 by yeonwkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_philo(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo[0].data->arg.num)
	{
		pthread_create(&philo[i].thread, 0, run_philo, &philo[i]);
		i++;
	}
	check_death(philo[0].data, philo);
	join_all_thread(philo);
}

void	*run_philo(void *philo)
{
	t_philo	*a;

	a = philo;
	while (1)
	{
		if (a->data->is_death)
			return (0);
		take_fork(philo);
		print_eat(a->data, a->idx);
		pthread_mutex_lock(&a->data->data_mutex);
		a->left_eat--;
		a->last_eat = a->data->now_time;
		pthread_mutex_unlock(&a->data->data_mutex);
		get_sleep(a->data, a->data->arg.to_eat);
		usleep(10);
		drop_fork(philo);
		if (!a->left_eat)
			return (0);
		print_sleep(a->data, a->idx);
		get_sleep(a->data, a->data->arg.to_sleep);
		print_think(a->data, a->idx);
	}
	return (0);
}

void	join_all_thread(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo[0].data->arg.num)
	{
		pthread_join(philo[i].thread, 0);
		i++;
	}
}

void	get_sleep(t_data *data, int time)
{
	int	now;

	now = data->now_time;
	while (data->now_time - now < time)
	{
		usleep(200);
		// pthread_mutex_lock(&data->print_lock);
		// get_time(data);
		// pthread_mutex_unlock(&data->print_lock);
	}
}
