/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 21:24:13 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/11/06 21:27:33 by yeonwkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	data_free(t_data *data, t_philo *philo)
{
	mutex_destroy(&data->fork, &data->arg);
	pthread_mutex_destroy(&data->print_lock);
	free(philo);
}
