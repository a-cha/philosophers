/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadolph <sadolph@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 16:06:13 by sadolph           #+#    #+#             */
/*   Updated: 2020/12/22 16:20:09 by sadolph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static void			take_forks(t_philo *philo);
static void			eating(t_philo *philo);

void 				*life_cycle(void *data)
{
	struct timeval	mark_t;
	t_philo			*philo;

	philo = (t_philo *)data;
	if (gettimeofday(&mark_t, NULL))
		return (NULL);
	philo->start_time = mark_t.tv_sec * 1000 + mark_t.tv_usec / 1000;
	philo->last_eat_time = mark_t.tv_sec * 1000 + mark_t.tv_usec / 1000;
	while (1)
	{
		take_forks(philo);
		eating(philo);
		print_status(philo, " is sleeping\n");
		ft_mysleep((long)philo->t_sleep * 1000);
		print_status(philo, " is thinking\n");
	}
}

static void			take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->waiter);
	pthread_mutex_lock(philo->fork_l);
	print_status(philo, " has taken a left fork\n");
	pthread_mutex_lock(philo->fork_r);
	print_status(philo, " has taken a right fork\n");
	pthread_mutex_unlock(philo->waiter);
}

static void			eating(t_philo *philo)
{
	struct timeval	mark_t;

	print_status(philo, " is eating\n");
	ft_mysleep((long)philo->t_eat * 1000);
	pthread_mutex_unlock(philo->fork_l);
	pthread_mutex_unlock(philo->fork_r);
	pthread_mutex_lock(philo->time);
	if (gettimeofday(&mark_t, NULL))
		return ;
	philo->last_eat_time = mark_t.tv_sec * 1000 + mark_t.tv_usec / 1000;
	pthread_mutex_unlock(philo->time);
}
