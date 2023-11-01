/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 01:56:42 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/31 20:14:07 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "table.h"
#include "utils.h"
#include <stdlib.h>

t_table	*table__new(t_table_args *args)
{
	t_table	*self;

	self = malloc(sizeof(*self));
	if (self)
	{
		*self = (t_table){0};
		if (table__int(self, args))
			table__del(&self);
	}
	return (self);
}

int	table__int(t_table *self, t_table_args *args)
{
	self->_lock = mutex_new();
	if (!self->_lock)
		return (-1);
	self->_len = args->len;
	self->_forks = malloc(sizeof(*self->_forks) * self->_len);
	if (!self->_forks)
		return (-1);
	while (self->__forks_len < self->_len)
		if (pthread_mutex_init(&self->_forks[self->__forks_len++], NULL))
			return (-1);
	self->_philos = args->philos;
	table__seat_philo(self);
	return (0);
}

int	table__del(t_table **self_ptr)
{
	t_table	*self;

	self = *self_ptr;
	table__leave_philo(self);
	self->_philos = NULL;
	while (self->__forks_len--)
		pthread_mutex_destroy(&self->_forks[self->__forks_len]);
	free(self->_forks);
	mutex_del(self->_lock);
	free(self);
	*self_ptr = NULL;
	return (0);
}

int	table__seat_philo(t_table *self)
{
	size_t	i;

	i = 0;
	while (i < self->_len)
	{
		self->_philos[i]->_table = self;
		self->_philos[i]->_nbr = i + 1;
		self->_philos[i]->_left_fork = &self->_forks[i % self->_len];
		self->_philos[i]->_right_fork = &self->_forks[(self->_len + i - 1)
			% self->_len];
		i++;
	}
	return (0);
}

int	table__leave_philo(t_table *self)
{
	size_t	i;

	i = 0;
	while (i < self->_len)
	{
		self->_philos[i]->_nbr = -1;
		self->_philos[i]->_table = NULL;
		self->_philos[i]->_left_fork = NULL;
		self->_philos[i]->_right_fork = NULL;
		i++;
	}
	return (0);
}
