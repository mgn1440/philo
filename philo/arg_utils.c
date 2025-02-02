/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:49:50 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/11/06 18:32:49 by yeonwkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	arg_init(t_arg *arg, char **argv)
{
	arg->num = ft_atoi(argv[1]);
	arg->to_die = ft_atoi(argv[2]);
	arg->to_eat = ft_atoi(argv[3]);
	arg->to_sleep = ft_atoi(argv[4]);
	arg->num_of_eat = ft_atoi(argv[5]);
}
