/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:06:56 by hshimizu          #+#    #+#             */
/*   Updated: 2023/11/04 19:48:11 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <errno.h>
#include <limits.h>

long	ft_atol(const char *str)
{
	unsigned long	cutoff;
	int				neg;
	int				n;
	unsigned long	result;

	neg = 0;
	result = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		neg = *str++ == '-';
	cutoff = (unsigned long []){LONG_MIN, LONG_MAX}[neg];
	while ('0' <= *str && *str <= '9')
	{
		result *= 10;
		n = *str++ - '0';
		if (result > cutoff || cutoff - result < (unsigned long)n)
		{
			result = cutoff;
			errno = EINVAL;
			break ;
		}
		result += n;
	}
	return ((long []){1l, -1l}[neg] * result);
}
