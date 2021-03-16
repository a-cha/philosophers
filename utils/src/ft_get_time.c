/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadolph <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:26:37 by sadolph           #+#    #+#             */
/*   Updated: 2021/03/16 14:26:40 by sadolph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include "errors.h"

long				ft_get_time(void)
{
	struct timeval	mark_t;

	if (gettimeofday(&mark_t, NULL))
		return (ERR_GETTIME);
	return (mark_t.tv_sec * 1000000 + mark_t.tv_usec);
}
