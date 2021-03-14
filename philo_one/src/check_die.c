/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_die.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadolph <sadolph@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 18:56:46 by sadolph           #+#    #+#             */
/*   Updated: 2021/01/15 21:28:14 by sadolph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"
#include "ft_print_status.h"
#include "utils.h"

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

void				*check_die(void *data)
{
	struct timeval	mark_t;
	t_philo			*philo;
	unsigned int	current;
	unsigned int	t_to_die;
	int 			i;

	while (!g_check_die)
		;
	philo = data;
//	TODO dikost' here
	t_to_die = philo[0].table->die * 1000;
//	t_to_die = philo[0].table->die * 1000;
//	t_to_die = philo[0].table->die * 1001;
	while (1)
	{
//		if (g_is_satisfied == g_n_philos)
//		{
//			pthread_mutex_lock(philo->printing);
//			return (0);
//		}
		i = -1;
		while (++i < g_n_philos)
		{
			if (gettimeofday(&mark_t, NULL))
				return (0);
//			if (philo[i].last_eat + t_to_die < (unsigned int)mark_t.tv_sec * 1000000 + mark_t.tv_usec)
			current = ft_get_time();
			if (philo[i].last_eat + t_to_die < current)
			{
				ft_print_status(philo[i].id, philo[i].table->start, MSG_DIED);
				pthread_mutex_lock(philo->table->print);
				return (0);
			}
			usleep(50);
		}
	}
}
//1748686333 + 800000 - 1748686330
//856325096
//855564506