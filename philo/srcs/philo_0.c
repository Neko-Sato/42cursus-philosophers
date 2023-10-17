/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 23:29:05 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/17 10:00:45 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

t_philo	*philo__new(t_philo_args *args)
{
	t_philo	*self;

	self = malloc(sizeof(*self));
	if (self)
	{
		*self = (t_philo){0};
		if (philo__init(self, args))
			philo__del(&self);
	}
	return (self);
}

int	philo__init(t_philo *self, t_philo_args *args)
{
	self->lock = mutex_new();
	if (!self->lock)
		return (-1);
	self->lock_printf = args->lock_printf;
	self->nbr = args->nbr;
	self->time_to_die = args->time_to_die;
	self->time_to_eat = args->time_to_eat;
	self->time_to_sleep = args->time_to_sleep;
	self->must_eat = args->must_eat;
	return (0);
}

int	philo__del(t_philo **self_ptr)
{
	mutex_del((*self_ptr)->lock);
	free(*self_ptr);
	*self_ptr = NULL;
	return (0);
}
