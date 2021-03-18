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
#include <signal.h>

/*
** Runs a separate process for each philosopher's life cycle
*/

int						main(int ac, char **av)
{
	int					i;
	t_philo				philos[av[1] ? ft_atoi(av[1]) : 0];
	int					ret;

	if (ac < 5 || ac > 6 || (ac == 5 && ft_atoi(av[4]) == 0))
		return (ERR_ARGS);
	g_n_philos = ft_atoi(av[1]);
	if ((ret = init_philos(philos, av)))
		return (ret);
	i = -1;
	while (++i < g_n_philos)
	{
		if ((philos[i].pid = fork()) == -1)
			return (ERR_PROCESS);
		if (philos[i].pid == 0)
			life_cycle(&philos[i]);
	}
	sem_wait(philos[0].table->sem_is_die);
	i = -1;
	while (++i < g_n_philos)
	{
		usleep(1000);
		kill(philos[i].pid, SIGKILL);
	}
	ft_safety_exit(0, philos);
}
