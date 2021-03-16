/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadolph <sadolph@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 23:36:29 by sadolph           #+#    #+#             */
/*   Updated: 2021/01/13 21:55:03 by sadolph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"
#include "init_philos.h"
#include "utils.h"
#include "errors.h"

int					init_philos(t_philo *philos, char **av)
{
	t_table			*table;
	pthread_mutex_t	*forks;
	int				i;

	if ((i = init_table(&table, av)))
		return (i);
	if ((i = init_forks(&forks, g_n_philos)))
		return (i);
	i = -1;
	while (++i < g_n_philos)
	{
		philos[i].id = i + 1;
		philos[i].table = table;
		philos[i].fork_r = &forks[(i + 1) % g_n_philos];
		philos[i].fork_l = &forks[i];
		philos[i].eat_times = av[5] ? ft_atoi(av[5]) : -1;
		philos[i].check_die = 0;
	}
	return (0);
}

static int			init_table(t_table **table, char **av)
{
	int				ret;

	if (!(*table = malloc(sizeof(t_table))))
		return (ERR_MALLOC);
	if ((ret = init_mutex(&(*table)->time)))
	{
		free(table);
		return (ret);
	}
	if ((ret = init_mutex(&(*table)->print)))
	{
		free(table);
		return (ret);
	}
	(*table)->die = ft_atoi(av[2]);
	(*table)->eat = ft_atoi(av[3]);
	(*table)->sleep = ft_atoi(av[4]);
	return (0);
}

static int			init_forks(pthread_mutex_t **forks, int n)
{
	int				i;

	if (!(*forks = malloc(n * sizeof(pthread_mutex_t))))
		return (ERR_MALLOC);
	i = -1;
	while (++i < n)
		if ((pthread_mutex_init(&(*forks)[i], NULL)))
		{
			free(*forks);
			return (ERR_PTHREAD);
		}
	return (0);
}

static int			init_mutex(pthread_mutex_t **mutex)
{
	if (!(*mutex = malloc(sizeof(pthread_mutex_t))))
		return (ERR_MALLOC);
	if ((pthread_mutex_init(*mutex, NULL)))
	{
		free(*mutex);
		return (ERR_PTHREAD);
	}
	return (0);
}
