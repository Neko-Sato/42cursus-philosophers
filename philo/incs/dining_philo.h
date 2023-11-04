/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining_philo.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:05:18 by hshimizu          #+#    #+#             */
/*   Updated: 2023/11/04 18:14:23 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DINING_PHILO_H
# define DINING_PHILO_H

typedef struct s_dining_philo_args
{
	long	len;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	must_eat;
}			t_dining_philo_args;

int			dining_philo(t_dining_philo_args *args);

#endif