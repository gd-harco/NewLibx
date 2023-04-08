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

/**
 * @file nlx_matrix.c
 *
 * @brief file containing every function related to matrices in nlx
 *
 * @author gd-harco
 * @date 2023-04-03
 */
#include "nlx_mat.h"

/**
 * @brief Create a identity matrix object
 * @details this function creates a 4x4 identity matrix
 * @return t_matrix* the identity matrix allocated on the heap. Must be freed
 * if the allocation fails, the function returns NULL
 */
t_matrix	*create_identity_matrix(void)
{
	int			row;
	int			col;
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
