/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadolph <sadolph@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 20:03:22 by sadolph           #+#    #+#             */
/*   Updated: 2021/01/12 16:50:43 by sadolph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_numlen(int n)
{
	int i;

	i = 1;
	if (n < 0)
		i++;
	while (n /= 10)
		i++;
	return (i);
}

static int	ft_divider(int n)
{
	int i;

	i = 1;
	if (n < 0)
		n++;
	while (n /= 10)
		i *= 10;
	return (i);
}

static int	some_cases(int n, char *str)
{
	char 	*min_int;

	if (n == 0)
	{
		*str = '0';
		return (0);
	}
	min_int = "-2147483648";
	if (n == -2147483648)
	{
		while (*min_int)
			*str++ = *min_int++;
		return (0);
	}
	if (n < 0)
		*str = '-';
	return (n);
}

int			ft_putnbr_str(int n, char *str)
{
	int		div;
	int 	ret;

	ret = ft_numlen(n);
	if (!(n = some_cases(n, str)))
		return (ret);
	if (n < 0)
	{
		str++;
		n *= -1;
	}
	div = ft_divider(n);
	while (n)
	{
		*str++ = n / div + 48;
		n %= div;
		div /= 10;
	}
	while (div)
	{
		*str++ = '0';
		div /= 10;
	}
	return (ret);
}
