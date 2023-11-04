/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 01:56:42 by hshimizu          #+#    #+#             */
/*   Updated: 2023/11/04 18:13:46 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "philo_visualizer.h"
#include "table.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int	table__check_died(t_table *self)
{
	int		ret;
	t_philo	*philo;
	size_t	i;
	long	now;

	pthread_mutex_lock(self->_lock);
	now = table__get_time(self);
	pthread_mutex_unlock(self->_lock);
	ret = 0;
	i = 0;
	while (!ret && i < self->_len)
	{
		philo = self->_philos[i];
		pthread_mutex_lock(philo->_lock);
		ret |= (0 <= philo->last_ate_time && philo->last_ate_time
				+ philo->_time_to_die < now);
		pthread_mutex_unlock(philo->_lock);
		if (ret)
		{
			philovisualizer_send(philo->_nbr, PV_DIED);
			philo__put_msg(philo, MSG_DIED, 1);
		}
		i++;
	}
	return (ret);
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
		philo = self->_philos[i];
		pthread_mutex_lock(philo->_lock);
		ret &= (philo->_must_eat && philo->_must_eat <= philo->count_to_eat);
		pthread_mutex_unlock(philo->_lock);
		i++;
	}
	return (ret);
}
