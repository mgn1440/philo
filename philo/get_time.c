/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:07:31 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/11/09 04:44:14 by yeonwkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_time(t_data *data)
{
	gettimeofday(&data->tv, 0);
	return (data->tv.tv_sec * 1000000 + data->tv.tv_usec) / 1000;
}
