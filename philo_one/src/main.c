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
#include "errors.h"

/*
** Runs a single thread for each philosopher's life cycle
** And one more thread to check whether philo isn't dead
*/
void start_threads(t_philo *philos);

int				main(int ac, char **av)
{
	t_philo		philos[av[1] ? ft_atoi_cropped(av[1]) : 0];
	int			ret;

	if (ac < 5 || ac > 6 || (ac == 5 && ft_atoi_cropped(av[4]) == 0))
		exit(ERR_ARGS);
//	g_is_satisfied = 0;
	g_n_philos = ft_atoi_cropped(av[1]);
	if ((ret = init_philos(g_n_philos, philos, av)))
		exit(ret);
	start_threads(philos);
}

void			start_threads(t_philo *philos)
{
	int			i;
	pthread_t	threads[g_n_philos];
	pthread_t	thread_die[1];

	i = -1;
	while (++i < g_n_philos)
		philos[i].thread = &threads[i];
	g_check_die = 0;
	if ((i = pthread_create(thread_die, NULL, &check_die, &philos)))
		ft_safety_exit(i, philos);
	i = -1;
	while (++i < g_n_philos)
		if ((i = pthread_create(&threads[i], NULL, &life_cycle, &philos[i])))
			ft_safety_exit(i, philos);
	pthread_join(*thread_die, NULL);
	ft_safety_exit(0, philos);
}
