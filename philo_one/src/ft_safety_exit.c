//
// Created by Skipjack Adolph on 3/15/21.
//

#include "philo_one.h"

void	ft_safety_exit(int status, t_philo *philos)
{
	int	i;

	pthread_mutex_destroy(philos[0].table->print);
	pthread_mutex_destroy(philos[0].table->time);
	pthread_mutex_destroy(philos[0].table->satisfied);
	i = -1;
	while (++i < g_n_philos)
		pthread_mutex_destroy(philos[i].fork_l);
	exit(status);
}
