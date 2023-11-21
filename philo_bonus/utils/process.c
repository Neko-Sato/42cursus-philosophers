/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 04:24:02 by hshimizu          #+#    #+#             */
/*   Updated: 2023/11/21 07:52:14 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <semaphore.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

pid_t	run_subprocess(int (*routine)(void *), void *args)
{
	pid_t	pid;

	pid = fork();
	if (!pid)
		exit(routine(args));
	return (pid);
}

sem_t	*sem_new(unsigned int value)
{
	sem_t	*lock;

	lock = sem_open("temp", O_CREAT | O_EXCL, 600, value);
	if (lock)
		sem_unlink("temp");
	return (lock);
}
