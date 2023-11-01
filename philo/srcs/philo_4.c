/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:13:35 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/31 20:03:56 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "table.h"
#include "utils.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	philo__take_left_fork(t_philo *self)
{
	if (~self->_is_using_fork & 0b10)
		pthread_mutex_lock(self->_left_fork);
	self->_is_using_fork |= 0b10;
	if (!philo__get_active(self))
		return (-1);
	philo__put_msg(self, MSG_TAKEN_FORK);
	return (0);
}

int	philo__put_left_fork(t_philo *self)
{
	if (self->_is_using_fork & 0b10)
		pthread_mutex_unlock(self->_left_fork);
	self->_is_using_fork &= ~0b10;
	return (0);
}

int	philo__take_right_fork(t_philo *self)
{
	if (~self->_is_using_fork & 0b01)
		pthread_mutex_lock(self->_right_fork);
	self->_is_using_fork |= 0b01;
	if (!philo__get_active(self))
		return (-1);
	philo__put_msg(self, MSG_TAKEN_FORK);
	return (0);
}

int	philo__put_right_fork(t_philo *self)
{
	if (self->_is_using_fork & 0b01)
		pthread_mutex_unlock(self->_right_fork);
	self->_is_using_fork &= ~0b01;
	return (0);
}
