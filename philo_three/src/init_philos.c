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

#include "philo_three.h"
#include "init_philos.h"
#include "utils.h"
#include "errors.h"
#include <stdlib.h>

int					init_philos(t_philo *philos, char **av)
{
	t_table			*table;
	int				i;

	if ((i = init_table(&table, av)))
		return (i);
	i = -1;
	while (++i < g_n_philos)
	{
		philos[i].id = i + 1;
		philos[i].table = table;
		philos[i].eat_times = av[5] ? ft_atoi(av[5]) : -1;
	}
	return (0);
}

static int			init_table(t_table **table, char **av)
{
	if (!(*table = malloc(sizeof(t_table))))
		return (ERR_MALLOC);
	if (!((*table)->forks = init_sem(SEM_FORKS, g_n_philos)))
		return (ERR_SEMAPHORE);
	if (!((*table)->print = init_sem(SEM_PRINT, 1)))
		return (ERR_SEMAPHORE);
	if (!((*table)->waiter = init_sem(SEM_WAITER, g_n_philos / 2)))
		return (ERR_SEMAPHORE);
	(*table)->die = ft_atoi(av[2]);
	(*table)->eat = ft_atoi(av[3]);
	(*table)->sleep = ft_atoi(av[4]);
	return (0);
}

static sem_t		*init_sem(const char *name, int value)
{
	sem_t			*sem;

	sem_unlink(name);
	if ((sem = sem_open(name, O_CREAT | O_EXCL, 0644, value)) == SEM_FAILED)
		return (NULL);
	return (sem);
}
