/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:22:36 by hshimizu          #+#    #+#             */
/*   Updated: 2023/11/04 22:31:23 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dining_philo.h"
#include "philo.h"
#include "philo_visualizer.h"
#include "table.h"
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct s_dining_philo_local
{
	pthread_mutex_t	*lock_printf;
	t_table			*table;
	t_philo			**philos;
}					t_dining_philo_local;

static int			execute(t_dining_philo_local *local,
						t_dining_philo_args *args);
static void			final(t_dining_philo_local *local,
						t_dining_philo_args *args);
static t_philo		**create_philos(t_dining_philo_local *local,
						t_dining_philo_args *args);

int	dining_philo(t_dining_philo_args *args)
{
	t_dining_philo_local	local;
	int						ret;

	ret = execute(&local, args);
	final(&local, args);
	return (ret);
}

static int	execute(t_dining_philo_local *local,
					t_dining_philo_args *args)
{
	philovisualizer_init(args->len);
	local->lock_printf = mutex_new();
	if (!local->lock_printf)
		return (1);
	local->philos = create_philos(local, args);
	if (!local->philos)
		return (1);
	local->table = table__new(&(t_table_args){args->len, local->philos});
	if (!local->table)
		return (1);
	if (table__start(local->table))
		return (1);
	table__wait(local->table);
	return (0);
}

static void	final(t_dining_philo_local *local,
					t_dining_philo_args *args)
{
	long	i;

	table__del(&local->table);
	i = 0;
	while (i < args->len)
		philo__del(&local->philos[i++]);
	free(local->philos);
	mutex_del(local->lock_printf);
}

static t_philo	**create_philos(t_dining_philo_local *local,
								t_dining_philo_args *args)
{
	t_philo	**philos;
	long	i;

	philos = malloc(sizeof(t_philo *[args->len]));
	i = 0;
	while (philos && i < args->len)
	{
		philos[i] = philo__new(&(t_philo_args){local->lock_printf,
				args->time_to_die, args->time_to_eat, args->time_to_sleep,
				args->must_eat});
		if (!philos[i])
		{
			while (--i)
				free(philos[i]);
			free(philos);
			philos = NULL;
		}
		i++;
	}
	return (philos);
}
