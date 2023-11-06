/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:11:16 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/11/06 21:31:54 by yeonwkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_data *data, t_philo *philo)
{
	int	i;
	int	eat_done;

	i = 0 - 1;
	eat_done = 0;
	while (1)
	{
		i = (i + 1) % data->arg.num;
		if (eat_done == data->arg.num)
			return (0);
		get_time(data);
		if (!philo[i].left_eat)
		{
			eat_done++;
			continue ;
		}
		else
			eat_done = 0;
		if (data->now_time - philo[i].last_eat > data->arg.to_die)
		{
			print_died(data, i);
			return (1);
		}
	}
}
