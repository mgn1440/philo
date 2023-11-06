/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:13:46 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/11/06 23:36:09 by yeonwkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *p)
{
	if (p->idx % 2)
	{
		usleep(100);
		pthread_mutex_lock(&p->data->fork[(p->idx + 1) % p->data->arg.num]);
		print_take_fork(p->data, p->idx);
		pthread_mutex_lock(&p->data->fork[p->idx]);
		print_take_fork(p->data, p->idx);
	}
	else
	{
		pthread_mutex_lock(&p->data->fork[p->idx]);
		print_take_fork(p->data, p->idx);
		pthread_mutex_lock(&p->data->fork[(p->idx + 1) % p->data->arg.num]);
		print_take_fork(p->data, p->idx);
	}
}

void	drop_fork(t_philo *p)
{
	if (p->idx % 2)
	{
		pthread_mutex_unlock(&p->data->fork[p->idx]);
		pthread_mutex_unlock(&p->data->fork[(p->idx + 1) % p->data->arg.num]);
	}
	else
	{
		pthread_mutex_unlock(&p->data->fork[(p->idx + 1) % p->data->arg.num]);
		pthread_mutex_unlock(&p->data->fork[p->idx]);
	}
}
