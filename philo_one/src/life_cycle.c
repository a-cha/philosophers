/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadolph <sadolph@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 16:06:13 by sadolph           #+#    #+#             */
/*   Updated: 2021/01/15 17:36:54 by sadolph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"
#include "utils.h"
#include "ft_print_status.h"

static int			eat(t_philo *philo);

void 				*life_cycle(void *data)
{
	t_philo			*philo;

	philo = (t_philo *)data;
	philo->table->start = ft_get_time();
	philo->last_eat = philo->table->start;

	g_check_die = 1;
	if (philo->id % 2)
		ft_mysleep(philo->table->eat);
	while (philo->eat_times != 0)
	{
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
		ft_mysleep(philo->table->sleep);
		ft_print_status(philo->id, philo->table->start, MSG_THINKING);
//		if (g_check_die)
//			break ;
	}
	return (NULL);
}

static int			eat(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_l);
	ft_print_status(philo->id, philo->table->start, MSG_TAKEN_FORK);
//	pthread_mutex_unlock(philo->table->print);
//	if (g_check_die)
//		return (-1);
	pthread_mutex_lock(philo->fork_r);
	ft_print_status(philo->id, philo->table->start, MSG_TAKEN_FORK);
	ft_print_status(philo->id, philo->table->start, MSG_EATING);
	--philo->eat_times;
	philo->last_eat = ft_get_time();
	ft_mysleep(philo->table->eat);
	pthread_mutex_unlock(philo->fork_l);
	pthread_mutex_unlock(philo->fork_r);

	return (0);
}
