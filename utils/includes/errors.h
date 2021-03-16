/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadolph <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:25:37 by sadolph           #+#    #+#             */
/*   Updated: 2021/03/16 14:25:41 by sadolph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_ERRORS_H
# define PHILOSOPHERS_ERRORS_H

enum	e_errors
{
	ERR_MALLOC = -6,
	ERR_GETTIME,
	ERR_PTHREAD,
	ERR_USLEEP,
	ERR_ARGS
};

#endif
