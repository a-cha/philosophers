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

#include "philo_two.h"

void	ft_safety_exit(int status, t_philo *philos)
{
	int	i;

	pthread_mutex_destroy(philos[0].table->print);
	pthread_mutex_destroy(philos[0].table->time);
	pthread_mutex_destroy(philos[0].table->satisfied);
	i = -1;
	while (++i < g_n_philos)
		pthread_mutex_destroy(philos[i].fork_l);
	exit(status);
}