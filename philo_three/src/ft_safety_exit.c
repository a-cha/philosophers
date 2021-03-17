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

void	ft_safety_exit(int status, __unused t_philo *philos)
{
	sem_unlink(SEM_FORKS);
	sem_unlink(SEM_PRINT);
	sem_unlink(SEM_WAITER);
//	sem_close(philos[0].table->forks);
//	sem_close(philos[0].table->print);
//	sem_close(philos[0].table->waiter);
	exit(status);
}
