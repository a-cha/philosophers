/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadolph <sadolph@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 19:20:18 by sadolph           #+#    #+#             */
/*   Updated: 2021/01/15 16:44:49 by sadolph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_STATUS_H
# define PRINT_STATUS_H

# define MSG_TAKEN_FORK " has taken a fork\n"
# define MSG_EATING "\e[0;32m is eating\033[0m\n"
# define MSG_THINKING " is thinking\n"
# define MSG_SLEEPING " is sleeping\n"
# define MSG_DIED "\033[31m is died\033[0m\n"

void				ft_print_status(int id, unsigned int start_time, char *msg);

#endif //PRINT_STATUS_H
