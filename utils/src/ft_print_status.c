/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadolph <sadolph@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 18:08:59 by sadolph           #+#    #+#             */
/*   Updated: 2021/01/14 19:38:00 by sadolph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <sys/time.h>

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

int			ft_putnbr_str(int n, char *str)
{
	int		num;
	int 	ret;
	int 	div;

	num = n;
	ret = 1;
	div = 10;
	while (num /= 10)
	{
		ret++;
		div *= 10;
	}
	while (div /= 10)
		*str++ = n / div % 10 + 48;
	return (ret);
}

void				ft_print_status(int id, long start_time, char *msg)
{
	struct timeval	mark_t;
	char 			status[30];
	int 			i;

	if (gettimeofday(&mark_t, NULL))
		return ;
	i = ft_putnbr_str((int)mark_t.tv_sec * 1000 + mark_t.tv_usec / 1000
							- (int)start_time / 1000, status);
	status[i++] = ' ';
	i += ft_putnbr_str(id, status + i);
	i += ft_putstr_str(status + i, msg);
	status[i] = '\0';
	write(1, status, i);
}
