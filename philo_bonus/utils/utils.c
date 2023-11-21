/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:21:22 by hshimizu          #+#    #+#             */
/*   Updated: 2023/11/06 21:44:03 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	even_odd(size_t i, size_t len)
{
	size_t	c;

	c = len / 2 + len % 2;
	if (c <= i)
		return ((i - c) * 2 + 1);
	else
		return (i * 2);
}

size_t	reverse_even_odd(size_t i, size_t len)
{
	return (i / 2 + (i % 2) * (len / 2 + i % 2));
}
