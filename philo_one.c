
#include "philo_one.h"

t_info				*get_info(char **av)
{
	t_info			*info;

	if ((info = (t_info *)malloc(sizeof(t_info))))
	{
		info->n_phil = ft_atoi(av[1]);
		info->t_die = ft_atoi(av[2]);
		info->t_eat = ft_atoi(av[3]);
		info->t_sleep = ft_atoi(av[4]);
		info->eat_times = av[5] ? ft_atoi(av[5]) : -1;
	}
	return (info);
}

t_philo				**init_mutex(int n, long start_time)
{
	t_philo			**philos;
	int				i;

	if ((philos = (t_philo **)malloc(sizeof(t_philo *) * (n + 1))))
	{
		i = -1;
		while (++i < n)
		{
			if (!(philos[i] = (t_philo *)malloc(sizeof(t_philo))))
				return (NULL);
			philos[i]->mut = i + 1;
			philos[i]->t_last_eat = start_time;
		}
		philos[n] = NULL;
	}
	return (philos);
}

int 	main(int ac, char **av)
{
	t_info			*info;
	t_philo			**philos;
	struct timeval	start_t;
	struct timeval	end_t;
	long 			curr_time;

	if (ac < 5 || ac > 6 || gettimeofday(&start_t, NULL))
		return (-1);
	info = &(t_info){ft_atoi(av[1]), ft_atoi(av[2]), ft_atoi(av[3]),
	ft_atoi(av[4]), av[5] ? ft_atoi(av[5]) : -1,
	start_t.tv_sec * 1000 + start_t.tv_usec / 1000};
	if (!(philos = init_mutex(info->n_phil, info->start_time)))
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
