/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadolph <sadolph@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 15:45:38 by sadolph           #+#    #+#             */
/*   Updated: 2020/12/22 18:12:35 by sadolph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include "utils.h"
# include <sys/time.h>
# include <pthread.h>

typedef struct		s_table
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	*waiter;
	pthread_mutex_t	*printing;
	pthread_mutex_t	*time;
}					t_table;

typedef struct		s_philo
{
	int				id;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				eat_times;
	long			start_time;
	long			last_eat_time;
	t_table			*table;
}					t_philo;

void				*life_cycle(void *data);
void 				print_status(t_philo *philo, char *msg);

#endif
