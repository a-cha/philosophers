/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadolph <sadolph@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 15:45:35 by sadolph           #+#    #+#             */
/*   Updated: 2020/12/23 21:34:47 by sadolph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"
#include "utils.h"

static void				init_philos(int n, t_philo *philos, char **av);
static pthread_mutex_t	*init_forks(int n);
static pthread_mutex_t	*init_mutex();

int						main(int ac, char **av)
{
	int					i;
	int					n_philos;
	t_philo				philos[av[1] ? ft_atoi(av[1]) : 0];
	pthread_t			threads[av[1] ? ft_atoi(av[1]) : 0];

	if (ac < 5 || ac > 6)
		return (-1);
	n_philos = ft_atoi(av[1]);
	init_philos(n_philos, philos, av);
	i = -1;
	while (++i < n_philos)
		pthread_create(&threads[i], NULL, &life_cycle, &philos[i]);
//	pthread_create(&threads[0], NULL, &life_cycle, &philos[0]);
//	pthread_join(threads[0], NULL);
//	pthread_detach(threads[0]);
	i = -1;
	while (++i < n_philos)
		pthread_join(threads[i], NULL);
//	i = -1;
//	while (++i < n_philos)
//		pthread_detach(threads[i]);
	pthread_mutex_destroy(philos[i].waiter);
	pthread_mutex_destroy(philos[i].printing);
	pthread_mutex_destroy(philos[i].time);
	while (++i < n_philos)
		pthread_mutex_destroy(philos[i].fork_l);
	return (0);
}

static void				init_philos(int n, t_philo *philos, char **av)
{
	pthread_mutex_t		*waiter;
	pthread_mutex_t		*printing;
	pthread_mutex_t		*time;
	pthread_mutex_t 	*forks;
	int					i;

	waiter = init_mutex();
	printing = init_mutex();
	time = init_mutex();
	forks = init_forks(n);
	i = -1;
	while (++i < n)
	{
		philos[i].id = i + 1;
		philos[i].fork_l = &forks[i];
		philos[i].fork_r = &forks[(i + 1) % n];
		philos[i].waiter = waiter;
		philos[i].printing = printing;
		philos[i].time = time;
		philos[i].t_die = ft_atoi(av[2]);
		philos[i].t_eat = ft_atoi(av[3]);
		philos[i].t_sleep = ft_atoi(av[4]);
		philos[i].eat_times = av[5] ? ft_atoi(av[5]) : -1;
	}
}

static pthread_mutex_t	*init_forks(int n)
{
	int					i;
	pthread_mutex_t 	*forks;

	i = -1;
	forks = malloc(n * sizeof(pthread_mutex_t));
	while (++i < n)
		pthread_mutex_init(&forks[i], NULL);
	return (forks);
}

static pthread_mutex_t	*init_mutex()
{
	pthread_mutex_t		*mutex;

	mutex = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(mutex, NULL);
	return (mutex);
}
