/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadolph <sadolph@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 16:06:13 by sadolph           #+#    #+#             */
/*   Updated: 2020/12/22 00:16:38 by sadolph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static void			take_forks(t_philo *philo);
static void			eating(t_philo *philo);
static void 		print_status(t_philo *philo, char *msg);

void 				*life_cycle(void *data)
{
	struct timeval	mark_t;
	t_philo			*philo;

	philo = (t_philo *)data;
	if (gettimeofday(&mark_t, NULL))
		return (NULL);
	philo->start_time = mark_t.tv_sec * 1000 + mark_t.tv_usec / 1000;
	philo->last_eat_time = mark_t.tv_sec * 1000 + mark_t.tv_usec / 1000;
	while (1)
	{
		take_forks(philo);
		eating(philo);
		pthread_mutex_lock(philo->printing);
		print_status(philo, " is sleeping\n");
		ft_mysleep((long)philo->t_sleep * 1000);
		pthread_mutex_lock(philo->printing);
		print_status(philo, " is thinking\n");
	}
}

static void			take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->waiter);
	pthread_mutex_lock(philo->fork_l);
	pthread_mutex_lock(philo->printing);
	print_status(philo, " has taken a left fork\n");
	pthread_mutex_lock(philo->fork_r);
	pthread_mutex_lock(philo->printing);
	print_status(philo, " has taken a right fork\n");
	pthread_mutex_unlock(philo->waiter);
}

static void			eating(t_philo *philo)
{
	struct timeval	mark_t;

	pthread_mutex_lock(philo->printing);
	print_status(philo, " is eating\n");
	ft_mysleep((long)philo->t_eat * 1000);
	pthread_mutex_unlock(philo->fork_l);
	pthread_mutex_unlock(philo->fork_r);
//	mutex for time
	if (gettimeofday(&mark_t, NULL))
		return ;
	philo->last_eat_time = mark_t.tv_sec * 1000 + mark_t.tv_usec / 1000;
}

static void 		print_status(t_philo *philo, char *msg)
{
	struct timeval	mark_t;
	int 			time;
	char 			*str;
	char			*tmp;
	char			*tmp1;

	if (gettimeofday(&mark_t, NULL))
		return ;
	time = (int)((mark_t.tv_sec * 1000 + mark_t.tv_usec / 1000) - philo->start_time);
	tmp = ft_itoa(time);
	tmp1 = ft_strjoin(tmp, " ");
	free(tmp);
	str = ft_itoa(philo->id);
	tmp = ft_strjoin(tmp1, str);
	free(str);
// free join result
	ft_putstr_fd(ft_strjoin(tmp, msg), 1);
//	ft_putnbr_fd(time, 1);
//	write(1, " ", 1);
//	ft_putnbr_fd(philo->id, 1);
//	ft_putstr_fd(msg, 1);

	pthread_mutex_unlock(philo->printing);
}
