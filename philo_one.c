/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadolph <sadolph@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 15:45:35 by sadolph           #+#    #+#             */
/*   Updated: 2020/12/22 18:24:50 by sadolph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static void			init_philos(int n, t_philo *philos, char **av);
static void			init_forks(int n, pthread_mutex_t *forks);
static t_table		*init_table(int n);

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
	i = -1;
//	pthread_mutex_destroy(philos[i].waiter);
//	pthread_mutex_destroy(philos[i].printing);
//	pthread_mutex_destroy(philos[i].time);
//	while (++i < n_philos)
//		pthread_mutex_destroy(philos[i].fork_l);
	return (0);
}

static void			init_philos(int n, t_philo *philos, char **av)
{
	t_table			*table;
	int				i;

	table = init_table(n);
	i = -1;
	while (++i < n)
	{
		philos[i].id = i + 1;
//		philos[i].fork_l = &forks[i];
//		philos[i].fork_r = &forks[(i + 1) % n];
		philos[i].t_die = ft_atoi(av[2]);
		philos[i].t_eat = ft_atoi(av[3]);
		philos[i].t_sleep = ft_atoi(av[4]);
		philos[i].eat_times = av[5] ? ft_atoi(av[5]) : -1;
		philos[i].table = table;
	}
}

static void			init_forks(int n, pthread_mutex_t *forks)
{
	int				i;

	i = -1;
	while (++i < n)
		pthread_mutex_init(&forks[i], NULL);
}

static t_table		*init_table(int n)
{
	pthread_mutex_t	*waiter;
	pthread_mutex_t	*printing;
	pthread_mutex_t	*time;
	pthread_mutex_t *forks;
	t_table			*table;

	waiter = malloc(sizeof(pthread_mutex_t));
	printing = malloc(sizeof(pthread_mutex_t));
	time = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(waiter, NULL);
	pthread_mutex_init(printing, NULL);
	pthread_mutex_init(time, NULL);
	table = malloc(sizeof(t_table));
	table->waiter = waiter;
	table->printing = printing;
	table->time = time;
	forks = malloc(n * sizeof(pthread_mutex_t));
	init_forks(n, forks);
	table->forks = forks;
	return (table);
}
