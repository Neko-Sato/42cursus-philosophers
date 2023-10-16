/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:33:00 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/16 17:56:58 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_LIFE_H
# define PHILO_LIFE_H

# include <pthread.h>
# include <sys/time.h>

typedef struct s_table t_table;

# define MASAGE_TAKEN_FORK "%ld %d has taken a fork\n"
# define MASAGE_EATING "%ld %d is eating\n"
# define MASAGE_SLEEPING "%ld %d is sleeping\n"
# define MASAGE_THINKING "%ld %d thinking\n"
# define MASAGE_DIED "%ld %d died\n"

typedef enum e_philo_state
{
	none,
	has_taken_fork,
	thinking,
	eating,
	sleeping,
	died,
}					t_philo_state;

typedef struct s_philo
{
	pthread_mutex_t	*lock;
	t_table			*table;
	pthread_t		thread;
	int				nbr;
	long			last_ate_time;
	int				count_to_eat;
	unsigned int	is_using_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
}					t_philo;

typedef struct s_philo_args
{
	int				nbr;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
}					t_philo_args;

t_philo				*philo__new(t_philo_args *args);
int					philo__del(t_philo **self_ptr);
int					philo__init(t_philo *self, t_philo_args *args);

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