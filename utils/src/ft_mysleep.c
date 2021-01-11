/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mysleep.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadolph <sadolph@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 20:10:03 by sadolph           #+#    #+#             */
/*   Updated: 2020/12/24 15:28:06 by sadolph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_mysleep(int sleep)
{
	struct timeval	mark_t;
	int				finish;
	int				current;

	if (gettimeofday(&mark_t, NULL))
		return ;
	finish = (int)(mark_t.tv_sec % 1000 * 1000000 + mark_t.tv_usec + sleep);
	current = 0;
	while (current < finish)
	{
		usleep(10);
		if (gettimeofday(&mark_t, NULL))
			return ;
		current = (int)(mark_t.tv_sec % 1000 * 1000000 + mark_t.tv_usec);
	}
}
