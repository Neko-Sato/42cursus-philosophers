/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:53:31 by hshimizu          #+#    #+#             */
/*   Updated: 2024/01/25 15:53:48 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dining_philo.h"
#include "utils.h"
#include <errno.h>
#include <unistd.h>

#define MSG_INVALID_VALUE "Invalid value\n"
#define MSG_ERROR "Error\n"

static int	purse_args(t_dining_philo_args *args, int argc, char *argv[]);
static void	put_error(int code);
static int	str2num(long *num, char *str, long min, long max);

int	main(int argc, char *argv[])
{
	t_dining_philo_args	args;
	int					code;

	code = purse_args(&args, argc, argv);
	if (!code && dining_philo(&args))
		code = -1;
	put_error(code);
	return (code);
}

static void	put_error(int code)
{
	char	*msg;

	if (!code)
		return ;
	else if (code == 1)
		msg = "\
Usage : ./philo_bonus NUMBER TIME_TO_DIE TIME_TO_EAT TIME_TO_SLEEP [MUST_EAT]\n\
\n\
\tNUMBER\t\tNumber of philosophers and forks.\n\
\tTIME_TO_DIE\tTime to die.\n\
\tTIME_TO_EAT\tTime to eat.\n\
\tTIME_TO_SLEEP\tTime to sleep.\n\
\t[MUST_EAT]\tFinish when each philosopher has eaten this many times.\n\
\n\
Made by hshimizu.\n\
github\t: https://github.com/Neko-Sato\n\
profile\t: https://profile.intra.42.fr/users/hshimizu\n\
";
	else if (code == 2)
		msg = MSG_INVALID_VALUE;
	else
		msg = MSG_ERROR;
	write(STDERR_FILENO, msg, ft_strlen(msg));
}

static int	purse_args(t_dining_philo_args *args, int argc, char *argv[])
{
	if (argc < 5 || 6 < argc)
		return (1);
	if (str2num(&args->len, argv[1], 1, (long)(~0u)))
		return (2);
	if (str2num(&args->time_to_die, argv[2], 50, (long)(~0u)))
		return (2);
	if (str2num(&args->time_to_eat, argv[3], 50, (long)(~0u)))
		return (2);
	if (str2num(&args->time_to_sleep, argv[4], 50, (long)(~0u)))
		return (2);
	if (argc != 6)
		args->must_eat = 0;
	else if (str2num(&args->must_eat, argv[5], 1, (long)(~0u)))
		return (2);
	return (0);
}

static int	str2num(long *num, char *str, long min, long max)
{
	long	n;

	if (!ft_isnumber(str, 0))
		return (-1);
	n = ft_atol(str);
	if (errno || n < min || max < n)
		return (-1);
	*num = n;
	return (0);
}
