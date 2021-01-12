/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadolph <sadolph@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 23:36:29 by sadolph           #+#    #+#             */
/*   Updated: 2021/01/13 00:01:38 by sadolph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"
#include "utils.h"

static pthread_mutex_t	*init_forks(int n);
static pthread_mutex_t	*init_mutex();

void					init_philos(int n, t_philo *philos, char **av)
{
	pthread_mutex_t		*printing;
	pthread_mutex_t		*time;
	pthread_mutex_t 	*forks;
//	pthread_mutex_t 	*satisfied;
	int					i;

	printing = init_mutex();
	time = init_mutex();
//	satisfied = init_mutex();
	forks = init_forks(n);
	i = -1;
	while (++i < n)
	{
		philos[i].id = i + 1;
//		philos[i].fork_l = &forks[(i + 1) % n];
//		philos[i].fork_r = &forks[i];
		philos[i].fork_l = &forks[philos[i].id % 2 ? i : (i + 1) % n];
		philos[i].fork_r = &forks[philos[i].id % 2 ? (i + 1) % n : i];
		philos[i].printing = printing;
		philos[i].time = time;
//		philos[i].satisfied = satisfied;
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
