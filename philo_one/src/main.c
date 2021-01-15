/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadolph <sadolph@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 15:45:35 by sadolph           #+#    #+#             */
/*   Updated: 2021/01/15 16:57:51 by sadolph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"
#include "utils.h"
#include "ft_print_status.h"

int						main(int ac, char **av)
{
	int					i;
	t_philo				philos[av[1] ? ft_atoi(av[1]) : 0];
	pthread_t			threads[av[1] ? ft_atoi(av[1]) : 0];
	pthread_t			thread_die[1];
	int 				ret;
//	int					n_philos;
//	pthread_t			thread_die[av[1] ? ft_atoi(av[1]) : 0];
//	struct timeval		mark_t;

	if (ac < 5 || ac > 6 || (ac == 5 && ft_atoi(av[4]) == 0))
		return (-1);
//	g_is_satisfied = 0;
	g_n_philos = ft_atoi(av[1]);
	if ((ret = init_philos(g_n_philos, philos, av)))
		return (ret);
//	if (gettimeofday(&mark_t, NULL))
//		return (ERR_GETTIME);
//	philos->table->start = mark_t.tv_sec * 1000000 + mark_t.tv_usec;

////	one thread to die
	i = -1;
	while (++i < g_n_philos)
		philos[i].thread = &threads[i];
	g_check_die = 0;
	pthread_create(thread_die, NULL, &check_die, &philos);
	i = -1;
	while (++i < g_n_philos)
		pthread_create(&threads[i], NULL, &life_cycle, &philos[i]);
	pthread_join(*thread_die, NULL);

////	thread for each philo to die + detached philos
//	i = -1;
//	while (++i < g_n_philos)
//		pthread_create(&thread_die[i], NULL, &check_die, &philos[i]);
//	i = -1;
//	while (++i < g_n_philos)
//		pthread_create(&threads[i], NULL, &life_cycle, &philos[i]);//	i = -1;
//	while (++i < g_n_philos)
//		pthread_join(thread_die[i], NULL);

////	thread for each philo to die creates into philos
//	g_check_die = 0;
//	pthread_create(thread_die, NULL, &check_die, &philos);
//	i = -1;
//	while (++i < g_n_philos)
//		pthread_create(&threads[i], NULL, &life_cycle, &philos[i]);
//	i = -1;
//	pthread_join(*thread_die, NULL);

	pthread_mutex_destroy(philos[0].table->print);
	pthread_mutex_destroy(philos[0].table->time);
	pthread_mutex_destroy(philos[0].table->satisfied);
	i = -1;
	while (++i < g_n_philos)
		pthread_mutex_destroy(philos[i].fork_l);
	return (0);
}
