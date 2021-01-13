/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mysleep.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadolph <sadolph@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 20:10:03 by sadolph           #+#    #+#             */
/*   Updated: 2021/01/13 16:46:20 by sadolph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_mysleep(int sleep)
{
	struct timeval	mark_t;
	size_t			finish;
	size_t			current;

	if (gettimeofday(&mark_t, NULL))
		return ;
	finish = (size_t)(mark_t.tv_sec * 1000000 + mark_t.tv_usec + sleep);
	current = 0;
	while (current < finish)
	{
		usleep(20);
		if (gettimeofday(&mark_t, NULL))
			return ;
		current = (size_t)(mark_t.tv_sec * 1000000 + mark_t.tv_usec);
	}
}
