
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
	pthread_mutex_init(waiter, NULL);
	while (++i < n)
	{
		philos[i].waiter = waiter;
		philos[i].id = i + 1;
		philos[i].fork_l = &forks[i];
		philos[i].fork_r = &forks[(i + 1) % n];
		philos[i].eat_times = eat_times;
		philos[i].last_eat_time = start_time;
		philos[i].start_time = start_time;
	}
	return (philos);
}

//	maybe move start time mark later
void				get_info(char **av, t_info *info)
{
	struct timeval	start_t;

	info->n_phil = ft_atoi(av[1]);
	info->t_die = ft_atoi(av[2]);
	info->t_eat = ft_atoi(av[3]);
	info->t_sleep = ft_atoi(av[4]), av[5] ? ft_atoi(av[5]) : -1;
//	do I really need timestamp here?
//	need consultation here
	while (gettimeofday(&start_t, NULL))
		;
	info->start_time = start_t.tv_sec * 1000 + start_t.tv_usec / 1000;
}

void 				*life_cycle(void *data)
{
	struct timeval	mark_t;
	t_philo			*philo;
	int 			time;
	char			*str;
	philo = (t_philo *)data;

	if (gettimeofday(&mark_t, NULL))
		;
	philo->start_time = mark_t.tv_sec * 1000 + mark_t.tv_usec / 1000;
	philo->last_eat_time = mark_t.tv_sec * 1000 + mark_t.tv_usec / 1000;
	while (1)
	{
		pthread_mutex_lock(philo->waiter);
		pthread_mutex_lock(philo->fork_l);
		pthread_mutex_lock(philo->fork_r);
		pthread_mutex_unlock(philo->waiter);
//		take a fork
//		is this status about one fork or two forks?
		if (gettimeofday(&mark_t, NULL))
			;
		time = (int)(philo->start_time - (mark_t.tv_sec * 1000 + mark_t.tv_usec / 1000));
		if (!(str = ft_itoa(time)))
			return (NULL);
		ft_putstr_fd(str, 1);
		write(1, " ", 1);
		if (!(str = ft_itoa(philo->id)))
			return (NULL);
		ft_putstr_fd(str, 1);
		ft_putstr_fd(" has taken a fork\n", 1);
//		eating
		if (!(str = ft_itoa(time)))
			return (NULL);
		ft_putstr_fd(str, 1);
		write(1, " ", 1);
		if (!(str = ft_itoa(philo->id)))
			return (NULL);
		ft_putstr_fd(str, 1);
		ft_putstr_fd(" is eating\n", 1);
		usleep(philo->t_eat);
		pthread_mutex_unlock(philo->fork_l);
		pthread_mutex_unlock(philo->fork_r);
//		sleeping
		if (gettimeofday(&mark_t, NULL))
			;
		time = (int)(philo->start_time - (mark_t.tv_sec * 1000 + mark_t.tv_usec / 1000));
		if (!(str = ft_itoa(time)))
			return (NULL);
		ft_putstr_fd(str, 1);
		write(1, " ", 1);
		if (!(str = ft_itoa(philo->id)))
			return (NULL);
		ft_putstr_fd(str, 1);
		ft_putstr_fd(" is sleeping\n", 1);
		usleep(philo->t_sleep);
//		thinking
		if (gettimeofday(&mark_t, NULL))
			;
		time = (int)(philo->start_time - (mark_t.tv_sec * 1000 + mark_t.tv_usec / 1000));
		if (!(str = ft_itoa(time)))
			return (NULL);
		ft_putstr_fd(str, 1);
		write(1, " ", 1);
		if (!(str = ft_itoa(philo->id)))
			return (NULL);
		ft_putstr_fd(str, 1);
		ft_putstr_fd(" is thinking\n", 1);
	}
	return (NULL);
}

int 				main(int ac, char **av)
{
	t_info			info[1];
	t_philo			*philos;

	get_info(av, info);
	if (ac < 5 || ac > 6 ||
	!(philos = init_philos(info->n_phil, info->start_time, info->eat_times)))
		return (-1);
	philos->t_die = info->t_die;
	philos->t_eat = info->t_eat;
	philos->t_sleep = info->t_sleep;
	simulation();
	return (0);
}
