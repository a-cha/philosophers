//
// Created by Skipjack Adolph on 12/20/20.
//

#ifndef PHILOSOPHERS_UTILS_H
#define PHILOSOPHERS_UTILS_H

#include <unistd.h>
#include <stdlib.h>

int		ft_atoi(const char *str);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd);

#endif //PHILOSOPHERS_UTILS_H
