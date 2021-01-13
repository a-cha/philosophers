/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadolph <sadolph@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 15:45:38 by sadolph           #+#    #+#             */
/*   Updated: 2021/01/13 17:11:53 by sadolph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

# define TAKE_FORK " has taken a fork\n"
# define EATING "\e[0;32m is eating\033[0m\n"
# define THINKING " is thinking\n"
# define SLEEPING " is sleeping\n"
# define DIED "\033[31m is died\033[0m\n"

char	g_check_die;
int 	g_n_philos;
int 	g_is_satisfied;

typedef struct		s_philo
{
	int				id;
	int 			check_die;
	pthread_mutex_t	*fork_l;
	pthread_mutex_t	*fork_r;
//	pthread_mutex_t	*satisfied;
	pthread_mutex_t	*printing;
	pthread_mutex_t	*time;
	pthread_t		*thread;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				eat_times;
	long			start_time;
	long			last_eat;
}					t_philo;

void				init_philos(int n, t_philo *philos, char **av);
void				*life_cycle(void *data);
void 				print_status(t_philo *philo, char *msg);
void			 	*check_die(void *data);

#endif
