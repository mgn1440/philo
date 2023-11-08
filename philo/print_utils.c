/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:23:17 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/11/09 05:49:42 by yeonwkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_take_fork(t_data *data, int i)
{
	int	now;

	pthread_mutex_lock(&data->print_lock);
	if (data->is_death)
	{
		pthread_mutex_unlock(&data->print_lock);
		return ;
	}
	now = get_time(data);
	printf("%d %d has taken a fork\n", now - data->start_time, i);
	pthread_mutex_unlock(&data->print_lock);
}

void	print_eat(t_data *data, int i)
{
	int	now;

	pthread_mutex_lock(&data->print_lock);
	if (data->is_death)
	{
		pthread_mutex_unlock(&data->print_lock);
		return ;
	}
	now = get_time(data);
	printf("%d %d is eating\n", now - data->start_time, i);
	pthread_mutex_unlock(&data->print_lock);
}

void	print_sleep(t_data *data, int i)
{
	int	now;

	pthread_mutex_lock(&data->print_lock);
	if (data->is_death)
	{
		pthread_mutex_unlock(&data->print_lock);
		return ;
	}
	now = get_time(data);
	printf("%d %d is sleeping\n", now - data->start_time, i);
	pthread_mutex_unlock(&data->print_lock);
}

void	print_think(t_data *data, int i)
{
	int	now;

	pthread_mutex_lock(&data->print_lock);
	if (data->is_death)
	{
		pthread_mutex_unlock(&data->print_lock);
		return ;
	}
	now = get_time(data);
	printf("%d %d is thinking\n", now - data->start_time, i);
	pthread_mutex_unlock(&data->print_lock);
}

void	print_died(t_data *data, int i)
{
	int	now;

	pthread_mutex_lock(&data->print_lock);
	if (data->is_death)
	{
		pthread_mutex_unlock(&data->print_lock);
		return ;
	}
	now = get_time(data);
	pthread_mutex_lock(&data->data_mutex);
	data->is_death = 1;
	pthread_mutex_unlock(&data->data_mutex);
	printf("%d %d died\n", now - data->start_time, i);
	pthread_mutex_unlock(&data->print_lock);
}
