/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:11:16 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/12/02 03:31:30 by yeonwkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	death(t_data *data, t_philo *philo)
{
	int	i;
	int	eat_done;
	int	now;

	i = 0 - 1;
	eat_done = 0;
	while (1)
	{
		i = (i + 1) % data->arg.num;
		if (eat_done == data->arg.num)
			return (0);
		if (is_done(data, philo, &eat_done, i))
			continue ;
		now = get_time(data);
		pthread_mutex_lock(&data->death_lock);
		if (now - philo[i].last_eat > data->arg.to_die)
		{
			pthread_mutex_unlock(&data->death_lock);
			print_died(data, i);
			if (data->arg.num == 1)
				pthread_detach(philo[i].thread);
			return (0);
		}
		pthread_mutex_unlock(&data->death_lock);
	}
}

int	is_done(t_data *data, t_philo *philo, int *eat_done, int i)
{
	pthread_mutex_lock(&data->left_eat_lock);
	if (!philo[i].left_eat)
	{
		pthread_mutex_unlock(&data->left_eat_lock);
		(*eat_done) += 1;
		return (0);
	}
	else
	{
		pthread_mutex_unlock(&data->left_eat_lock);
		(*eat_done) = 0;
		return (1);
	}
}
