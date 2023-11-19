/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 23:29:05 by hshimizu          #+#    #+#             */
/*   Updated: 2023/11/19 10:06:29 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "table.h"
#include "utils.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	philo__start(t_philo *self)
{
	pthread_mutex_lock(self->_lock);
	while (1)
	{
		self->_thread = thread_start((void *)philo__routine, self);
		if (!self->_thread)
			break ;
		self->active = 1;
		pthread_mutex_unlock(self->_lock);
		return (0);
	}
	pthread_mutex_unlock(self->_lock);
	return (-1);
}

int	philo__wait(t_philo *self)
{
	thread_join(self->_thread, NULL);
	return (0);
}

int	philo__stop(t_philo *self)
{
	pthread_mutex_lock(self->_lock);
	self->active = 0;
	pthread_mutex_unlock(self->_lock);
	return (0);
}

void	*philo__routine(t_philo *self)
{
	if (self->_table->_snooze)
	{
		if (!philo__get_active(self))
			return (NULL);
		msleep(self->_table->_snooze
			* reverse_even_odd(self->_nbr - 1, self->_table->_len));
	}
	while (1)
	{
		if (philo__do_to_eat(self))
			break ;
		if (philo__do_to_sleep(self))
			break ;
		if (philo__do_to_think(self))
			break ;
	}
	philo__put_fork(self);
	return (NULL);
}
