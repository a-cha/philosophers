//
// Created by Skipjack Adolph on 12/20/20.
//

#ifndef PHILOSOPHERS_PHILO_ONE_H
#define PHILOSOPHERS_PHILO_ONE_H

#include <sys/time.h>
#include "utils/utils.h"
// remove
#include <stdio.h>

typedef struct	s_info
{
	int 		n_phil;
	int 		t_die;
	int 		t_eat;
	int 		t_sleep;
	int 		eat_times;
	long		start_time;
}				t_info;

typedef struct	s_philo
{
	int 		mut;
	long 		t_last_eat;
}				t_philo;


#endif //PHILOSOPHERS_PHILO_ONE_H
