/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlx_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:54:50 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/06 14:56:21 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlx_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:01:04 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/05 13:15:11 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file nlx_matrix.c
 *
 * @brief file containing every function related to matrices in nlx
 *
 * @author gd-harco
 * @date 2023-04-03
 */
#include "nlx_matrix.h"


/**
 * @brief Create a identity matrix object
 * @details this function creates a 4x4 identity matrix
 * @return t_matrix* the identity matrix allocated on the heap. Must be freed
 * if the allocation fails, the function returns NULL
 */
t_matrix	*create_identity_matrix(void)
{
	int	row;
	int	col;
	t_matrix	*returned_m;

	returned_m = malloc(sizeof(t_matrix));
	if (!returned_m)
		return (NULL);
	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			if (row == col)
				returned_m->m[row][col] = 1.0f;
			else
				returned_m->m[row][col] = 0.0f;
			col++;
		}
		row++;
	}
	return (returned_m);
}

/**
 * @brief Get the projection matrix object
 * @details this function returns a projection matrix
 * based on the information about the projection passed in parameter
 * @param data structure containing the data needed to create the matrix
 * @return t_matrix the projection matrix allocated on the heap. Must be freed
 */
t_matrix	*get_projection_matrix(t_proj_info *data)
{
	t_matrix	*proj_matrix;

	proj_matrix = create_identity_matrix();
	proj_matrix->m[0][0] = data->aspect_ratio * data->fov_rad;
	proj_matrix->m[1][1] = data->fov_rad;
	proj_matrix->m[2][2] = data->z_far / (data->z_far - data->z_near);
	proj_matrix->m[3][2] = (-data->z_far * data->z_near)
		/ (data->z_far - data->z_near);
	return (proj_matrix);
}

/**
 * @brief Get the translation matrix object
 * @details this function returns a translation matrix
 * based on the information about the translation passed in parameter
 * @param data structure containing the data needed to create the matrix
 * @return t_matrix the translation matrix allocated on the heap. Must be freed
 */
t_matrix	*get_translation_matrix(t_translation_info *data)
{
	t_matrix	*translation_matrix;

	translation_matrix = create_identity_matrix();
	translation_matrix->m[3][0] = data->translate_x;
	translation_matrix->m[3][1] = data->translate_y;
	translation_matrix->m[3][2] = data->translate_z;
	return (translation_matrix);
}

/**
 * @brief Multiply a matrix by a vector
 * @details this function multiplies a matrix by a vector,
 * returning a vector that can be used to draw a point on the screen
 * @param m matrix to multiply
 * @param s_vec vector to multiply
 * @param r_vec vector containing the result of the multiplication
 */
void	multiply_vector_matrix(t_matrix *m, t_vec3d *s_vec, t_vec3d *r_vec)
{
	float	w;

	r_vec->x = s_vec->x * m->m[0][0] + s_vec->y * m->m[1][0]
		+ s_vec->z * m->m[2][0] + m->m[3][0];
	r_vec->y = s_vec->x * m->m[0][1] + s_vec->y * m->m[1][1]
		+ s_vec->z * m->m[2][1] + m->m[3][1];
	r_vec->z = s_vec->x * m->m[0][2] + s_vec->y * m->m[1][2]
		+ s_vec->z * m->m[2][2] + m->m[3][2];
	w = s_vec->x * m->m[0][3] + s_vec->y * m->m[1][3]
		+ s_vec->z * m->m[2][3] + m->m[3][3];
	if (w != 0.0f)
	{
		r_vec->x /= w;
		r_vec->y /= w;
		r_vec->z /= w;
	}
}
