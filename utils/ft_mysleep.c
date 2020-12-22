/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mysleep.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadolph <sadolph@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 20:10:03 by sadolph           #+#    #+#             */
/*   Updated: 2020/12/21 20:46:04 by sadolph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_mysleep(long sleep)
{
	struct timeval	mark_t;
	long			finish;
	long			current;

	if (gettimeofday(&mark_t, NULL))
		return ;
	finish = mark_t.tv_sec * 1000000 + mark_t.tv_usec + sleep;
	current = 0;
	while (current < finish)
	{
		usleep(500);
		if (gettimeofday(&mark_t, NULL))
			return ;
		current = mark_t.tv_sec * 1000000 + mark_t.tv_usec;
	}
}
