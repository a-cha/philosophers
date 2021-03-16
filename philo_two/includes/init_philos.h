/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadolph <sadolph@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 15:45:38 by sadolph           #+#    #+#             */
/*   Updated: 2021/01/15 14:15:55 by sadolph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_INIT_PHILOS_H
# define PHILOSOPHERS_INIT_PHILOS_H

static int			init_table(t_table **table, char **av);
static int			init_forks(pthread_mutex_t **forks, int n);
static int			init_mutex(pthread_mutex_t **mutex);

#endif
