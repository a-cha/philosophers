/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadolph <sadolph@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 15:45:38 by sadolph           #+#    #+#             */
/*   Updated: 2021/01/15 14:15:55 by sadolph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREE_H
# define PHILO_THREE_H

# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <unistd.h>

# define SEM_FORKS		"forks_sem"
# define SEM_PRINT		"print_sem"
# define SEM_WAITER		"waiter_sem"
# define SEM_DIE		"die_sem"
# define SEM_SATISFIED	"satisfied_sem"

int					g_n_philos;
int					g_is_satisfied;

typedef struct		s_table
{
	int				die;
	int				eat;
	int				sleep;
	long			start;
	sem_t			*forks;
	sem_t			*print;
	sem_t			*waiter;
	sem_t			*is_die;
	sem_t			*is_satisfied;
}					t_table;

typedef struct		s_philo
{
	int				id;
	pid_t			pid;
	long			last_eat;
	t_table			*table;
//	pthread_t		*thread;
	int				eat_times;
}					t_philo;

int					init_philos(t_philo *philos, char **av);
void				*life_cycle(void *data);
int					eat(t_philo *philo);
//void				*check_die(void *data);
void				*check_die_each(void *data);
void				ft_safety_exit(int status, t_philo *philos);

#endif
