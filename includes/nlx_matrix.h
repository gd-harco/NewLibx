/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlx_matrix.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:15:08 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/03 22:07:14 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file nlx_matrix.h
 *
 * @brief Header file for the matrix module of the nlx library
 *
 * @ingroup matrix
 * @author gd-harco
 * @date 2023/03/26
 */
#ifndef NLX_MATRIX_H
# define NLX_MATRIX_H

# include "nlx_vec.h"
# include <math.h>

//-----------------STRUCTURES-----------------//

/**

 *
 * @brief A 4x4 matrix of double to use for 3D normalisation
 *
 * @ingroup matrix
 */
typedef struct s_matrix
{
	double	m[4][4];
}				t_matrix;

/**
 * @struct s_proj_m
 * @brief Structure containing the data needed
 * to create a projection matrix, and the matrix itself
 * @ingroup matrix
 * @param m The projection matrix created with the data
 * @param z_near The near clipping plane. Must be provided
 * @param z_far The far clipping plane. Must be provided
 * @param fov The field of view. Must be provided
 * @param aspect_ratio The aspect ratio of the screen.
 * Determined by the function that creates the matrix
 */
typedef struct s_proj_m
{
	t_matrix	m;
	double		z_near;
	double		z_far;
	double		fov;
	double		aspect_ratio;
}	t_proj_m;

//-----------------FUNCTIONS-----------------//

void		create_identity_matrix(t_matrix *m);
t_matrix	get_projection_matrix(t_proj_m *data);
t_vec3d		multiply_vector_matrix(t_matrix m, t_vec3d *v);

#endif
