/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 23:29:05 by hshimizu          #+#    #+#             */
/*   Updated: 2023/11/06 02:02:15 by hshimizu         ###   ########.fr       */
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
	self->_lock = mutex_new();
	if (!self->_lock)
		return (-1);
	self->_lock_printf = args->lock_printf;
	self->_nbr = -1;
	self->_time_to_die = args->time_to_die;
	self->_time_to_eat = args->time_to_eat;
	self->_time_to_sleep = args->time_to_sleep;
	self->_must_eat = args->must_eat;
	self->_snooze = (self->_time_to_die - (self->_time_to_eat
				+ self->_time_to_sleep)) / 2;
	if (self->_snooze < 0)
		self->_snooze = 0;
	return (0);
}

int	philo__del(t_philo **self_ptr)
{
	mutex_del((*self_ptr)->_lock);
	free(*self_ptr);
	*self_ptr = NULL;
	return (0);
}
