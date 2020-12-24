/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_die.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadolph <sadolph@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 18:56:46 by sadolph           #+#    #+#             */
/*   Updated: 2020/12/24 17:22:24 by sadolph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	*check_die(void *data)
{
	struct timeval	mark_t;
	t_philo			*philo;
	long			current;

	philo = data;
	current = 0;
	while (!g_check_die && current < philo->last_eat + philo->t_die * 1000)
	{
		usleep(10);
		if (gettimeofday(&mark_t, NULL))
			return (0);
		current = mark_t.tv_sec * 1000000 + mark_t.tv_usec;
	}
	print_status(philo, " IS DIED\n");
//	pthread_mutex_lock(philo->printing);
	g_check_die = 1;
	return (0);
}
