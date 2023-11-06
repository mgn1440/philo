/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:25:36 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/11/06 21:05:58 by yeonwkan         ###   ########.fr       */
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

typedef struct s_data
{
	t_arg			arg;
	struct timeval	tv;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print_lock;
	int				start_time;
	int				now_time;
	int				is_death;
	int				eat_done;
}	t_data;

typedef struct s_philo
{
	pthread_t		thread;
	int				idx;
	int				left_eat;
	int				last_eat;
	t_data			*data;
}	t_philo;

//-------------------main-----------------------
void	data_init(t_data *data, char **argv, t_philo **philo, int argc);

//-------------------error-----------------------
int		arg_error(void);

//-------------------utils-----------------------
int		ft_atoi(const char *str);

//-------------------arg_utils-----------------------
void	arg_init(t_arg *arg, char **argv);

//-------------------mutex_utils-----------------------
void	mutex_init(pthread_mutex_t **fork, t_arg *arg);

//-------------------mutex_utils-----------------------
void	print_take_fork(t_data *data, int i);
void	print_eat(t_data *data, int i);
void	print_sleep(t_data *data, int i);
void	print_think(t_data *data, int i);
void	print_died(t_data *data, int i);

//-------------------philo----------------------------
void	start_philo(t_philo *philo);
void	*run_philo(void *philo);
void	join_all_thread(t_philo *philo);
void	get_sleep(t_data *data, int time);

//------------------get_time----------------------------
void	get_time(t_data *data);

//-----------------------fork---------------------------
void	take_fork(t_philo *p);
void	drop_fork(t_philo *p);

//-----------------------fork---------------------------
int		check_death(t_data *data, t_philo *philo);

#endif