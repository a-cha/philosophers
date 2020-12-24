/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_die.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadolph <sadolph@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 18:56:46 by sadolph           #+#    #+#             */
/*   Updated: 2020/12/24 13:59:52 by sadolph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void 	check_die(t_philo *philo)
{
	struct timeval	mark_t;
	long			current;

	current = 0;
	while (current < philo->last_eat + philo->t_die * 1000)
	{
		usleep(10);
		if (gettimeofday(&mark_t, NULL))
			return ;
		current = mark_t.tv_sec * 1000000 + mark_t.tv_usec;
	}
}
