/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadolph <sadolph@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 17:26:52 by sadolph           #+#    #+#             */
/*   Updated: 2021/01/11 18:14:11 by sadolph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int				i;
	int				s;
	unsigned int	prev;
	int				res;

	i = 0;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	s = i - 1;
	while (str[i] >= 48 && str[i] <= 57)
	{
		prev = (unsigned int)res;
		res = res * 10 + (str[i++] - '0');
		if (i - s > 20 && prev > (unsigned int)res)
			return (str[s] == '-' ? 0 : -1);
	}
	if (str[s] == '-')
		res *= -1;
	return (res);
}
