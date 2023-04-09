/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlx_mat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:54:50 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/09 16:35:59 by gd-harco         ###   ########lyon.fr   */
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

	proj_matrix = malloc(sizeof(t_matrix));
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			proj_matrix->m[i][j] = 0.0f;
	proj_matrix->m[0][0] = data->aspect_ratio * data->fov_rad;
	proj_matrix->m[1][1] = data->fov_rad;
	proj_matrix->m[2][2] = data->z_far / (data->z_far - data->z_near);
	proj_matrix->m[3][2] = -proj_matrix->m[2][2] * data->z_near;
	proj_matrix->m[2][3] = 1.0f;
	return (proj_matrix);
}
