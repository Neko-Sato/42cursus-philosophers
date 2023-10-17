/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 04:24:02 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/17 09:59:21 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>

pthread_mutex_t	*mutex_new(void)
{
	pthread_mutex_t	*var;

	var = malloc(sizeof(pthread_mutex_t));
	if (var && pthread_mutex_init(var, NULL))
		free(var);
	return (var);
}

int	mutex_del(pthread_mutex_t *var)
{
	if (var && pthread_mutex_destroy(var))
		return (-1);
	free(var);
	return (0);
}

long	timeval2useconds(struct timeval t)
{
	return (t.tv_sec * 1000000l + t.tv_usec);
}

struct timeval	get_interval(struct timeval a, struct timeval b)
{
	struct timeval	ret;

	ret.tv_sec = a.tv_sec - b.tv_sec;
	ret.tv_usec = a.tv_usec - b.tv_usec;
	while (ret.tv_usec < 0)
	{
		ret.tv_sec--;
		ret.tv_usec += 1000000;
	}
	ret.tv_sec += ret.tv_usec / 1000000;
	ret.tv_usec %= 1000000;
	if (ret.tv_sec < 0)
	{
		ret.tv_sec++;
		ret.tv_usec -= 1000000;
	}
	return (ret);
}
