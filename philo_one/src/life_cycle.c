/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadolph <sadolph@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 16:06:13 by sadolph           #+#    #+#             */
/*   Updated: 2021/01/13 00:00:31 by sadolph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"
#include "utils.h"

//static void			take_forks(t_philo *philo);
static void			eat(t_philo *philo);

void 				*life_cycle(void *data)
{
	struct timeval	mark_t;
	t_philo			*philo;
//	pthread_t		thread[1];

	g_check_die = 0;
	philo = (t_philo *)data;
	pthread_mutex_lock(philo->time);
	if (gettimeofday(&mark_t, NULL))
		return (NULL);
	philo->start_time = mark_t.tv_sec * 1000000 + mark_t.tv_usec;
	philo->last_eat = philo->start_time;
	pthread_mutex_unlock(philo->time);
//	pthread_create(thread, NULL, &check_die, data);
	pthread_detach(*philo->thread);
//	if (!(pthread_join(*thread, NULL)))
//		return (NULL);
	g_check_die = 1;
	while (1)
	{
//		take_forks(philo);
		eat(philo);
		if (philo->eat_times == 0)
		{
//			pthread_mutex_lock(philo->satisfied);
			++g_is_satisfied;
//			pthread_mutex_unlock(philo->satisfied);
			return (0);
		}
		print_status(philo, " is sleeping\n");
		ft_mysleep(philo->t_sleep * 1000);
		print_status(philo, " is thinking\n");
//		if (g_check_die)
//		{
//			pthread_join(*thread, NULL);
//			return (NULL);
//		}
	}
}

/*
static void			take_forks(t_philo *philo)
{
//	pthread_mutex_lock(philo->waiter);
	pthread_mutex_lock(philo->id % 2 ? philo->fork_l : philo->fork_r);
	print_status(philo, " has taken a left fork\n");
	pthread_mutex_lock(philo->id % 2 ? philo->fork_r : philo->fork_l);
	print_status(philo, " has taken a right fork\n");
//	pthread_mutex_unlock(philo->waiter);
}
*/

static void			eat(t_philo *philo)
{
	struct timeval	mark_t;

//	pthread_mutex_lock(philo->waiter);
	pthread_mutex_lock(philo->fork_l);
//	pthread_mutex_lock(philo->id % 2 ? philo->fork_l : philo->fork_r);
	print_status(philo, " has taken a left fork\n");
	pthread_mutex_lock(philo->fork_r);
//	pthread_mutex_lock(philo->id % 2 ? philo->fork_r : philo->fork_l);
	print_status(philo, " has taken a right fork\n");
//	pthread_mutex_unlock(philo->waiter);
	print_status(philo, " is EATING\n");
	--philo->eat_times;
	pthread_mutex_lock(philo->time);
	if (gettimeofday(&mark_t, NULL))
		return ;
	philo->last_eat = mark_t.tv_sec * 1000000 + mark_t.tv_usec;
	pthread_mutex_unlock(philo->time);
	ft_mysleep(philo->t_eat * 1000);
	pthread_mutex_unlock(philo->fork_l);
	pthread_mutex_unlock(philo->fork_r);
}
