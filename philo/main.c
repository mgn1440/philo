/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:24:17 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/11/28 23:08:46 by yeonwkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void a(void){
// 	system("leaks philo");
// }

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philo;

	// atexit(a);
	if (!(argc == 5 || argc == 6))
		return (arg_error());
	data_init(&data, argv, &philo, argc);
	start_philo(philo);
	data_free(&data, &philo);
}

void	data_init(t_data *data, char **argv, t_philo **philo, int argc)
{
	int	i;

	arg_init(&data->arg, argv);
	data->fork = (int *)malloc(sizeof(int) * data->arg.num);
	mutex_init(&data->fork_mutex, &data->arg);
	pthread_mutex_init(&data->print_lock, 0);
	pthread_mutex_init(&data->death_lock, 0);
	pthread_mutex_init(&data->left_eat_lock, 0);
	pthread_mutex_init(&data->same_start_lock, 0);
	*philo = (t_philo *)malloc(sizeof(t_philo) * (data->arg.num));
	data->start_time = get_time(data);
	i = 0;
	while (i < data->arg.num)
	{
		data->fork[i] = 1;
		(*philo)[i].idx = i;
		(*philo)[i].last_eat = data->start_time;
		(*philo)[i].left_eat = -1;
		if (argc == 6)
			(*philo)[i].left_eat = data->arg.num_of_eat;
		(*philo)[i].data = data;
		i++;
	}
	data->is_death = 0;
	data->eat_done = data->arg.num;
}
