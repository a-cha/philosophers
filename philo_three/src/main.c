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

#include "philo_three.h"
#include "utils.h"
#include "errors.h"

/*
** Runs a single thread for each philosopher's life cycle
** And one more thread to check whether philo is dead
*/
#include <sys/wait.h>
#include <stdlib.h>

int						main(int ac, char **av)
{
	int					i;
	t_philo				philos[av[1] ? ft_atoi(av[1]) : 0];
//	pthread_t			threads[av[1] ? ft_atoi(av[1]) : 0];
//	pthread_t			thread_die[1];
	int					ret;

	if (ac < 5 || ac > 6 || (ac == 5 && ft_atoi(av[4]) == 0))
		return (ERR_ARGS);
	g_n_philos = ft_atoi(av[1]);
	if ((ret = init_philos(philos, av)))
		return (ret);
	i = -1;
//	while (++i < g_n_philos)
//		philos[i].thread = &threads[i];
//	pthread_create(thread_die, NULL, &check_die, &philos);

	i = -1;
	while (++i < g_n_philos)
	{
		if ((philos[i].pid = fork()) == -1)
			return (ERR_PROCESS);
		if (philos[i].pid == 0)
			life_cycle(&philos[i]);
	}
	if (philos->eat_times >= 0)
	{
		i = -1;
		while (++i < g_n_philos)
		{
			sem_wait(philos[0].table->is_satisfied);
		}
		sem_wait(philos->table->print);
		i = -1;
		while (++i < g_n_philos)
			kill(philos[i].pid, SIGKILL);
	}
	else
	{
		sem_wait(philos[0].table->is_die);
		i = -1;
		while (++i < g_n_philos)
			kill(philos[i].pid, SIGKILL);
	}
	ft_safety_exit(0, philos);

/*
	i = -1;
	while (++i < g_n_philos)
		pthread_create(&threads[i], NULL, &life_cycle, &philos[i]);
	i = -1;
	while (++i < g_n_philos)
		pthread_join(*philos[i].thread, NULL);
	ft_safety_exit(0, philos);
*/
}
