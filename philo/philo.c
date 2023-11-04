/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:31:12 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/11/04 16:51:37 by yeonwkan         ###   ########.fr       */
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
	join_all_thread(philo);
}

void	*run_philo(void *philo)
{
	t_philo	*a;

	a = philo;
	while (1)
	{
		take_fork(philo);
		print_eat(a->data, a->idx);
		a->last_eat = a->data->now_time;
		usleep(a->data->arg.to_eat * 1000);
		drop_fork(philo);
		print_sleep(a->data, a->idx);
		usleep(a->data->arg.to_sleep * 1000);
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
