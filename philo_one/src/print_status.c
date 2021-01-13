/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadolph <sadolph@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 18:08:59 by sadolph           #+#    #+#             */
/*   Updated: 2021/01/13 15:26:10 by sadolph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"
#include "utils.h"

int					ft_putstr_str(char *s1, char *s2);

void				print_status(t_philo *philo, char *msg)
{
	struct timeval	mark_t;
	char 			status[30];
	int 			i;

	pthread_mutex_lock(philo->printing);
	if (gettimeofday(&mark_t, NULL))
		return ;
	i = ft_putnbr_str((int)((mark_t.tv_sec * 1000 + mark_t.tv_usec / 1000)
							- philo->start_time / 1000), status);
	status[i++] = ' ';
	i += ft_putnbr_str(philo->id, status + i);
	i += ft_putstr_str(status + i, msg);
	status[i] = '\0';
	ft_putstr(status);
	pthread_mutex_unlock(philo->printing);
}
