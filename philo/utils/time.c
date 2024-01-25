/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 09:43:59 by hshimizu          #+#    #+#             */
/*   Updated: 2024/01/25 12:46:47 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <unistd.h>

long	timeval2useconds(struct timeval t)
{
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

struct timeval	interval(struct timeval a, struct timeval b)
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

static int	gettime(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (timeval2useconds(time));
}

void	msleep(unsigned int time)
{
	int	end_time;

	end_time = gettime() + time;
	while (end_time > gettime())
		usleep((end_time - gettime()) / 4 * 1000);
}
