/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mysleep.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadolph <sadolph@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 20:10:03 by sadolph           #+#    #+#             */
/*   Updated: 2021/01/15 15:49:04 by sadolph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <sys/time.h>
# include <unistd.h>

void				ft_mysleep(int sleep)
{
	struct timeval	mark_t;
	unsigned int	finish;
	unsigned int	current;

	if (gettimeofday(&mark_t, NULL))
		return ;
	finish = (int)mark_t.tv_sec * 1000000 + mark_t.tv_usec + sleep * 1000;
	current = 0;
	while (current < finish)
	{
		if ((usleep(20)))
			return ;
		if (gettimeofday(&mark_t, NULL))
			return ;
		current = (unsigned int)mark_t.tv_sec * 1000000 + mark_t.tv_usec;
	}
}
