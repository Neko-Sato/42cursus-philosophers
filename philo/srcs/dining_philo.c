/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:22:36 by hshimizu          #+#    #+#             */
/*   Updated: 2023/11/04 18:20:31 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dining_philo.h"
#include "philo.h"
#include "table.h"
#include "utils.h"
#include <stddef.h>

typedef struct s_dining_philo_local
{
	pthread_mutex_t	*lock_printf;
	t_table			*table;
	t_philo			**philos;
}					t_dining_philo_local;

int	dining_philo(t_dining_philo_args *args)
{
	(void)args;
	return 1;
	// philovisualizer_init(args->len);
	// lock_printf = mutex_new();
	// if (!lock_printf)
	// 	break ;
	// philos = create_philos();
	// if (!philos)
	// 	break ;
	// table = table__new(&(t_table_args){args->len, philos});
	// if (!table)
	// 	break ;
	// table__start(table);
	// table__wait(table);
	// table__del(&table);
	// i = 0;
	// while (i < args->len)
	// 	philo__del(&philos[i++]);
	// free(philos);
	// mutex_del(lock_printf);
	// return (0);
}

// static t_philo	**create_philos(t_dining_philo_args *args,
			// void *lock_printf)
// {
// 	t_philo			**philos;
// 	unsigned int	i;

// 	philos = malloc(sizeof(t_philo *[args->len]));
// 	i = 0;
// 	while (i < args->len)
// 	{
// 		philos[i] = philo__new(&(t_philo_args){lock_printf, args->time_to_die,
// 				args->time_to_eat, args->time_to_sleep, args->must_eat});
// 		if (!philos[i])
// 		{
// 			while (--i)
// 				free(i);
// 			free(philos);
// 			philos = NULL;
// 			break ;
// 		}
// 	}
// 	return (philos);
// }
