/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 23:29:05 by hshimizu          #+#    #+#             */
/*   Updated: 2023/11/07 03:09:16 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "table.h"
#include "utils.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	philo__take_fork(t_philo *self)
{
	int	(*actions[2])(t_philo *);

	actions[0] = philo__take_left_fork;
	actions[1] = philo__take_right_fork;
	if (actions[self->_nbr % 2 != 0](self))
		return (-1);
	if (actions[self->_nbr % 2 == 0](self))
		return (-1);
	return (0);
}

int	philo__put_fork(t_philo *self)
{
	philo__put_left_fork(self);
	philo__put_right_fork(self);
	return (0);
}

int	philo__do_to_eat(t_philo *self)
{
	int	stop;

	if (philo__take_fork(self))
		return (-1);
	pthread_mutex_lock(self->_table->_lock);
	pthread_mutex_lock(self->_lock);
	self->last_ate_time = table__get_time(self->_table);
	self->count_to_eat++;
	pthread_mutex_unlock(self->_lock);
	pthread_mutex_unlock(self->_table->_lock);
	stop = table__check_satisfied(self->_table);
	(void)(stop && table__stop(self->_table));
	philo__put_msg(self, MSG_EATING, stop);
	if (!philo__get_active(self))
		return (-1);
	msleep(self->_table->_time_to_eat);
	philo__put_fork(self);
	return (0);
}

int	philo__do_to_sleep(t_philo *self)
{
	if (!philo__get_active(self))
		return (-1);
	philo__put_msg(self, MSG_SLEEPING, 0);
	msleep(self->_table->_time_to_sleep);
	return (0);
}

int	philo__do_to_think(t_philo *self)
{
	if (!philo__get_active(self))
		return (-1);
	philo__put_msg(self, MSG_THINKING, 0);
	return (0);
}
