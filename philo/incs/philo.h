/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:33:00 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/17 11:19:28 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>

typedef struct s_table	t_table;

# define MASG_TAKEN_FORK "%8ld %d has taken a fork\n"
# define MASG_EATING "%8ld %d is eating\n"
# define MASG_SLEEPING "%8ld %d is sleeping\n"
# define MASG_THINKING "%8ld %d thinking\n"
# define MASG_DIED "%8ld %d died\n"

typedef enum e_philo_state
{
	none,
	has_taken_fork,
	thinking,
	eating,
	sleeping,
	died,
}						t_philo_state;

typedef struct s_philo
{
	pthread_mutex_t		*lock;
	pthread_mutex_t		*lock_printf;
	t_table				*table;
	int					is_active;
	pthread_t			thread;
	int					nbr;
	long				last_ate_time;
	int					count_to_eat;
	unsigned int		is_using_fork;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					must_eat;
}						t_philo;

typedef struct s_philo_args
{
	pthread_mutex_t		*lock_printf;
	int					nbr;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					must_eat;
}						t_philo_args;

t_philo					*philo__new(t_philo_args *args);
int						philo__init(t_philo *self, t_philo_args *args);
int						philo__del(t_philo **self_ptr);

int						philo__run(t_philo *self);
int						philo__start(t_philo *self);
int						philo__wait(t_philo *self);
int						philo__stop(t_philo *self);

int						philo__life(t_philo *self);

// int						philo__do_to_eat(t_philo *self);
int						philo__do_to_sleep(t_philo *self);
int						philo__do_to_think(t_philo *self);

// seat
// テーブルやフォークの情報をセットする
//leave
//	テーブルやフォークの情報をアンセットする
// life
/*
	to_think
	to_eat
	to_sleep
	をひたすら繰り返す
*/
// put_msg
// to_eat
// to_sleep
// to_think
// take_fork
// put_fork
// take_left_fork
// take_right_fork
// put_left_fork
// put_right_fork
#endif