/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:33:00 by hshimizu          #+#    #+#             */
/*   Updated: 2023/11/06 19:58:45 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <pthread.h>
# include <stddef.h>
# include <sys/time.h>

size_t			even_odd(size_t i, size_t len);
size_t			reverse_even_odd(size_t i, size_t len);

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