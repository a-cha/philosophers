/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadolph <sadolph@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 15:45:35 by sadolph           #+#    #+#             */
/*   Updated: 2021/01/13 21:35:23 by sadolph          ###   ########.fr       */
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
//	pthread_t			thread_die[av[1] ? ft_atoi(av[1]) : 0];
	pthread_t			thread_die[1];
	int 				ret;

	if (ac < 5 || ac > 6 || (ac == 5 && ft_atoi(av[4]) == 0))
		return (-1);
//	g_is_satisfied = 0;
	g_n_philos = ft_atoi(av[1]);
	if ((ret = init_philos(g_n_philos, philos, av)))
		return (ret);
	i = -1;
	while (++i < g_n_philos)
		philos[i].thread = &threads[i];
	g_check_die = 0;
	pthread_create(thread_die, NULL, &check_die, &philos);
//	i = -1;
//	while (++i < g_n_philos)
//		pthread_create(&thread_die[i], NULL, &check_die, &philos[i]);
	i = -1;
	while (++i < g_n_philos)
		pthread_create(&threads[i], NULL, &life_cycle, &philos[i]);
//	pthread_create(&threads[0], NULL, &life_cycle, &philos[0]);
//	pthread_join(threads[0], NULL);
//	pthread_detach(threads[0]);
	pthread_join(*thread_die, NULL);
//	i = -1;
//	while (++i < g_n_philos)
//		pthread_join(thread_die[i], NULL);

	pthread_mutex_destroy(philos[0].printing);
	pthread_mutex_destroy(philos[0].time);
	i = -1;
	while (++i < g_n_philos)
		pthread_mutex_destroy(philos[i].fork_l);
	return (0);
}
