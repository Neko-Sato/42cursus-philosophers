/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 04:24:02 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/29 01:44:43 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>

pthread_t	*thread_start(void *(*routine)(void *), void *args)
{
	pthread_t	*thread;

	thread = malloc(sizeof(pthread_t));
	if (thread && pthread_create(thread, NULL, routine, args))
	{
		free(thread);
		thread = NULL;
	}
	return (thread);
}

int	thread_join(pthread_t *thread, void **thread_return)
{
	if (thread && pthread_join(*thread, thread_return))
		return (-1);
	free(thread);
	return (0);
}

pthread_mutex_t	*mutex_new(void)
{
	pthread_mutex_t	*var;

	var = malloc(sizeof(pthread_mutex_t));
	if (var && pthread_mutex_init(var, NULL))
	{
		free(var);
		var = NULL;
	}
	return (var);
}

int	mutex_del(pthread_mutex_t *var)
{
	if (var && pthread_mutex_destroy(var))
		return (-1);
	free(var);
	return (0);
}
