/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 02:49:40 by hshimizu          #+#    #+#             */
/*   Updated: 2023/11/04 20:02:25 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_isnumber(const char *src, int issigned)
{
	if (issigned && *src && ft_strchr("+-", *src))
		src++;
	if (!*src)
		return (0);
	while (ft_isdigit(*src))
		src++;
	return (!*src);
}
