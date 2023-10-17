/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 01:56:42 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/17 09:57:10 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "table.h"
#include <stdio.h>

int	table__run(t_table *self)
{
	if (table__start(self))
		return (-1);
	table__wait(self);
	return (0);
}

int	table__start(t_table *self)
{
	size_t	i;

	pthread_mutex_lock(self->lock);
	i = 0;
	while (1)
	{
		while (i < self->len)
		{
			if (philo__start(self->philos[i]))
				break ;
			i++;
		}
		self->is_running = 1;
		pthread_mutex_unlock(self->lock);
		return (0);
	}
	pthread_mutex_unlock(self->lock);
	table__stop(self);
	return (-1);
}

int	table__wait(t_table *self)
{
	size_t	i;

	i = 0;
	while (i < self->len)
		philo__wait(self->philos[i++]);
	return (0);
}

int	table__stop(t_table *self)
{
	size_t	i;

	i = 0;
	pthread_mutex_lock(self->lock);
	while (i < self->len)
		philo__stop(self->philos[i++]);
	self->is_running = 0;
	pthread_mutex_unlock(self->lock);
	return (0);
}
