/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:33:00 by hshimizu          #+#    #+#             */
/*   Updated: 2023/11/21 13:46:39 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_H
# define TABLE_H

# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo	t_philo;

typedef struct s_table
{
	pthread_mutex_t		*_lock;
	pthread_mutex_t		*_lock_printf;
	int					is_running;
	pthread_t			*_thread;
	struct timeval		start_time;
	size_t				_len;
	size_t				__forks_len;
	pthread_mutex_t		*_forks;
	t_philo				*_philos;
	long				_time_to_die;
	long				_time_to_eat;
	long				_time_to_sleep;
	size_t				_must_eat;
	long				_snooze;
}						t_table;

typedef struct s_table_args
{
	size_t				len;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	size_t				must_eat;
}						t_table_args;

//	0
int						table__init(t_table *self, t_table_args *args);
int						table__del(t_table *self);

//	1
int						table__start(t_table *self);
int						table__wait(t_table *self);
int						table__stop(t_table *self);
void					*table__monitor(t_table *self);

//	2
int						table__put_msg(t_table *self, int nbr, char *msg,
							int enforce);
long					table__get_time(t_table *self);
int						table__check_died(t_table *self);
int						table__check_satisfied(t_table *self);

#endif
