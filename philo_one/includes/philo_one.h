/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadolph <sadolph@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 15:45:38 by sadolph           #+#    #+#             */
/*   Updated: 2021/01/15 14:15:55 by sadolph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

int					g_n_philos;
int					g_is_satisfied;

typedef struct		s_table
{
	int				die;
	int				eat;
	int				sleep;
	long			start;
	pthread_mutex_t	*print;
	pthread_mutex_t	*time;
	pthread_mutex_t	*satisfied;
}					t_table;

typedef struct		s_philo
{
	int				id;
	long			last_eat;
	t_table			*table;
	pthread_mutex_t	*fork_l;
	pthread_mutex_t	*fork_r;
	pthread_t		*thread;
	int				eat_times;
	int				check_die;
}					t_philo;

int					init_philos(t_philo *philos, char **av);
static int			init_table(t_table **table, char **av);
static int			init_forks(pthread_mutex_t **forks, int n);
static int			init_mutex(pthread_mutex_t **mutex);

void				*life_cycle(void *data);
static int			eat(t_philo *philo);
void				*check_die(void *data);
void				ft_safety_exit(int status, t_philo *philos);

#endif
