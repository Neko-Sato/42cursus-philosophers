/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 01:56:42 by hshimizu          #+#    #+#             */
/*   Updated: 2024/01/24 16:58:28 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "table.h"
#include "utils.h"
#include <semaphore.h>
#include <signal.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>

static int	run_philos(t_table *self);

int	table__run(t_table *self)
{
	int	status;

	status = -1;
	while (1)
	{
		gettimeofday(&self->start_time, NULL);
		if (run_philos(self))
			break ;
		status = table__wait(self);
		break ;
	}
	table__stop(self);
	return (status < 0);
}

int	table__wait(t_table *self)
{
	int		status;
	size_t	count;

	count = 0;
	while (count < self->len)
	{
		waitpid(-1, &status, 0);
		if (WIFEXITED(status) && WEXITSTATUS(status))
			return (WEXITSTATUS(status));
		count++;
	}
	return (0);
}

int	table__stop(t_table *self)
{
	size_t	i;

	i = 0;
	while (i < self->len)
		if (0 < self->process[i++])
			kill(self->process[i - 1], SIGTERM);
	i = 0;
	while (i < self->len)
	{
		if (0 < self->process[i++])
		{
			waitpid(self->process[i - 1], NULL, 0);
			self->process[i - 1] = -1;
		}
	}
	return (0);
}

static int	run_philos(t_table *self)
{
	size_t	i;
	t_philo	philo;

	i = 0;
	while (i < self->len)
	{
		if (philo__init(&philo, &(t_philo_args){i + 1, self}))
			return (-1);
		self->process[i] = run_subprocess((void *)philo__run, &philo);
		philo__del(&philo);
		if (self->process[i++] < 0)
			return (-1);
	}
	return (0);
}
