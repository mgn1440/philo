/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:24:17 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/11/06 21:27:42 by yeonwkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philo;

	if (!(argc == 5 || argc == 6))
		return (arg_error());
	data_init(&data, argv, &philo, argc);
	start_philo(philo);
	// data_free(&data, &philo);
}

void	data_init(t_data *data, char **argv, t_philo **philo, int argc)
{
	int	i;

	arg_init(&data->arg, argv);
	mutex_init(&data->fork, &data->arg);
	pthread_mutex_init(&data->print_lock, 0);
	*philo = (t_philo *)malloc(sizeof(t_philo) * (data->arg.num));
	gettimeofday(&data->tv, 0);
	data->start_time = (data->tv.tv_sec * 1000000 + data->tv.tv_usec) / 1000;
	get_time(data);
	i = 0;
	while (i < data->arg.num)
	{
		(*philo)[i].idx = i;
		(*philo)[i].last_eat = data->start_time;
		if (argc == 6)
			(*philo)[i].left_eat = data->arg.num_of_eat;
		else
			(*philo)[i].left_eat = -1;
		(*philo)[i].data = data;
		i++;
	}
	data->is_death = 0;
	data->eat_done = data->arg.num;
}
