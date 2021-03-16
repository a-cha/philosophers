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

#include "philo_two.h"
#include "ft_print_status.h"
#include "utils.h"
#include <unistd.h>

void			*check_die(void *data)
{
	t_philo		*philo;
	int			t_to_die;
	int			i;

	philo = data;
	t_to_die = philo[0].table->die * 1000;
	while (1)
	{
		i = -1;
		while (++i < g_n_philos)
		{
			if (g_is_satisfied == g_n_philos)
			{
				sem_wait(philo->table->print);
				return (0);
			}
			usleep(100);
			if (philo[i].last_eat + t_to_die < ft_get_time())
			{
				sem_wait(philo->table->print);
				ft_print_status(philo[i].id, philo[i].table->start, MSG_DIED);
				return (0);
			}
		}
	}
}
