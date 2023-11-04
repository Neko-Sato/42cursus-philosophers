/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:53:31 by hshimizu          #+#    #+#             */
/*   Updated: 2023/11/04 19:13:57 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dining_philo.h"
#include <unistd.h>
#include <errno.h>

#define HELP_MASG "\
Usage: philo NUMBER TIME_TO_DIE TIME_TO_EAT TIME_TO_SLEEP [MUST_EAT]\n\
\n\
\tNUMBER\t\tNumber of philosophers and forks.\n\
\tTIME_TO_DIE\tTime to die.\n\
\tTIME_TO_EAT\tTime to eat.\n\
\tTIME_TO_SLEEP\tTime to sleep.\n\
\t[MUST_EAT]\tTime to finish when all philosophers have eaten that many times.\n\
\n\
All arguments must be unsigned signed integers greater than zero.\n\
\n\
Made by hshimizu.\n\
source: https://github.com/Neko-Sato/42cursus-philosophers\n\
"

static int	purse_args(t_dining_philo_args *args, int argc, char *argv[]);

int	main(int argc, char *argv[])
{
	t_dining_philo_args	args;

	if (purse_args(&args, argc, argv))
	{
		write(STDERR_FILENO, HELP_MASG, sizeof(HELP_MASG));
		return (1);
	}
	if (1 && dining_philo(&args))
	{
		write(STDERR_FILENO, "Error\n", 6);
		return (1);
	}
	return (0);
}

static int	purse_args(t_dining_philo_args *args, int argc, char *argv[])
{
	if (argc < 5 || 6 < argc)
		return (-1);
	return -1;
	// args->len = ft_atol(argv[1]);
	// if (errno || args->len < 1)
	// 	retrun (-1);
	// args->time_to_die = ft_atol(argv[2]);
	// if (errno)
	// 	retrun (-1);
	// args->time_to_eat = ft_atol(argv[3]);
	// if (errno)
	// 	retrun (-1);
	// args->time_to_sleep = ft_atol(argv[4]);
	// if (errno)
	// 	retrun (-1);
	// if (argc < 6)
	// 	args->must_eat = 0;
	// else
	// 	args->must_eat = ft_atol(argv[5]);
	// if (errno)
	// 	retrun (-1);
	// return (0);
}
