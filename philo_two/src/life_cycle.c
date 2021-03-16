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

#include "philo_two.h"
#include "utils.h"
#include "ft_print_status.h"

static int			eat(t_philo *philo);

void 				*life_cycle(void *data)
{
	t_philo			*philo;

	philo = (t_philo *)data;
	philo->table->start = ft_get_time();
	philo->last_eat = philo->table->start;
	if (philo->id % 2)
		ft_mysleep(philo->table->eat);
	while (philo->eat_times != 0)
	{
		eat(philo);
		if (philo->eat_times == 0)
		{
			++g_is_satisfied;
			break ;
		}
		pthread_mutex_lock(philo->table->print);
		ft_print_status(philo->id, philo->table->start, MSG_SLEEPING);
		pthread_mutex_unlock(philo->table->print);
		ft_mysleep(philo->table->sleep);
		pthread_mutex_lock(philo->table->print);
		ft_print_status(philo->id, philo->table->start, MSG_THINKING);
		pthread_mutex_unlock(philo->table->print);
	}
	return (NULL);
}

static int			eat(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_l);
	pthread_mutex_lock(philo->table->print);
	ft_print_status(philo->id, philo->table->start, MSG_TAKEN_FORK);
	pthread_mutex_unlock(philo->table->print);
	pthread_mutex_lock(philo->fork_r);
	pthread_mutex_lock(philo->table->print);
	ft_print_status(philo->id, philo->table->start, MSG_TAKEN_FORK);
	ft_print_status(philo->id, philo->table->start, MSG_EATING);
	pthread_mutex_unlock(philo->table->print);
	--philo->eat_times;
	philo->last_eat = ft_get_time();
	ft_mysleep(philo->table->eat);
	pthread_mutex_unlock(philo->fork_l);
	pthread_mutex_unlock(philo->fork_r);

	return (0);
}
