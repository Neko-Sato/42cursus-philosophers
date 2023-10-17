/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:33:00 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/17 10:11:55 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_H
# define TABLE_H

# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo	t_philo;

typedef struct s_table
{
	pthread_mutex_t		*lock;
	int					is_running;
	struct timeval		start_time;
	size_t				len;
	size_t				__forks_len;
	pthread_mutex_t		*forks;
	t_philo				**philos;
}						t_table;

typedef struct s_table_args
{
	size_t				len;
	t_philo				**philos;
}						t_table_args;

t_table					*table__new(t_table_args *args);
int						table__int(t_table *self, t_table_args *args);
int						table__del(t_table **self_ptr);
int						table__seat_philo(t_table *self);
int						table__leave_philo(t_table *self);

int						table__run(t_table *self);
int						table__start(t_table *self);
int						table__wait(t_table *self);
int						table__stop(t_table *self);

long					table__get_time(t_table *self);
// t_table					*table__new(t_table_args *args);
// void					table__del(t_table **self_ptr);

// get_time
/*
	is_runningの時
	start_timeが0だった時
		時間をセットして0を返す
	そうじゃなかった場合
		現在との差分を返す
*/
// run
/*
	is_runningを1にして
	フィロたちを稼働させる
*/
// stop
/*
	is_runningを0にして
	終了するのを待つ
*/

// check_died
/*
	どれか哲学者が死んでいるか確認して
	出力する
	stopを実行する
*/

#endif
