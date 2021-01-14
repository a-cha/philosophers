/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_die.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadolph <sadolph@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 18:56:46 by sadolph           #+#    #+#             */
/*   Updated: 2021/01/14 15:56:07 by sadolph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"
#include "ft_print_status.h"

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
	ft_print_status(philo->id, philo->table->start, MSG_DIED);
	return (0);
}

/*
void				*check_die(void *data)
{
	struct timeval	mark_t;
	t_philo			*philo;
	int 			current;
	int 			i;

	while (!g_check_die)
		;
	philo = data;
	while (1)
	{
		if (g_is_satisfied == g_n_philos)
			return (0);
		i = -1;
		while (++i < g_n_philos)
		{
			current = (int)mark_t.tv_sec * 1000000 + mark_t.tv_usec;
			if (current < (int)philo[i].last_eat + philo[i].table->die * 1000)
			{
				usleep(10);
				if (gettimeofday(&mark_t, NULL))
					return (0);
			}
			else
			{
				ft_print_status(philo[i].id, philo[i].table->start, MSG_DIED);
//				pthread_mutex_lock(philo->printing);
				return (0);
			}
		}
	}
}
*/
