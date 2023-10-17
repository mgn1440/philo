/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:24:17 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/10/17 20:38:51 by yeonwkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (!(argc == 5 || argc == 6))
		return (arg_error());
	data_init(&data, argv);
	start_philo(&data);
}

void	data_init(t_data *data, char **argv)
{
	int	i;

	arg_init(&data->arg, argv);
	mutex_init(data->fork, &data->arg);
	pthread_mutex_init(&data->print_lock, 0);
	data->philo = (t_philo *)malloc(sizeof(t_philo) * (data->arg.num));
	i = 0;
	while (i < data->arg.num)
	{
		data->philo[i].idx = i;
		data->philo[i].last_eat = 0;
		data->philo[i].left_eat = 0;
		data->philo[i].fork = &data->fork;
		data->philo[i].print_lock = &data->print_lock;
		data->philo[i].arg = &data->arg;
		i++;
	}
}
