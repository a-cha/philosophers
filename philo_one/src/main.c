/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadolph <sadolph@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 15:45:35 by sadolph           #+#    #+#             */
/*   Updated: 2021/01/12 23:54:36 by sadolph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"
#include "utils.h"

int						main(int ac, char **av)
{
	int					i;
//	int					n_philos;
	t_philo				philos[av[1] ? ft_atoi(av[1]) : 0];
	pthread_t			threads[av[1] ? ft_atoi(av[1]) : 0];
	pthread_t			thread_die;

	if (ac < 5 || ac > 6 || ft_atoi(av[5]) == 0)
		return (-1);
	g_n_philos = ft_atoi(av[1]);
	init_philos(g_n_philos, philos, av);
	i = -1;
	while (++i < g_n_philos)
		philos[i].thread = &threads[i];
	g_check_die = 0;
	g_is_satisfied = 0;
	pthread_create(&thread_die, NULL, &check_die, philos);
	i = -1;
	while (++i < g_n_philos)
		pthread_create(&threads[i], NULL, &life_cycle, &philos[i]);
	pthread_join(thread_die, NULL);
//	pthread_create(&threads[0], NULL, &life_cycle, &philos[0]);
//	pthread_join(threads[0], NULL);
//	pthread_detach(threads[0]);
//	i = -1;
//	while (++i < g_n_philos)
//		pthread_join(threads[i], NULL);
//	i = -1;
//	while (++i < g_n_philos)
//		pthread_detach(threads[i]);
//	pthread_mutex_destroy(philos[i].waiter);

// TODO segfault when destroyed mutex (why?)
//	pthread_mutex_destroy(philos[i].printing);
//	pthread_mutex_destroy(philos[i].time);
//	while (++i < g_n_philos)
//		pthread_mutex_destroy(philos[i].fork_l);
	return (0);
}
