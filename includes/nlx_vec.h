/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlx_vec.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:03:31 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/22 16:55:26 by gd-harco         ###   ########lyon.fr   */
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
# include <stdbool.h>

//-----------------STRUCTURES-----------------//

/**
 * @brief Structure representing a 3D vector
 * @ingroup vector
 * @details This structure is used to represent a 3D vector
 * @param x x coordinate of the vector
 * @param y y coordinate of the vector
 * @param z z coordinate of the vector
 * @param initial_z initial z coordinate of the vector
 * @param w w coordinate of the vector, used to set the next parameters
 * @param is_behind_camera boolean to know if the vector is behind the camera
 */
typedef struct s_vec3d
{
	float	x;
	float	y;
	float	z;
	float	initial_z;
	float	w;
	bool	is_behind_camera;
}				t_vec3d;

#endif
