/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:23:17 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/11/07 03:44:53 by yeonwkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_take_fork(t_data *data, int i)
{
	pthread_mutex_lock(&data->print_lock);
	if (data->is_death)
	{
		pthread_mutex_unlock(&data->print_lock);
		return ;
	}
	printf("%d %d has taken a fork\n", data->now_time - data->start_time, i);
	pthread_mutex_unlock(&data->print_lock);
}

void	print_eat(t_data *data, int i)
{
	pthread_mutex_lock(&data->print_lock);
	if (data->is_death)
	{
		pthread_mutex_unlock(&data->print_lock);
		return ;
	}
	printf("%d %d is eating\n", data->now_time - data->start_time, i);
	pthread_mutex_unlock(&data->print_lock);
}

void	print_sleep(t_data *data, int i)
{
	pthread_mutex_lock(&data->print_lock);
	if (data->is_death)
	{
		pthread_mutex_unlock(&data->print_lock);
		return ;
	}
	printf("%d %d is sleeping\n", data->now_time - data->start_time, i);
	pthread_mutex_unlock(&data->print_lock);
}

void	print_think(t_data *data, int i)
{
	pthread_mutex_lock(&data->print_lock);
	if (data->is_death)
	{
		pthread_mutex_unlock(&data->print_lock);
		return ;
	}
	printf("%d %d is thinking\n", data->now_time - data->start_time, i);
	pthread_mutex_unlock(&data->print_lock);
}

void	print_died(t_data *data, int i)
{
	pthread_mutex_lock(&data->print_lock);
	if (data->is_death)
	{
		pthread_mutex_unlock(&data->print_lock);
		return ;
	}
	data->is_death = 1;
	printf("%d %d died\n", data->now_time - data->start_time, i);
	pthread_mutex_unlock(&data->print_lock);
}
