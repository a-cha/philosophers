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
#include "errors.h"

int						main(int ac, char **av)
{
	int					i;
	t_philo				philos[av[1] ? ft_atoi_cropped(av[1]) : 0];
	pthread_t			threads[av[1] ? ft_atoi_cropped(av[1]) : 0];
	pthread_t			thread_die[1];
	int 				ret;

	if (ac < 5 || ac > 6 || (ac == 5 && ft_atoi_cropped(av[4]) == 0))
		return (ERR_ARGS);
//	g_is_satisfied = 0;
	g_n_philos = ft_atoi_cropped(av[1]);
	if ((ret = init_philos(g_n_philos, philos, av)))
		return (ret);

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

////	clean memory


	ft_safety_exit(0, philos);
}
