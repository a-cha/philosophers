/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_die.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadolph <sadolph@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 18:56:46 by sadolph           #+#    #+#             */
/*   Updated: 2021/01/13 17:26:36 by sadolph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

/*
void				*check_die(void *data)
{
	struct timeval	mark_t;
	t_philo			*philo;
	long			current;

	philo = data;
	while (!philo->check_die)
		;
	current = 0;
	while (current < philo->last_eat + philo->t_die * 1000)
	{
		usleep(10);
		if (gettimeofday(&mark_t, NULL))
			return (0);
		current = mark_t.tv_sec * 1000000 + mark_t.tv_usec;
	}
	print_status(philo, DIED);
	return (0);
}
*/

void				*check_die(void *data)
{
	struct timeval	mark_t;
	t_philo			*philo;
	long			current;
	int 			i;

	while (!g_check_die)
		;
	philo = data;
	current = 0;
	while (1)
	{
		i = -1;
		if (g_is_satisfied == g_n_philos)
			return (0);
		while (++i < g_n_philos)
		{
			if (current < philo[i].last_eat + philo[i].t_die * 1000)
			{
				usleep(10);
				if (gettimeofday(&mark_t, NULL))
					return (0);
				current = mark_t.tv_sec * 1000000 + mark_t.tv_usec;
			}
			else
			{
				print_status(&philo[i], DIED);
				pthread_mutex_lock(philo->printing);
				return (0);
			}
		}
	}
}
