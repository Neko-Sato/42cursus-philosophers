/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:46:58 by hshimizu          #+#    #+#             */
/*   Updated: 2024/01/24 15:24:42 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "table.h"
#include "utils.h"
#include <semaphore.h>

int	philo__take_fork(t_philo *self)
{
	int	i;

	i = 0;
	while (i++ < 2)
	{
		sem_wait(self->table->forks);
		sem_wait(self->table->stop);
		philo__put_msg(self, MSG_TAKEN_FORK);
		sem_post(self->table->stop);
	}
	return (0);
}

int	philo__put_fork(t_philo *self)
{
	int	i;

	i = 0;
	while (i++ < 2)
		sem_post(self->table->forks);
	return (0);
}

int	philo__do_to_eat(t_philo *self)
{
	philo__take_fork(self);
	sem_wait(self->lock);
	self->count_to_eat++;
	self->last_ate_time = table__get_time(self->table);
	sem_wait(self->table->stop);
	philo__put_msg(self, MSG_EATING);
	sem_post(self->table->stop);
	sem_post(self->lock);
	msleep(self->table->time_to_eat);
	philo__put_fork(self);
	return (0);
}

int	philo__do_to_sleep(t_philo *self)
{
	sem_wait(self->table->stop);
	philo__put_msg(self, MSG_SLEEPING);
	sem_post(self->table->stop);
	msleep(self->table->time_to_sleep);
	return (0);
}

int	philo__do_to_think(t_philo *self)
{
	sem_wait(self->table->stop);
	philo__put_msg(self, MSG_THINKING);
	sem_post(self->table->stop);
	return (0);
}
