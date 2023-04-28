/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlx_mat.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:15:08 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/28 18:13:08 by gd-harco         ###   ########lyon.fr   */
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
 * @version 1.2
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
 * @details This structure is used to represent a 4x4 matrix of float
 * @param m The matrix itself
 */
typedef struct s_matrix
{
	float	m[4][4];
}				t_matrix;

/**
 * @brief Enum containing the different types of projection
 *
 * @param ISO Isometric projection (default)
 * @param PERSP Perspective projection
 */
enum e_proj
{
	ISO = 0,
	PERSP
};

/**
 * @brief Enum containing the different types of render
 *
 * @param LINE Lines are fully drawn (default)
 * @param Point Only start and end points are drawn
 */
enum e_render
{
	LINE = 0,
	POINT
};

/**
 * @struct s_proj_info
 *
 * @brief Structure containing the data needed
 * to create a projection matrix, and the matrix itself

 * @param iso_m The matrix used for the isometric projection
 * @param persp_m The matrix used for the perspective projection
 * @param current_m The matrix currently used for the projection
 * @param z_near The near clipping plane. Must be provided
 * @param z_far The far clipping plane. Must be provided
 * @param fov The field of view. Must be provided
 * @param aspect_ratio The aspect ratio of the screen.
 * Determined by the function that creates the matrix
 * @param fov_rad The field of view in radians
 */
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

/**
 * @brief Structure containing all data about the translation of the world
 *
 * @param translate_x The translation value on the x axis
 * @param translate_y The translation value on the y axis
 * @param translate_z The translation value on the z axis
 * @param m The translation matrix
 */
typedef struct s_trans_info
{
	float		translate_x;
	float		translate_y;
	float		translate_z;
	t_matrix	*m;
}				t_trans_info;

/**
 * @brief Structure containing all data about the rotation of the world
 *
 * @param rot_x The rotation value on the x axis
 * @param rot_y The rotation value on the y axis
 * @param rot_z The rotation value on the z axis
 * @param x_rot_m The rotation matrix on the x axis
 * @param y_rot_m The rotation matrix on the y axis
 * @param z_rot_m The rotation matrix on the z axis
 */
typedef struct s_rot_info
{
	float		rot_x;
	float		rot_y;
	float		rot_z;
	t_matrix	*x_rot_m;
	t_matrix	*y_rot_m;
	t_matrix	*z_rot_m;
}				t_rot_info;

/**
 * @brief Structure containing all data about the world
 *
 * @param key_is_pressed Boolean to know if a key is pressed
 * @param key_pressed The key that is pressed
 * @param proj_type The projection type currently used
 * @param render_type The render type currently used
 * @param world_m The world matrix
 * @param rot The rotation info of the world
 * @param trans The translation info of the world
 * @param proj The projection info of the world
 */
typedef struct s_world_i {
	bool			key_is_pressed;
	int				key_pressed;
	enum e_proj		proj_type;
	enum e_render	render_type;
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
