//
// Created by Skipjack Adolph on 12/20/20.
//

#include "utils.h"

size_t		ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
