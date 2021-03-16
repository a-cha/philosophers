#include <__wctype.h>
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadolph <sadolph@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 18:08:59 by sadolph           #+#    #+#             */
/*   Updated: 2021/01/15 17:36:54 by sadolph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
#include "utils.h"

static int	ft_putstr_str(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (*s2)
	{
		*s1++ = *s2++;
		++i;
	}
	return (i);
}

static int	ft_putnbr_str(long n, char *str)
{
	long	num;
	int 	len;
	int 	div;

	num = n;
	len = 1;
	div = 10;
	while (num /= 10)
	{
		len++;
		div *= 10;
	}
	while (div /= 10)
		*str++ = n / div % 10 + 48;
	return (len);
}

void		ft_print_status(int id, long start_time, char *msg)
{
	char	status[40];
	int 	i;

	i = ft_putnbr_str((ft_get_time() - start_time) / 1000, status);
	status[i++] = ' ';
	i += ft_putnbr_str(id, status + i);
	i += ft_putstr_str(status + i, msg);
	status[i] = '\0';
	write(1, status, i);
}
