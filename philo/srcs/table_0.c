/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 01:56:42 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/17 07:35:12 by hshimizu         ###   ########.fr       */
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
	int	ret;

	self->lock = mutex_new();
	if (!self->lock)
		return (ret);
	self->len = args->len;
	self->forks = malloc(sizeof(*self->forks) * self->len);
	if (!self->forks)
		return (-1);
	while (self->__forks_len < self->len)
		if (pthread_mutex_init(&self->forks[self->__forks_len++], NULL))
			return (-1);
	self->philos = args->philos;
	table__seat_philo(self);
	return (0);
}

int	table__del(t_table **self_ptr)
{
	t_table	*self;

	self = *self_ptr;
	table__leave_philo(self);
	self->philos = NULL;
	while (self->__forks_len--)
		pthread_mutex_destroy(&self->forks[self->__forks_len]);
	free(self->forks);
	mutex_del(self->lock);
	free(self);
	*self_ptr = NULL;
	return (0);
}

int	table__seat_philo(t_table *self)
{
	size_t	i;

	i = 0;
	while (i < self->len)
	{
		self->philos[i]->table = self;
		self->philos[i]->left_fork = &self->forks[i % self->len];
		self->philos[i]->right_fork = &self->forks[(i + 1) % self->len];
		i++;
	}
	return (0);
}

int	table__leave_philo(t_table *self)
{
	size_t	i;

	i = 0;
	while (i < self->len)
	{
		self->philos[i]->table = NULL;
		self->philos[i]->left_fork = NULL;
		self->philos[i]->right_fork = NULL;
		i++;
	}
	return (0);
}
