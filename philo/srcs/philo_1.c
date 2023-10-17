/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 23:29:05 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/17 09:50:12 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	philo__run(t_philo *self)
{
	if (philo__start(self))
		return (-1);
	philo__wait(self);
	return (0);
}

static void	*routine(void *args)
{
	philo__life((t_philo *)args);
	return (NULL);
}

int	philo__start(t_philo *self)
{
	pthread_mutex_lock(self->lock);
	while (1)
	{
		if (pthread_create(&self->thread, NULL, routine, self))
			break ;
		self->is_active = 1;
		pthread_mutex_unlock(self->lock);
		return (0);
	}
	pthread_mutex_unlock(self->lock);
	return (-1);
}

int	philo__wait(t_philo *self)
{
	pthread_join(self->thread, NULL);
	return (0);
}

int	philo__stop(t_philo *self)
{
	pthread_mutex_lock(self->lock);
	self->is_active = 0;
	pthread_mutex_unlock(self->lock);
	return (0);
}
