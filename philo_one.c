
#include "philo_one.h"

void				init_forks(int n, pthread_mutex_t *forks)
{
	int				i;

	i = -1;
	while (++i < n)
		pthread_mutex_init(&forks[i], NULL);
}

void				init_philos(int n, t_philo *philos, char **av)
{
	pthread_mutex_t forks[n];
	pthread_mutex_t	waiter[1];
	int				i;

	init_forks(n, forks);
	pthread_mutex_init(waiter, NULL);
	i = -1;
	while (++i < n)
	{
		philos[i].id = i + 1;
		philos[i].waiter = waiter;
		philos[i].fork_l = &forks[i];
		philos[i].fork_r = &forks[(i + 1) % n];
		philos[i].t_die = ft_atoi(av[2]);
		philos[i].t_eat = ft_atoi(av[3]);
		philos[i].t_sleep = ft_atoi(av[4]);
		philos[i].eat_times = av[5] ? ft_atoi(av[5]) : -1;
	}
}

int					main(int ac, char **av)
{
	int				n_philos;
	t_philo			philos[av[1] ? ft_atoi(av[1]) : 0];

	if (ac < 5 || ac > 6)
		return (-1);
	n_philos = ft_atoi(av[1]);
	init_philos(n_philos, philos, av);
//	simulation();
	return (0);
}
