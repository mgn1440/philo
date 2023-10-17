/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:25:36 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/10/17 20:38:24 by yeonwkan         ###   ########.fr       */
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

typedef struct s_philo
{
	pthread_t		thread;
	int				idx;
	int				left_eat;
	int				last_eat;
	pthread_mutex_t	**fork;
	pthread_mutex_t	*print_lock;
	t_arg			*arg;
}	t_philo;

typedef struct s_data
{
	t_arg			arg;
	struct timeval	tv;
	t_philo			*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print_lock;
}	t_data;


//-------------------main-----------------------
void	data_init(t_data *data, char **argv);

//-------------------error-----------------------
int		arg_error(void);

//-------------------utils-----------------------
int		ft_atoi(const char *str);

//-------------------arg_utils-----------------------
void	arg_init(t_arg *arg, char **argv);

//-------------------mutex_utils-----------------------
void	mutex_init(pthread_mutex_t *fork, t_arg *arg);

//-------------------mutex_utils-----------------------
void	print_take_fork(struct timeval *tv, int i);
void	print_eat(struct timeval *tv, int i);
void	print_sleep(struct timeval *tv, int i);
void	print_think(struct timeval *tv, int i);
void	print_died(struct timeval *tv, int i);

//-------------------philo----------------------------
void	start_philo(t_data *data);
void	*run_philo(void *philo);


#endif