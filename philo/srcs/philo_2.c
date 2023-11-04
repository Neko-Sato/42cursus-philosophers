/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 23:29:05 by hshimizu          #+#    #+#             */
/*   Updated: 2023/11/04 15:08:08 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "table.h"
#include "utils.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	philo__put_msg(t_philo *self, char *msg, int enforce)
{
	pthread_mutex_lock(self->_table->_lock);
	pthread_mutex_lock(self->_lock_printf);
	if (enforce || self->_table->is_running)
		printf("%ld %d %s\n", table__get_time(self->_table), self->_nbr, msg);
	pthread_mutex_unlock(self->_lock_printf);
	pthread_mutex_unlock(self->_table->_lock);
	return (0);
}

int	philo__get_active(t_philo *self)
{
	int	active;

	pthread_mutex_lock(self->_lock);
	active = self->active;
	pthread_mutex_unlock(self->_lock);
	return (active);
}
