/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlx_mat.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:15:08 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/19 17:01:00 by gd-harco         ###   ########lyon.fr   */
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
#ifndef NLX_MAT_H
# define NLX_MAT_H

# include "nlx_vec.h"
# include "nlx_win.h"
# include <stdbool.h>
# include <math.h>

//-----------------STRUCTURES-----------------//

/**

 *
 * @brief A 4x4 matrix of float to use for 3D normalisation
 *
 * @ingroup matrix
 */
typedef struct s_matrix
{
	float	m[4][4];
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

enum e_proj
{
	ISO,
	PERSP
};

typedef struct s_proj_info
{
	t_matrix	*iso_m;
	t_matrix	*persp_m;
	t_matrix	*current_m;
	float		z_near;
	float		z_far;
	float		fov;
	float		aspect_ratio;
	float		fov_rad;
}				t_proj_info;

typedef struct s_trans_info
{
	float		translate_x;
	float		translate_y;
	float		translate_z;
	t_matrix	*m;
}				t_trans_info;

typedef struct s_rot_info
{
	float		rot_x;
	float		rot_y;
	float		rot_z;
	t_matrix	*x_rot_m;
	t_matrix	*y_rot_m;
	t_matrix	*z_rot_m;
}				t_rot_info;

typedef struct s_world_i {
	bool			key_is_pressed;
	int				key_pressed;
	enum e_proj		proj_type;
	t_matrix		*world_m;
	t_rot_info		*rot;
	t_trans_info	*trans;
	t_proj_info		*proj;
}			t_world_i;

//-----------------FUNCTIONS-----------------//
t_matrix	*create_identity_matrix(void);
t_matrix	*get_x_rotation_matrix(float angle);
t_matrix	*get_y_rotation_matrix(float angle);
t_matrix	*get_z_rotation_matrix(float angle);
t_matrix	*get_persp_matrix(t_proj_info *data);
t_matrix	*get_iso_matrix(float iso_factor);
t_matrix	*get_translation_matrix(t_trans_info *trans);
t_matrix	multiply_matrix_matrix(t_matrix *m1, t_matrix *m2);
void		multiply_vector_matrix(
				t_matrix *m, t_vec3d *source_vec, t_vec3d *result_vec);
t_matrix	*get_world_matrix(t_world_i *world);
#endif
