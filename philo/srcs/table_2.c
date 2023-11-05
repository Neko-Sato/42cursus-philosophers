/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 01:56:42 by hshimizu          #+#    #+#             */
/*   Updated: 2023/11/06 02:11:10 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "table.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

long	table__get_time(t_table *self)
{
	long			time;
	struct timeval	now;

	gettimeofday(&now, NULL);
	time = timeval2useconds(interval(now, self->start_time));
	return (time);
}

int	table__check_died(t_table *self)
{
	int		isdied;
	t_philo	*philo;
	size_t	i;

	i = 0;
	while (i < self->_len)
	{
		philo = self->_philos[i++];
		pthread_mutex_lock(self->_lock);
		pthread_mutex_lock(philo->_lock);
		isdied = (0 <= philo->last_ate_time && philo->last_ate_time
				+ philo->_time_to_die < table__get_time(self));
		pthread_mutex_unlock(philo->_lock);
		pthread_mutex_unlock(self->_lock);
		if (isdied)
			return (philo->_nbr);
	}
	return (0);
}

int	table__check_satisfied(t_table *self)
{
	int		ret;
	t_philo	*philo;
	size_t	i;

	ret = 1;
	i = 0;
	while (ret && i < self->_len)
	{
		philo = self->_philos[i++];
		pthread_mutex_lock(philo->_lock);
		ret &= (philo->_must_eat && philo->_must_eat <= philo->count_to_eat);
		pthread_mutex_unlock(philo->_lock);
	}
	return (ret);
}
