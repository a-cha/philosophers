//
// Created by Skipjack Adolph on 12/20/20.
//

#ifndef PHILOSOPHERS_PHILO_ONE_H
#define PHILOSOPHERS_PHILO_ONE_H

#include <sys/time.h>
#include "utils/utils.h"
#include <pthread.h>
// remove
#include <stdio.h>

typedef struct		s_philo
{
	int 			id;
	pthread_mutex_t	*waiter;
	pthread_mutex_t	*fork_l;
	pthread_mutex_t	*fork_r;
	int 			t_die;
	int 			t_eat;
	int 			t_sleep;
	int 			eat_times;
	long			start_time;
	long 			last_eat_time;
}					t_philo;

void 				*life_cycle(void *data);

#endif //PHILOSOPHERS_PHILO_ONE_H
