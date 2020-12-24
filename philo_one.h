/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadolph <sadolph@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 15:45:38 by sadolph           #+#    #+#             */
/*   Updated: 2020/12/24 14:28:01 by sadolph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

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

void				*life_cycle(void *data);
void 				print_status(t_philo *philo, char *msg);
void			 	check_die(t_philo *philo);

#endif
