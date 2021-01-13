/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadolph <sadolph@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 20:03:22 by sadolph           #+#    #+#             */
/*   Updated: 2021/01/13 15:14:51 by sadolph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
