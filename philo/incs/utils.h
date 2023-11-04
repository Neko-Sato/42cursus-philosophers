/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:33:00 by hshimizu          #+#    #+#             */
/*   Updated: 2023/11/04 20:21:12 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <pthread.h>
# include <sys/time.h>

int				ft_strlen(const char *s);
long			ft_atol(const char *str);
int				ft_isdigit(int c);
int				ft_isnumber(const char *src, int issigned);
int				ft_isspace(int c);
char			*ft_strchr(const char *s, int c);

pthread_t		*thread_start(void *(*routine)(void *), void *args);
int				thread_join(pthread_t *thread, void **thread_return);
pthread_mutex_t	*mutex_new(void);
int				mutex_del(pthread_mutex_t *var);

long			timeval2useconds(struct timeval t);
struct timeval	interval(struct timeval a, struct timeval b);

int				msleep(unsigned int msec);

#endif