/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:13:46 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/12/02 03:37:47 by yeonwkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_fork(t_philo *p)
{
	int	left;
	int	right;

	right = ((p->idx + 1) % p->data->arg.num);
	left = p->idx;
	if (p->idx % 2)
		return (take_fork_odd(p, left, right));
	else
		return (take_fork_even(p, left, right));
}

int	take_fork_odd(t_philo *p, int left, int right)
{
	pthread_mutex_lock(&p->data->fork_mutex[right]);
	if (!p->data->fork[right])
	{
		pthread_mutex_unlock(&p->data->fork_mutex[right]);
		return (0);
	}
	p->data->fork[right] = 0;
	print_take_fork(p->data, p->idx);
	pthread_mutex_lock(&p->data->fork_mutex[left]);
	if (!p->data->fork[left])
	{
		pthread_mutex_unlock(&p->data->fork_mutex[left]);
		return (0);
	}
	p->data->fork[left] = 0;
	print_take_fork(p->data, p->idx);
	return (1);
}

int	take_fork_even(t_philo *p, int left, int right)
{
	pthread_mutex_lock(&p->data->fork_mutex[left]);
	if (!p->data->fork[left])
	{
		pthread_mutex_unlock(&p->data->fork_mutex[left]);
		return (0);
	}
	p->data->fork[left] = 0;
	print_take_fork(p->data, p->idx);
	pthread_mutex_lock(&p->data->fork_mutex[right]);
	if (!p->data->fork[right])
	{
		pthread_mutex_unlock(&p->data->fork_mutex[right]);
		return (0);
	}
	p->data->fork[right] = 0;
	print_take_fork(p->data, p->idx);
	return (1);
}

int	drop_fork(t_philo *p)
{
	int	left;
	int	right;

	right = ((p->idx + 1) % p->data->arg.num);
	left = p->idx;
	if (p->idx % 2)
	{
		p->data->fork[left] = 1;
		pthread_mutex_unlock(&p->data->fork_mutex[left]);
		p->data->fork[right] = 1;
		pthread_mutex_unlock(&p->data->fork_mutex[right]);
	}
	else
	{
		p->data->fork[right] = 1;
		pthread_mutex_unlock(&p->data->fork_mutex[right]);
		p->data->fork[left] = 1;
		pthread_mutex_unlock(&p->data->fork_mutex[left]);
	}
	return (0);
}
