/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 01:56:42 by hshimizu          #+#    #+#             */
/*   Updated: 2023/11/04 15:41:05 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "table.h"
#include "utils.h"
#include <stdio.h>

int	table__start(t_table *self)
{
	size_t	i;

	pthread_mutex_lock(self->_lock);
	i = 0;
	while (1)
	{
		while (i < self->_len)
			if (philo__start(self->_philos[i++]))
				break ;
		self->_thread = thread_start((void *)table__monitor, self);
		if (!self->_thread)
			break ;
		if (gettimeofday(&self->start_time, NULL))
			break ;
		self->is_running = 1;
		pthread_mutex_unlock(self->_lock);
		return (0);
	}
	pthread_mutex_unlock(self->_lock);
	table__stop(self);
	return (-1);
}

int	table__wait(t_table *self)
{
	size_t	i;

	thread_join(self->_thread, NULL);
	i = 0;
	while (i < self->_len)
		philo__wait(self->_philos[i++]);
	return (0);
}

int	table__stop(t_table *self)
{
	size_t	i;

	pthread_mutex_lock(self->_lock);
	self->is_running = 0;
	pthread_mutex_unlock(self->_lock);
	i = 0;
	while (i < self->_len)
		philo__stop(self->_philos[i++]);
	return (0);
}

void	*table__monitor(t_table *self)
{
	int	is_running;

	while (1)
	{
		pthread_mutex_lock(self->_lock);
		is_running = self->is_running;
		pthread_mutex_unlock(self->_lock);
		if (!is_running)
			break ;
		if (table__check_died(self))
			table__stop(self);
	}
	return (NULL);
}

long	table__get_time(t_table *self)
{
	long			time;
	struct timeval	now;

	gettimeofday(&now, NULL);
	time = timeval2useconds(interval(now, self->start_time));
	return (time);
}
