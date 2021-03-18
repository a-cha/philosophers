/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safety_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadolph <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 13:59:03 by sadolph           #+#    #+#             */
/*   Updated: 2021/03/16 13:59:23 by sadolph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"
#include <stdlib.h>

void	ft_safety_exit(int status, t_philo *philos)
{
	int i;

	sem_unlink(SEM_FORKS);
	sem_unlink(SEM_PRINT);
	sem_unlink(SEM_WAITER);
	sem_unlink(SEM_DIE);
	sem_close(philos[0].table->sem_forks);
	sem_close(philos[0].table->sem_print);
	sem_close(philos[0].table->sem_waiter);
	sem_close(philos[0].table->sem_is_die);
	i = -1;
	while (++i < g_n_philos)
	{
		sem_unlink(SEM_PRINT_PHILO);
		sem_close(philos[i].sem_print_philo);
	}
	exit(status);
}
