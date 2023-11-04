/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:24:17 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/11/04 16:28:36 by yeonwkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philo;

	if (!(argc == 5 || argc == 6))
		return (arg_error());
	data_init(&data, argv, &philo);
	start_philo(philo);
}

void	data_init(t_data *data, char **argv, t_philo **philo)
{
	int	i;

	arg_init(&data->arg, argv);
	mutex_init(&data->fork, &data->arg);
	pthread_mutex_init(&data->print_lock, 0);
	*philo = (t_philo *)malloc(sizeof(t_philo) * (data->arg.num));
	i = 0;
	while (i < data->arg.num)
	{
		(*philo)[i].idx = i;
		(*philo)[i].last_eat = 0;
		(*philo)[i].left_eat = 0;
		(*philo)[i].data = data;
		i++;
	}
	gettimeofday(&data->tv, 0);
	data->start_time = (data->tv.tv_sec * 1000000 + data->tv.tv_usec) / 1000;
}
