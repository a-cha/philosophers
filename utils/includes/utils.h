/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadolph <sadolph@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 15:50:52 by sadolph           #+#    #+#             */
/*   Updated: 2020/12/24 14:10:45 by sadolph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

int		ft_atoi(const char *str);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *str);
void	ft_putstr(char *s);
int		ft_putnbr_str(int n, char *str);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_mysleep(int sleep);

#endif
