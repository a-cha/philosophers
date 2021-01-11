/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadolph <sadolph@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 15:45:38 by sadolph           #+#    #+#             */
/*   Updated: 2020/12/24 17:21:08 by sadolph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

char	g_check_die;

typedef struct		s_philo
{
	int				id;
	pthread_mutex_t	*fork_l;
	pthread_mutex_t	*fork_r;
//	pthread_mutex_t	*waiter;
	pthread_mutex_t	*printing;
	pthread_mutex_t	*time;
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
