/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 23:29:05 by hshimizu          #+#    #+#             */
/*   Updated: 2023/11/06 18:20:00 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "table.h"
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
	self->_nbr = args->nbr;
	self->_table = args->table;
	self->_left_fork = args->left_fork;
	self->_right_fork = args->right_fork;
	self->_lock = mutex_new();
	if (!self->_lock)
		return (-1);
	return (0);
}

int	philo__del(t_philo **self_ptr)
{
	mutex_del((*self_ptr)->_lock);
	free(*self_ptr);
	*self_ptr = NULL;
	return (0);
}
