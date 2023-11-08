/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:11:16 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/11/09 05:57:57 by yeonwkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_data *data, t_philo *philo)
{
	int	i;
	int	eat_done;
	int	now;

	i = 0 - 1;
	eat_done = 0;
	now = 0;
	while (1)
	{
		i = (i + 1) % data->arg.num;
		if (eat_done == data->arg.num)
			return (0);
		pthread_mutex_lock(&data->data_mutex);
		if (!philo[i].left_eat)
		{
			eat_done++;
			pthread_mutex_unlock(&data->data_mutex);
			continue ;
		}
		else
			eat_done = 0;
		pthread_mutex_unlock(&data->data_mutex);
		now = get_time(data);
		pthread_mutex_lock(&data->data_mutex);
		if (now - philo[i].last_eat > data->arg.to_die)
		{
			pthread_mutex_unlock(&data->data_mutex);
			print_died(data, i);
			if (data->arg.num == 1)
				pthread_detach(philo[i].thread);
			return (1);
		}
		pthread_mutex_unlock(&data->data_mutex);
	}
}
