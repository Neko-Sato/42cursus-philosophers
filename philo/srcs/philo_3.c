/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:43:35 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/17 12:06:57 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "table.h"
#include "utils.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// int	philo__do_to_eat(t_philo *self)
// {
// 	// pthread_mutex_lock(self->lock_printf);
// 	// printf(MASG_EATING, self->nbr, table__get_time(self->table));
// 	// pthread_mutex_unlock(self->lock_printf);
// 	return (0);
// }

int	philo__do_to_sleep(t_philo *self)
{
	pthread_mutex_lock(self->lock_printf);
	pthread_mutex_lock(self->table->lock);
	printf(MASG_SLEEPING, table__get_time(self->table), self->nbr);
	pthread_mutex_unlock(self->table->lock);
	pthread_mutex_unlock(self->lock_printf);
	if (usleep(self->time_to_sleep * 1000))
		return (-1);
	return (0);
}

int	philo__do_to_think(t_philo *self)
{
	pthread_mutex_lock(self->lock_printf);
	pthread_mutex_lock(self->table->lock);
	printf(MASG_THINKING, table__get_time(self->table), self->nbr);
	pthread_mutex_unlock(self->table->lock);
	pthread_mutex_unlock(self->lock_printf);
	return (0);
}
