/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 08:34:06 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/17 09:57:19 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	philo__life(t_philo *self)
{
	while (1)
	{
		pthread_mutex_lock(self->lock);
		if (!self->is_active)
			break ;
		pthread_mutex_unlock(self->lock);
		pthread_mutex_lock(self->lock_printf);
		printf("%d life%d\n", self->nbr, self->count_to_eat);
		pthread_mutex_unlock(self->lock_printf);
		usleep(1000000);
	}
	pthread_mutex_unlock(self->lock);
	return (0);
}