/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlx_vec.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:03:31 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/03 18:19:51 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file nlx_vec.h
 *
 * @brief Header file for the vector module of the nlx library
 *
 * @ingroup vector
 * @author gd-harco
 * @date 2023/03/28
 */
#ifndef NLX_VEC_H
# define NLX_VEC_H
# include <stdlib.h>

//-----------------STRUCTURES-----------------//

typedef struct s_vec3d
{
	double	x;
	double	y;
	double	z;
}				t_vec3d;

#endif
