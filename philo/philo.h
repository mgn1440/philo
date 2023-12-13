/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:25:36 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/12/02 03:23:52 by yeonwkan         ###   ########.fr       */
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
	int				*fork;
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	death_lock;
	pthread_mutex_t	left_eat_lock;
	pthread_mutex_t	same_start_lock;
	long long		start_time;
	long long		now_time;
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
void		data_init(t_data *data, char **argv, t_philo **philo, int argc);

//-------------------error-----------------------
int			arg_error(void);

//-------------------utils-----------------------
int			ft_atoi(const char *str);

//-------------------arg_utils-----------------------
void		arg_init(t_arg *arg, char **argv);

//-------------------mutex_utils-----------------------
void		mutex_init(pthread_mutex_t **fork, t_arg *arg);

//-------------------mutex_utils-----------------------
void		print_take_fork(t_data *data, int i);
void		print_eat(t_data *data, int i);
void		print_sleep(t_data *data, int i);
void		print_think(t_data *data, int i);
void		print_died(t_data *data, int i);

//-------------------philo----------------------------
void		start_philo(t_philo *philo);
void		*run_philo(void *philo);
int			philo_cycle(t_philo *p);

//-------------------philo_utils----------------------------
void		join_all_thread(t_philo *philo);
void		usleep_ph(t_data *data, int time);
int			check_death(t_philo *a);
void		reduce_left_eat(t_philo *p);
void		get_last_eat_time(t_philo *p);

//------------------get_time----------------------------
long long	get_time(t_data *data);

//-----------------------fork---------------------------
int			take_fork(t_philo *p);
int			take_fork_odd(t_philo *p, int left, int right);
int			take_fork_even(t_philo *p, int left, int right);
int			drop_fork(t_philo *p);

//-----------------------death---------------------------
int			death(t_data *data, t_philo *philo);
int			is_done(t_data *data, t_philo *philo, int *eat_done, int i);

//-----------------------abs---------------------------
int			abs(int a);

//-----------------------free---------------------------
void		data_free(t_data *data, t_philo **philo);
void		fork_destroy(pthread_mutex_t *fork, int num);

#endif
