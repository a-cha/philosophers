/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadolph <sadolph@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 18:08:59 by sadolph           #+#    #+#             */
/*   Updated: 2021/01/12 19:31:25 by sadolph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"
#include "utils.h"

//void				print_status(t_philo *philo, char *msg)
//{
//	struct timeval	mark_t;
//	char 			*status;
//	int 			i;
//
//	pthread_mutex_lock(philo->printing);
//	status = malloc(40);
//	if (gettimeofday(&mark_t, NULL))
//		return ;
//	i = ft_putnbr_str((int)((mark_t.tv_sec * 1000 + mark_t.tv_usec / 1000)
//										- philo->start_time / 1000), status);
//	status[i++] = ' ';
//	i += ft_putnbr_str(philo->id, status);
//	status[i] = '\0';
//	ft_putstr_fd(status, 1);
//	ft_putstr_fd(msg, 1);
//	pthread_mutex_unlock(philo->printing);
//}

int		ft_putstr_str(char *s1, char *s2);

//void				print_status(long start_time, int id, char *msg)
//{
//	struct timeval	mark_t;
//	char 			*status;
//	int 			i;
//
//	status = malloc(1000);
//	if (gettimeofday(&mark_t, NULL))
//		return ;
//	i = ft_putnbr_str((int)((mark_t.tv_sec * 1000 + mark_t.tv_usec / 1000)
//							- start_time / 1000), status);
//	status[i++] = ' ';
//	i += ft_putnbr_str(id, status + i);
//	i += ft_putstr_str(status + i, msg);
//	status[i] = '\0';
//	ft_putstr_fd(status, 1);
//}

void				print_status(t_philo *philo, char *msg)
{
	struct timeval	mark_t;
	char 			*status;
	int 			i;

	pthread_mutex_lock(philo->printing);
	status = malloc(33);
	if (gettimeofday(&mark_t, NULL))
		return ;
	i = ft_putnbr_str((int)((mark_t.tv_sec * 1000 + mark_t.tv_usec / 1000)
							- philo->start_time / 1000), status);
	status[i++] = ' ';
	i += ft_putnbr_str(philo->id, status + i);
	i += ft_putstr_str(status + i, msg);
	status[i] = '\0';
	ft_putstr_fd(status, 1);
	free(status);
	pthread_mutex_unlock(philo->printing);
}
