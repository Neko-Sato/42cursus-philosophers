/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 23:29:05 by hshimizu          #+#    #+#             */
/*   Updated: 2023/11/21 09:25:23 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "table.h"
#include "utils.h"
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static int	init(t_philo *self, t_philo_args *args);
static int	del(t_philo *self);

int	philo__init(t_philo *self, t_philo_args *args)
{
	int	result;

	result = init(self, args);
	if (result)
		del(self);
	return (result);
}

int	philo__del(t_philo *self)
{
	return (del(self));
}

static int	init(t_philo *self, t_philo_args *args)
{
	memset(self, 0, sizeof(*self));
	self->nbr = args->nbr;
	self->table = args->table;
	self->lock = sem_new(1);
	if (!self->lock)
		return (-1);
	return (0);
}

static int	del(t_philo *self)
{
	sem_close(self->lock);
	return (0);
}
