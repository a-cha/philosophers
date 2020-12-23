//
// Created by Skipjack Adolph on 12/22/20.
//

#include "philo_one.h"

void				print_status(t_philo *philo, char *msg)
{
	struct timeval	mark_t;

	pthread_mutex_lock(philo->table->printing);
	if (gettimeofday(&mark_t, NULL))
		return ;
	ft_putnbr_fd((int)((mark_t.tv_sec * 1000 + mark_t.tv_usec / 1000)
												- philo->start_time), 1);
//	write(1, "A", 1);
	write(1, " ", 1);
//	write(1, "B", 1);
	ft_putnbr_fd(philo->id, 1);
//	write(1, "C", 1);
	ft_putstr_fd(msg, 1);
//	write(1, "D", 1);
	pthread_mutex_unlock(philo->table->printing);
}

/*
void 		print_status(t_philo *philo, char *msg)
{
	struct timeval	mark_t;
	int 			time;
	char 			*str;
	char			*tmp;
	char			*tmp1;

	if (gettimeofday(&mark_t, NULL))
		return ;
	time = (int)((mark_t.tv_sec * 1000 + mark_t.tv_usec / 1000) - philo->start_time);
	tmp = ft_itoa(time);
	tmp1 = ft_strjoin(tmp, " ");
	free(tmp);
	str = ft_itoa(philo->id);
	tmp = ft_strjoin(tmp1, str);
	free(tmp1);
	free(str);
	str = ft_strjoin(tmp, msg);
	ft_putstr_fd(str, 1);
	free(str);
	free(tmp);
	pthread_mutex_unlock(philo->printing);
}
*/
