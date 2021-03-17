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

#include "philo_three.h"
#include "ft_print_status.h"
#include "utils.h"
#include <unistd.h>

void				*check_die_each(void *data)
{
	t_philo		*philo;
	long		t_to_die;

	philo = data;
	t_to_die = philo->table->die * 1000;
	while (1)
	{
			if (g_is_satisfied == g_n_philos)
			{
				sem_wait(philo->table->print);
				return (0);
			}
			usleep(100);
			if (philo->last_eat + t_to_die < ft_get_time())
			{
				ft_print_status(philo->id, philo->table->start, MSG_DIED);
				sem_wait(philo->table->print);
				sem_post(philo->table->is_die);
				return (0);
			}
	}
}
