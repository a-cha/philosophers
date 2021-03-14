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

# include <unistd.h>
#include "utils.h"

void				ft_mysleep(int sleep)
{
	unsigned int	finish;
	unsigned int	current;

	finish = ft_get_time() + sleep * 1000;
	current = 0;
	while (current < finish)
	{
		if ((usleep(50)))
			return ;
		current = ft_get_time();
	}
}
