/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 01:56:42 by hshimizu          #+#    #+#             */
/*   Updated: 2023/11/21 23:20:41 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table.h"
#include "utils.h"
#include <semaphore.h>
#include <stdio.h>
#include <sys/time.h>

long	table__get_time(t_table *self)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (timeval2useconds(interval(now, self->start_time)));
}

int	table__put_msg(t_table *self, int nbr, char *msg)
{
	sem_wait(self->lock_printf);
	printf("%ld %d %s\n", table__get_time(self), nbr, msg);
	sem_post(self->lock_printf);
	return (0);
}
