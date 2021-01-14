/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadolph <sadolph@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 16:06:13 by sadolph           #+#    #+#             */
/*   Updated: 2021/01/14 18:52:08 by sadolph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"
#include "utils.h"
#include "ft_print_status.h"

static int			eat(t_philo *philo);

void 				*life_cycle(void *data)
{
	t_philo			*philo;
//	pthread_t		thread[1];
	struct timeval		mark_t;

	philo = (t_philo *)data;
//	if ((pthread_create(thread, NULL, &check_die_each, data)))
//		return (NULL);
	if ((pthread_detach(*philo->thread)))
		return (NULL);
	if (gettimeofday(&mark_t, NULL))
		return (NULL);
	philo->table->start = (int)mark_t.tv_sec * 1000000 + mark_t.tv_usec;
	philo->last_eat = philo->table->start;
	g_check_die = 1;
//	philo->check_die = 1;
//	while (!g_check_die)
	while (1)
	{
//		take_forks(philo);
		if (eat(philo))
			break ;
		if (philo->eat_times == 0)
		{
//			pthread_mutex_lock(philo->table->satisfied);
			++g_is_satisfied;
//			pthread_mutex_unlock(philo->table->satisfied);
			break ;
		}
		ft_print_status(philo->id, philo->table->start, MSG_SLEEPING);
//		if (g_check_die)
//			break ;
		ft_mysleep(philo->table->sleep);
		ft_print_status(philo->id, philo->table->start, MSG_THINKING);
//		if (g_check_die)
//			break ;
	}
	return (NULL);
}

static int			eat(t_philo *philo)
{
	struct timeval	mark_t;

	pthread_mutex_lock(philo->fork_l);
//	pthread_mutex_lock(philo->id % 2 ? philo->fork_l : philo->fork_r);
	ft_print_status(philo->id, philo->table->start, MSG_TAKEN_FORK);
//	if (g_check_die)
//		return (-1);
	pthread_mutex_lock(philo->fork_r);
//	pthread_mutex_lock(philo->id % 2 ? philo->fork_r : philo->fork_l);
	ft_print_status(philo->id, philo->table->start, MSG_TAKEN_FORK);
//	pthread_mutex_unlock(philo->waiter);
//	if (g_check_die)
//		return (-1);
	ft_print_status(philo->id, philo->table->start, MSG_EATING);
	--philo->eat_times;
//	pthread_mutex_lock(philo->table->time);
	if (gettimeofday(&mark_t, NULL))
		return (ERR_GETTIME);
	philo->last_eat = (int)mark_t.tv_sec * 1000000 + mark_t.tv_usec;
//	pthread_mutex_unlock(philo->table->time);
	ft_mysleep(philo->table->eat);
	pthread_mutex_unlock(philo->fork_l);
//	pthread_mutex_unlock(philo->id % 2 ? philo->fork_r : philo->fork_l);
	pthread_mutex_unlock(philo->fork_r);
//	pthread_mutex_unlock(philo->id % 2 ? philo->fork_l : philo->fork_r);
	return (0);
}
