/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlx_vec.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:03:31 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/04 15:29:42 by gd-harco         ###   ########lyon.fr   */
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

/**
 * @brief Structure representing a 3D vector
 * @ingroup vector
 * @details This structure is used to represent a 3D vector
 * @param x x coordinate of the vector
 * @param y y coordinate of the vector
 * @param z z coordinate of the vector
 */
typedef struct s_vec3d
{
	double	x;
	double	y;
	double	z;
}				t_vec3d;

#endif
