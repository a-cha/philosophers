//
// Created by Skipjack Adolph on 12/20/20.
//

#include "utils.h"

static int	ft_numlen(int n, int base)
{
	int		i;

	i = 1;
	if (n < 0)
		n++;
	while (n /= base)
		i++;
	return (i);
}

char		*ft_itoa(int n)
{
	int		len;
	char	*res;

	len = ft_numlen(n, 10);
	if (!(res = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	res[len] = '\0';
	if (n == 0)
		res[0] = '0';
	else if (n < 0)
		res[0] = '-';
	while (n)
	{
		if (n < 0)
			res[--len] = (n % 10) * -1 + '0';
		else
			res[--len] = n % 10 + '0';
		n /= 10;
	}
	return (res);
}
