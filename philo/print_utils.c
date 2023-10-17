/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:23:17 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/10/17 16:28:12 by yeonwkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_take_fork(struct timeval *tv, int i)
{
	gettimeofday(tv, 0);
	printf("%d %d has taken a fork\n", tv->tv_usec, i);
}

void	print_eat(struct timeval *tv, int i)
{
	gettimeofday(tv, 0);
	printf("%d %d is eating\n", tv->tv_usec, i);
}

void	print_sleep(struct timeval *tv, int i)
{
	gettimeofday(tv, 0);
	printf("%d %d is sleeping\n", tv->tv_usec, i);
}


void	print_think(struct timeval *tv, int i)
{
	gettimeofday(tv, 0);
	printf("%d %d is thinking\n", tv->tv_usec, i);
}

void	print_died(struct timeval *tv, int i)
{
	gettimeofday(tv, 0);
	printf("%d %d died\n", tv->tv_usec, i);
}
