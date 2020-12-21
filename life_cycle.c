//
// Created by Skipjack Adolph on 12/21/20.
//

#include "philo_one.h"

void 				*life_cycle(void *data)
{
	struct timeval	mark_t;
	t_philo			*philo;
	int 			time;
	char			*str;
	philo = (t_philo *)data;

	if (gettimeofday(&mark_t, NULL))
		;
	philo->start_time = mark_t.tv_sec * 1000 + mark_t.tv_usec / 1000;
	philo->last_eat_time = mark_t.tv_sec * 1000 + mark_t.tv_usec / 1000;
	while (1)
	{
		pthread_mutex_lock(philo->waiter);
		pthread_mutex_lock(philo->fork_l);
		pthread_mutex_lock(philo->fork_r);
		pthread_mutex_unlock(philo->waiter);
//		take a fork
//		is this status about one fork or two forks?
		if (gettimeofday(&mark_t, NULL))
			;
		time = (int)(philo->start_time - (mark_t.tv_sec * 1000 + mark_t.tv_usec / 1000));
		if (!(str = ft_itoa(time)))
			return (NULL);
		ft_putstr_fd(str, 1);
		write(1, " ", 1);
		if (!(str = ft_itoa(philo->id)))
			return (NULL);
		ft_putstr_fd(str, 1);
		ft_putstr_fd(" has taken a fork\n", 1);
//		eating
		if (!(str = ft_itoa(time)))
			return (NULL);
		ft_putstr_fd(str, 1);
		write(1, " ", 1);
		if (!(str = ft_itoa(philo->id)))
			return (NULL);
		ft_putstr_fd(str, 1);
		ft_putstr_fd(" is eating\n", 1);
		usleep(philo->t_eat);
		pthread_mutex_unlock(philo->fork_l);
		pthread_mutex_unlock(philo->fork_r);
//		sleeping
		if (gettimeofday(&mark_t, NULL))
			;
		time = (int)(philo->start_time - (mark_t.tv_sec * 1000 + mark_t.tv_usec / 1000));
		if (!(str = ft_itoa(time)))
			return (NULL);
		ft_putstr_fd(str, 1);
		write(1, " ", 1);
		if (!(str = ft_itoa(philo->id)))
			return (NULL);
		ft_putstr_fd(str, 1);
		ft_putstr_fd(" is sleeping\n", 1);
		usleep(philo->t_sleep);
//		thinking
		if (gettimeofday(&mark_t, NULL))
			;
		time = (int)(philo->start_time - (mark_t.tv_sec * 1000 + mark_t.tv_usec / 1000));
		if (!(str = ft_itoa(time)))
			return (NULL);
		ft_putstr_fd(str, 1);
		write(1, " ", 1);
		if (!(str = ft_itoa(philo->id)))
			return (NULL);
		ft_putstr_fd(str, 1);
		ft_putstr_fd(" is thinking\n", 1);
	}
	return (NULL);
}
