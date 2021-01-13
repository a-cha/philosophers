/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadolph <sadolph@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 20:03:22 by sadolph           #+#    #+#             */
/*   Updated: 2021/01/11 18:16:19 by sadolph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

int		ft_putstr_str(char *s1, char *s2)
{
	int i;

	i = 0;
	while (*s2)
	{
		*s1++ = *s2++;
		++i;
	}
	return (i);
}
