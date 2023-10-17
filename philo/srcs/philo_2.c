/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 08:34:06 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/17 12:07:44 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "table.h"
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
		philo__do_to_sleep(self);
		pthread_mutex_lock(self->lock);
		if (!self->is_active)
			break ;
		pthread_mutex_unlock(self->lock);
		philo__do_to_think(self);
	}
	pthread_mutex_unlock(self->lock);
	return (0);
}


// check_died