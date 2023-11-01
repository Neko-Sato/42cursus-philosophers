/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:33:00 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/29 01:44:53 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <pthread.h>
# include <sys/time.h>

pthread_t		*thread_start(void *(*routine)(void *), void *args);
int				thread_join(pthread_t *thread, void **thread_return);
pthread_mutex_t	*mutex_new(void);
int				mutex_del(pthread_mutex_t *var);

long			timeval2useconds(struct timeval t);
struct timeval	interval(struct timeval a, struct timeval b);

int				msleep(unsigned int msec);

#endif