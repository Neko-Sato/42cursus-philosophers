/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 01:56:42 by hshimizu          #+#    #+#             */
/*   Updated: 2023/11/19 09:37:12 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "table.h"
#include "utils.h"
#include <stddef.h>
#include <stdio.h>

int	table__start(t_table *self)
{
	size_t	i;

	pthread_mutex_lock(self->_lock);
	while (1)
	{
		self->_thread = thread_start((void *)table__monitor, self);
		if (!self->_thread)
			break ;
		i = 0;
		while (i < self->_len)
			if (philo__start(&self->_philos[even_odd(i++, self->_len)]))
				break ;
		if (i < self->_len)
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
		philo__wait(&self->_philos[i++]);
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
		philo__stop(&self->_philos[i++]);
	return (0);
}

void	*table__monitor(t_table *self)
{
	int	temp;

	while (1)
	{
		pthread_mutex_lock(self->_lock);
		temp = self->is_running;
		pthread_mutex_unlock(self->_lock);
		if (!temp)
			break ;
		temp = table__check_died(self);
		if (temp)
		{
			table__stop(self);
			philo__put_msg(&self->_philos[temp - 1], MSG_DIED, 1);
			break ;
		}
	}
	return (NULL);
}
