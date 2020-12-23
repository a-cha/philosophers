/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadolph <sadolph@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 18:08:59 by sadolph           #+#    #+#             */
/*   Updated: 2020/12/23 20:20:41 by sadolph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"
#include "utils.h"

void				print_status(t_philo *philo, char *msg)
{
	struct timeval	mark_t;

	pthread_mutex_lock(philo->printing);
	if (gettimeofday(&mark_t, NULL))
		return ;
	ft_putnbr_fd((int)((mark_t.tv_sec * 1000 + mark_t.tv_usec / 1000)
										- philo->start_time / 1000), 1);
	write(1, " ", 1);
	ft_putnbr_fd(philo->id, 1);
	ft_putstr_fd(msg, 1);
	pthread_mutex_unlock(philo->printing);
}
