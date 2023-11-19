/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:33:00 by hshimizu          #+#    #+#             */
/*   Updated: 2023/11/19 09:12:51 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>

typedef struct s_table	t_table;

# ifndef COLOR_MSG
#  define MSG_TAKEN_FORK "has taken a fork"
#  define MSG_EATING "is eating"
#  define MSG_SLEEPING "is sleeping"
#  define MSG_THINKING "is thinking"
#  define MSG_DIED "died"
# else
#  define MSG_TAKEN_FORK "has taken a fork"
#  define MSG_EATING "\e[38;2;0;255;0mis eating\e[0m"
#  define MSG_SLEEPING "\e[38;2;0;0;255mis sleeping\e[0m"
#  define MSG_THINKING "is thinking"
#  define MSG_DIED "\e[38;2;255;0;0mdied\e[0m"
# endif

typedef struct s_philo
{
	pthread_mutex_t		*_lock;
	t_table				*_table;
	int					active;
	pthread_t			*_thread;
	int					_nbr;
	long				last_ate_time;
	size_t				count_to_eat;
	unsigned int		_is_using_fork;
	pthread_mutex_t		*_left_fork;
	pthread_mutex_t		*_right_fork;
}						t_philo;

typedef struct s_philo_args
{
	int					nbr;
	t_table				*table;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
}						t_philo_args;

//	0
int						philo__init(t_philo *self, t_philo_args *args);
int						philo__del(t_philo *self);

//	1
int						philo__start(t_philo *self);
int						philo__wait(t_philo *self);
int						philo__stop(t_philo *self);
void					*philo__routine(t_philo *self);

//	2
int						philo__put_msg(t_philo *self, char *msg, int enforce);
int						philo__get_active(t_philo *self);

//	3
int						philo__take_fork(t_philo *self);
int						philo__put_fork(t_philo *self);
int						philo__do_to_eat(t_philo *self);
int						philo__do_to_sleep(t_philo *self);
int						philo__do_to_think(t_philo *self);

//	4
int						philo__take_left_fork(t_philo *self);
int						philo__put_left_fork(t_philo *self);
int						philo__take_right_fork(t_philo *self);
int						philo__put_right_fork(t_philo *self);

#endif