/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:33:00 by hshimizu          #+#    #+#             */
/*   Updated: 2023/11/21 10:21:10 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <semaphore.h>
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
	sem_t				*lock;
	t_table				*table;
	pthread_t			*check_died;
	int					nbr;
	long				last_ate_time;
	size_t				count_to_eat;
	unsigned int		is_using_fork;
}						t_philo;

typedef struct s_philo_args
{
	int					nbr;
	t_table				*table;
}						t_philo_args;

//	0
int						philo__init(t_philo *self, t_philo_args *args);
int						philo__del(t_philo *self);

//	1
int						philo__run(t_philo *self);
void					*philo__check_died(t_philo *self);
int						philo__routine(t_philo *self);
int						philo__put_msg(t_philo *self, char *msg);

//	2
int						philo__do_to_eat(t_philo *self);
int						philo__do_to_sleep(t_philo *self);
int						philo__do_to_think(t_philo *self);

#endif