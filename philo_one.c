
#include "philo_one.h"

void				init_forks(int n, pthread_mutex_t *forks)
{
	int 			i;

	i = 0;
	while (i < n)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

t_philo				*init_philos(int n, long start_time, int eat_times)
{
	t_philo			*philos;
	pthread_mutex_t	forks[n];
	pthread_mutex_t	waiter[1];
	int				i;

	init_forks(n, forks);
	if (!(philos = (t_philo *)malloc(sizeof(t_philo *) * n)))
		return (NULL);
	i = -1;
	while (++i < n)
	{
		philos[i].id = i + 1;
		philos[i].fork_l = &forks[i];
		philos[i].fork_r = &forks[(i + 1) % n];
		philos[i].eat_times = eat_times;
		philos[i].t_last_eat = start_time;
		philos[i].start_time = start_time;
	}
	pthread_mutex_init(waiter, NULL);
	philos[i].waiter = waiter;
	return (philos);
}

//	allocates memory in stack
//	maybe move start time mark paster
t_info				*get_info(char **av)
{
	t_info			*info;
	struct timeval	start_t;

	info = &(t_info){
	ft_atoi(av[1]),
	ft_atoi(av[2]),
	ft_atoi(av[3]),
	ft_atoi(av[4]), av[5] ? ft_atoi(av[5]) : -1,
	0};
	if (gettimeofday(&start_t, NULL))
		return (NULL);
	info->start_time = start_t.tv_sec * 1000 + start_t.tv_usec / 1000;
	return (info);
}

int 				main(int ac, char **av)
{
	t_info			*info;
	t_philo			*philos;
//	for time test
	struct timeval	end_t;
	long 			curr_time;
	char 			*time;

	if (ac < 5 || ac > 6 || !(info = get_info(av)) ||
	!(philos = init_philos(info->n_phil, info->start_time, info->eat_times)))
		return (-1);
//	simulation();
//	for time test
//
	sleep(1);
	if (gettimeofday(&end_t, NULL))
		return (-1);
	curr_time = (end_t.tv_sec * 1000 + end_t.tv_usec / 1000) - info->start_time;
	time = ft_itoa((int)(curr_time - info->start_time));
	ft_putstr_fd(time, 1);
	free(time);
//
	return (0);
}

