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

#include "philo_three.h"
#include "utils.h"
#include "ft_print_status.h"

void				*life_cycle(void *data)
{
	t_philo			*philo;
	pthread_t 		thread_die[1];

	philo = (t_philo *)data;
	philo->table->start = ft_get_time();
	philo->last_eat = philo->table->start;
	if ((pthread_create(thread_die, NULL, &check_die_each, data)))
		return (NULL);
//	if (philo->id % 2)
//		ft_mysleep(philo->table->eat);
	while (philo->eat_times != 0)
	{
		eat(philo);
		if (philo->eat_times == 0)
		{
			++g_is_satisfied;
			break ;
		}
		sem_wait(philo->table->print);
		ft_print_status(philo->id, philo->table->start, MSG_SLEEPING);
		sem_post(philo->table->print);
		ft_mysleep(philo->table->sleep);
		sem_wait(philo->table->print);
		ft_print_status(philo->id, philo->table->start, MSG_THINKING);
		sem_post(philo->table->print);
	}
	return (NULL);
}

int					eat(t_philo *philo)
{
	sem_wait(philo->table->waiter);
	sem_wait(philo->table->forks);
	sem_wait(philo->table->print);
	ft_print_status(philo->id, philo->table->start, MSG_TAKEN_FORK);
	sem_post(philo->table->print);
	sem_wait(philo->table->forks);
	sem_wait(philo->table->print);
	ft_print_status(philo->id, philo->table->start, MSG_TAKEN_FORK);
	ft_print_status(philo->id, philo->table->start, MSG_EATING);
	sem_post(philo->table->print);
	--philo->eat_times;
	philo->last_eat = ft_get_time();
	ft_mysleep(philo->table->eat);
	sem_post(philo->table->forks);
	sem_post(philo->table->forks);
	sem_post(philo->table->waiter);
	return (0);
}
