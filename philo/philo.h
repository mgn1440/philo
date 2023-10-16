/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:25:36 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/10/16 20:48:35 by yeonwkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_arg
{
	int	num;
	int	to_die;
	int	to_eat;
	int	to_sleep;
	int	num_of_eat;
}	t_arg;

//-------------------main-----------------------

//-------------------error-----------------------
int	arg_error(void);


#endif