/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:22:36 by hshimizu          #+#    #+#             */
/*   Updated: 2023/11/06 18:03:28 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dining_philo.h"
#include "philo_visualizer.h"
#include "table.h"
#include <stdio.h>

int	dining_philo(t_dining_philo_args *args)
{
	t_table	*table;
	int		ret;

	ret = 1;
	while (1)
	{
		philovisualizer_init(args->len);
		table = table__new(&(t_table_args){args->len, args->time_to_die,
				args->time_to_eat, args->time_to_sleep, args->must_eat,
				args->lock_printf});
		if (!table)
			return (1);
		if (table__start(table))
			return (1);
		table__wait(table);
		ret = 0;
		break ;
	}
	table__del(&table);
	return (ret);
}
