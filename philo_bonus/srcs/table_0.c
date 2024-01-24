/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 01:56:42 by hshimizu          #+#    #+#             */
/*   Updated: 2024/01/24 16:00:55 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "table.h"
#include "utils.h"
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

static int	init(t_table *self, t_table_args *args);
static int	del(t_table *self);

int	table__init(t_table *self, t_table_args *args)
{
	int	result;

	result = init(self, args);
	if (result)
		del(self);
	return (result);
}

int	table__del(t_table *self)
{
	return (del(self));
}

static int	init(t_table *self, t_table_args *args)
{
	memset(self, 0, sizeof(*self));
	self->len = args->len;
	self->time_to_die = args->time_to_die;
	self->time_to_eat = args->time_to_eat;
	self->time_to_sleep = args->time_to_sleep;
	self->must_eat = args->must_eat;
	self->snooze = self->time_to_eat / (double)(self->len / 2);
	self->lock_printf = sem_new(1);
	if (!self->lock_printf)
		return (-1);
	self->stop = sem_new(1);
	if (!self->stop)
		return (-1);
	self->forks = sem_new(self->len);
	if (!self->forks)
		return (-1);
	self->process = malloc(sizeof(pid_t[self->len]));
	if (!self->process)
		return (-1);
	memset(self->process, -1, sizeof(pid_t[self->len]));
	return (0);
}

static int	del(t_table *self)
{
	free(self->process);
	sem_close(self->forks);
	sem_close(self->stop);
	sem_close(self->lock_printf);
	return (0);
}
