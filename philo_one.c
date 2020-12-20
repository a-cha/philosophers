
#include "philo_one.h"

t_philo				**init_mutex(int n, long start_time, int eat_times)
{
	t_philo			**philos;
	int				i;

	if (!(philos = (t_philo **)malloc(sizeof(t_philo *) * (n + 1))))
		return (NULL);
	i = -1;
	while (++i < n)
	{
		if (!(philos[i] = (t_philo *)malloc(sizeof(t_philo))))
			return (NULL);
//		fork 1
//		fork 2
		philos[i]->eat_times = eat_times;
		philos[i]->t_last_eat = start_time;
		philos[i]->start_time = start_time;
	}
	philos[n] = NULL;
	return (philos);
}

//	allocates memory in stack
//	marks the time before ft_atoi (can do it after)
t_info				*get_info(char **av)
{
	t_info			*info;
	struct timeval	start_t;

	if (gettimeofday(&start_t, NULL))
		return (NULL);
	info = &(t_info){
	ft_atoi(av[1]),
	ft_atoi(av[2]),
	ft_atoi(av[3]),
	ft_atoi(av[4]), av[5] ? ft_atoi(av[5]) : -1,
	start_t.tv_sec * 1000 + start_t.tv_usec / 1000};
	return (info);
}

int 				main(int ac, char **av)
{
	t_info			*info;
	t_philo			**philos;
	struct timeval	end_t;
	long 			curr_time;

	if (ac < 5 || ac > 6 || !(info = get_info(av)))
		return (-1);
	if (!(philos = init_mutex(info->n_phil, info->start_time, info->eat_times)))
		return (-1);
	if (gettimeofday(&end_t, NULL))
	{
		free(philos);
		return (-1);
	}
	sleep(1);
	curr_time = (end_t.tv_sec * 1000 + end_t.tv_usec / 1000) - info->start_time;
	ft_putstr_fd(ft_itoa((int)(curr_time - info->start_time)), 1);
//	simulation();
	return (0);
}
