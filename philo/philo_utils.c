/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 03:10:05 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/12/08 02:13:47 by yeonwkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

void	usleep_ph(t_data *data, int time)
{
	int	before;
	int	now;
	int	sleep_time;

	sleep_time = time * 1000 / 2;
	before = get_time(data);
	now = before;
	while (now - before < time)
	{
		sleep_time /= 2;
		if (sleep_time < 200)
			sleep_time = 200;
		usleep(sleep_time);
		now = get_time(data);
	}
}

int	check_death(t_philo *p)
{
	pthread_mutex_lock(&p->data->print_lock);
	if (p->data->is_death)
	{
		pthread_mutex_unlock(&p->data->print_lock);
		return (1);
	}
	pthread_mutex_unlock(&p->data->print_lock);
	return (0);
}

void	reduce_left_eat(t_philo *p)
{
	pthread_mutex_lock(&p->data->left_eat_lock);
	if (p->left_eat > 0)
		p->left_eat--;
	pthread_mutex_unlock(&p->data->left_eat_lock);
}

void	get_last_eat_time(t_philo *p)
{
	pthread_mutex_lock(&p->data->death_lock);
	p->last_eat = get_time(p->data);
	pthread_mutex_unlock(&p->data->death_lock);
}
