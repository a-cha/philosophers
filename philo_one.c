/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadolph <sadolph@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 15:45:35 by sadolph           #+#    #+#             */
/*   Updated: 2020/12/21 20:50:02 by sadolph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static void			init_philos(int n, t_philo *philos, char **av);
static void			init_forks(int n, pthread_mutex_t *forks);

int					main(int ac, char **av)
{
	int				i;
	int				n_philos;
	t_philo			philos[av[1] ? ft_atoi(av[1]) : 0];
	pthread_t		threads[av[1] ? ft_atoi(av[1]) : 0];

	if (ac < 5 || ac > 6)
		return (-1);
	n_philos = ft_atoi(av[1]);
	init_philos(n_philos, philos, av);
	i = -1;
	while (++i < n_philos)
		pthread_create(&threads[i], NULL, &life_cycle, &philos[i]);
	i = -1;
	while (++i < n_philos)
		pthread_join(threads[i], NULL);
	return (0);
}

static void			init_philos(int n, t_philo *philos, char **av)
{
	pthread_mutex_t forks[n];
	pthread_mutex_t	waiter[1];
	pthread_mutex_t	printing[1];
	int				i;

	init_forks(n, forks);
	pthread_mutex_init(waiter, NULL);
	pthread_mutex_unlock(waiter);
	pthread_mutex_init(printing, NULL);
	pthread_mutex_unlock(printing);
	i = -1;
	while (++i < n)
	{
		philos[i].id = i + 1;
		philos[i].waiter = waiter;
		philos[i].printing = printing;
		philos[i].fork_l = &forks[i];
		philos[i].fork_r = &forks[(i + 1) % n];
		philos[i].t_die = ft_atoi(av[2]);
		philos[i].t_eat = ft_atoi(av[3]);
		philos[i].t_sleep = ft_atoi(av[4]);
		philos[i].eat_times = av[5] ? ft_atoi(av[5]) : -1;
	}
}

static void			init_forks(int n, pthread_mutex_t *forks)
{
	int				i;

	i = -1;
	while (++i < n)
	{
		pthread_mutex_init(&forks[i], NULL);
		pthread_mutex_unlock(&forks[i]);
	}
}
