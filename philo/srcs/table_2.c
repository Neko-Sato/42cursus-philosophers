/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:02:23 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/17 10:37:04 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "table.h"
#include "utils.h"
#include <stdlib.h>
#include <sys/time.h>

long	table__get_time(t_table *self)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (-1);
	return (timeval2useconds(get_interval(time, self->start_time)));
}
