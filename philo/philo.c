/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:31:12 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/10/31 20:53:39 by yeonwkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_philo(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo[0].data->arg.num)
	{
		pthread_create(&philo->thread, 0, run_philo, &philo[i]);
		i++;
	}
}

void	*run_philo(void *philo)
{
	t_philo	*a;

	a = philo;
	printf("%d\n", a->idx);
	usleep(1000);
	return (0);
}
