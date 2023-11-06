/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 01:56:42 by hshimizu          #+#    #+#             */
/*   Updated: 2023/11/06 22:39:30 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "table.h"
#include "utils.h"
#include <stdlib.h>

static t_philo	**create_philos(t_table *self);

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
	self->_len = args->len;
	self->_time_to_die = args->time_to_die;
	self->_time_to_eat = args->time_to_eat;
	self->_time_to_sleep = args->time_to_sleep;
	self->_must_eat = args->must_eat;
	self->_lock_printf = args->lock_printf;
	if (self->_len % 2)
		self->_snooze = self->_time_to_eat / (self->_len / 2);
	self->_lock = mutex_new();
	if (!self->_lock)
		return (-1);
	self->_forks = malloc(sizeof(*self->_forks) * self->_len);
	if (!self->_forks)
		return (-1);
	while (self->__forks_len < self->_len)
		if (pthread_mutex_init(&self->_forks[self->__forks_len++], NULL))
			return (-1);
	self->_philos = create_philos(self);
	if (!self->_philos)
		return (-1);
	return (0);
}

int	table__del(t_table **self_ptr)
{
	t_table	*self;

	self = *self_ptr;
	while (self->_philos && self->_len--)
		philo__del(&self->_philos[self->_len]);
	free(self->_philos);
	while (self->__forks_len--)
		pthread_mutex_destroy(&self->_forks[self->__forks_len]);
	free(self->_forks);
	mutex_del(self->_lock);
	free(self);
	*self_ptr = NULL;
	return (0);
}

static t_philo	**create_philos(t_table *self)
{
	t_philo_args	args;
	t_philo			**philos;
	size_t			i;

	philos = malloc(sizeof(t_philo *[self->_len]));
	if (!philos)
		return (NULL);
	args.table = self;
	i = 0;
	while (i < self->_len)
	{
		args.nbr = i + 1;
		args.left_fork = &self->_forks[i];
		args.right_fork = &self->_forks[(i + self->_len + 1) % self->_len];
		philos[i] = philo__new(&args);
		if (!philos[i])
		{
			while (--i)
				free(philos[i]);
			free(philos);
			return (NULL);
		}
		i++;
	}
	return (philos);
}
