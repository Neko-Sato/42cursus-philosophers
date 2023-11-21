/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 23:29:05 by hshimizu          #+#    #+#             */
/*   Updated: 2023/11/21 23:43:25 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "table.h"
#include "utils.h"
#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int	philo__run(t_philo *self)
{
	if (pthread_create(&self->check_died, NULL, (void *)philo__check_died,
			self))
		return (-1);
	pthread_detach(self->check_died);
	philo__routine(self);
	return (0);
}

void	*philo__check_died(t_philo *self)
{
	while (1)
	{
		sem_wait(self->lock);
		if (0 <= self->last_ate_time && self->last_ate_time
			+ self->table->time_to_die < table__get_time(self->table))
			break ;
		sem_post(self->lock);
	}
	sem_wait(self->table->stop);
	philo__put_msg(self, MSG_DIED);
	exit(0);
	return (NULL);
}

int	philo__routine(t_philo *self)
{
	if (self->table->len % 2)
		msleep(self->table->snooze * (self->nbr - 1));
	else if (self->table->len / 2 < (size_t)(self->nbr - 1))
		msleep(self->table->snooze);
	while (1)
	{
		philo__do_to_eat(self);
		philo__do_to_sleep(self);
		philo__do_to_think(self);
		if (self->table->len % 2)
			msleep(self->table->snooze);
	}
	return (0);
}

int	philo__put_msg(t_philo *self, char *msg)
{
	return (table__put_msg(self->table, self->nbr, msg));
}
