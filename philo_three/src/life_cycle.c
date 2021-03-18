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
#include <stdlib.h>

void				*life_cycle(void *data)
{
	t_philo			*philo;
	pthread_t		thread_die[1];

	philo = (t_philo *)data;
	philo->table->start = ft_get_time();
	philo->last_eat = philo->table->start;
	if ((pthread_create(thread_die, NULL, &check_die_each, data)))
		return (NULL);
	pthread_detach(*thread_die);
	while (1)
	{
		eat(philo);
		if (philo->eat_times == 0)
		{
			sem_post(philo->table->sem_is_die);
			sem_wait(philo->sem_print_philo);
			exit(0);
		}
		input_msg(philo, MSG_SLEEPING);
		ft_mysleep(philo->table->sleep);
		input_msg(philo, MSG_THINKING);
	}
}

int					eat(t_philo *philo)
{
	sem_wait(philo->table->sem_waiter);
	sem_wait(philo->table->sem_forks);
	input_msg(philo, MSG_TAKEN_FORK);
	sem_wait(philo->table->sem_forks);
	input_msg(philo, MSG_TAKEN_FORK);
	input_msg(philo, MSG_EATING);
	--philo->eat_times;
	philo->last_eat = ft_get_time();
	ft_mysleep(philo->table->eat);
	sem_post(philo->table->sem_forks);
	sem_post(philo->table->sem_forks);
	sem_post(philo->table->sem_waiter);
	return (0);
}

void				input_msg(t_philo *philo, char *msg)
{
	sem_wait(philo->table->sem_print);
	sem_wait(philo->sem_print_philo);
	ft_print_status(philo->id, philo->table->start, msg);
	sem_post(philo->sem_print_philo);
	sem_post(philo->table->sem_print);
}
