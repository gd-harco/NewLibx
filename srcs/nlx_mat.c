/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlx_mat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:54:50 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/18 17:58:58 by gd-harco         ###   ########lyon.fr   */
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
#include "nlx_win.h"

/**
 * @brief Create an identity matrix object.
 * @details this function creates a 4x4 identity matrix.
 * @allocated_on Heap (must be freed)
 * @return t_matrix* the identity matrix. \n
 * If the allocation fails, the function returns NULL
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
 * @brief Get the projection matrix object.
 * @details this function returns a projection matrix \n
 * based on the information about the projection passed in parameter.
 * @param data structure containing the data needed to create the matrix.
 * @allocated_on Heap (must be freed)
 * @return t_matrix the projection matrix.
 */
t_matrix	*get_persp_matrix(t_proj_info *data)
{
	t_matrix	*proj_matrix;
	int			row;
	int			col;

	proj_matrix = malloc(sizeof(t_matrix));
	if (!proj_matrix)
		return (NULL);
	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			proj_matrix->m[row][col] = 0.0f;
			col++;
		}
		row++;
	}
	proj_matrix->m[0][0] = data->aspect_ratio * data->fov_rad;
	proj_matrix->m[1][1] = data->fov_rad;
	proj_matrix->m[2][2] = data->z_far / (data->z_far - data->z_near);
	proj_matrix->m[3][2] = -proj_matrix->m[2][2] * data->z_near;
	proj_matrix->m[2][3] = 1.0f;
	return (proj_matrix);
}

t_matrix	*get_iso_matrix(t_proj_info *data, t_win *win)
{
	t_matrix	*proj_matrix;

	proj_matrix = create_identity_matrix();
	if (!proj_matrix)
		return (NULL);
	proj_matrix->m[0][0] = win->width / 2;
	proj_matrix->m[0][3] = proj_matrix->m[0][0];
	proj_matrix->m[1][1] = -win->height / 2;
	proj_matrix->m[1][3] = -proj_matrix->m[1][1];
	proj_matrix->m[2][2] = (data->z_far - data->z_near) / -2;
	proj_matrix->m[2][3] = (data->z_far + data->z_near) / 2;
	return (proj_matrix);
}
