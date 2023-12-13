/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 21:24:13 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/11/28 19:37:01 by yeonwkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	data_free(t_data *data, t_philo **philo)
{
	fork_destroy(data->fork_mutex, data->arg.num);
	pthread_mutex_destroy(&data->print_lock);
	pthread_mutex_destroy(&data->death_lock);
	pthread_mutex_destroy(&data->left_eat_lock);
	pthread_mutex_destroy(&data->same_start_lock);
	free(data->fork);
	free(data->fork_mutex);
	free(*philo);
}

void	fork_destroy(pthread_mutex_t *fork, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		pthread_mutex_destroy(&fork[i]);
		i++;
	}
}
