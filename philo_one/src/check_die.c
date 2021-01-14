/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_die.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadolph <sadolph@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 18:56:46 by sadolph           #+#    #+#             */
/*   Updated: 2021/01/14 13:39:49 by sadolph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"
#include "print_status.h"

/*
void				*check_die_each_main(void *data)
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
	print_status(philo->printing, philo->id, philo->t_start, MSG_DIED);
	return (0);
}
*/

void				*check_die_each(void *data)
{
	struct timeval	mark_t;
	t_philo			*philo;
	int 			current;

	philo = data;
	current = 0;
	while (current < (int)(philo->last_eat + philo->table->die * 1000))
	{
		if (g_check_die)
			return (NULL);
		usleep(10);
		if (gettimeofday(&mark_t, NULL))
			return (NULL);
		current = (int)(mark_t.tv_sec * 1000000 + mark_t.tv_usec);
	}
	g_check_die = 1;
	print_status(philo->id, philo->table->start, MSG_DIED);
	return (0);
}

/*
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
				print_status(philo[i].printing, philo[i].id, philo[i].t_start, MSG_DIED);
				pthread_mutex_lock(philo->printing);
				return (0);
			}
		}
	}
}
*/
