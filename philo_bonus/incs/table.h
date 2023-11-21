/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:33:00 by hshimizu          #+#    #+#             */
/*   Updated: 2023/11/21 21:23:15 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_H
# define TABLE_H

# include <semaphore.h>
# include <sys/time.h>

typedef struct s_philo	t_philo;

typedef struct s_table
{
	sem_t				*lock_printf;
	sem_t				*stop;
	sem_t				*satisfied;
	pid_t				*process;
	struct timeval		start_time;
	size_t				len;
	sem_t				*forks;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	size_t				must_eat;
	double				snooze;
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
int						table__run(t_table *self);
int						table__wait(t_table *self);
int						table__stop(t_table *self);
int						table__check_satisfied(t_table *self);

//	2
long					table__get_time(t_table *self);
int						table__put_msg(t_table *self, int nbr, char *msg);

#endif
