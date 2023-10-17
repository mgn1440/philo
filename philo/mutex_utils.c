/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:16:56 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/10/17 16:43:16 by yeonwkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_init(pthread_mutex_t *fork, t_arg *arg)
{
	int	i;

	fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * (arg->num));
	i = 0;
	while (i < arg->num)
	{
		pthread_mutex_init(&fork[i], 0);
		i++;
	}
}
