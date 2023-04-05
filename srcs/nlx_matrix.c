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
#include <math.h>

/**
 * @brief Create a identity matrix object
 * @details this function initialize the matrix
 * passed in parameter as an identity matrix
 * @param m matrix to transform into an identity matrix. Must has been allocated
 */
void	create_identity_matrix(t_matrix *m)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i == j)
				m->m[i][j] = 1;
			else
				m->m[i][j] = 0;
			j++;
		}
		i++;
	}
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
	if (!proj_matrix)
		return (NULL);
	create_identity_matrix(proj_matrix);
	proj_matrix->m[0][0] = data->aspect_ratio * (1 / (tan(data->fov / 2)));
	proj_matrix->m[1][1] = 1 / (tan(data->fov / 2));
	proj_matrix->m[2][2] = data->z_far / (data->z_far - data->z_near);
	proj_matrix->m[3][2] = (-data->z_far * data->z_near)
		/ (data->z_far - data->z_near);
	proj_matrix->m[2][3] = 1;
	return (proj_matrix);
}

/**
 * @brief Multiply a matrix by a vector
 * @details this function multiplies a matrix by a vector,
 * returning a vector that can be used to draw a point on the screen
 * @param m matrix to multiply
 * @param source_vec vector to multiply
 * @param result_vec vector containing the result of the multiplication
 */
void multiply_vector_matrix(t_matrix *m, t_vec3d *source_vec, t_vec3d *result_vec)
{
	float 	w;

	result_vec->x = source_vec->x * m->m[0][0] + source_vec->y * m->m[1][0]
			  + source_vec->z * m->m[2][0] + m->m[3][0];
	result_vec->y = source_vec->x * m->m[0][1] + source_vec->y * m->m[1][1]
			  + source_vec->z * m->m[2][1] + m->m[3][1];
	result_vec->z = source_vec->x * m->m[0][2] + source_vec->y * m->m[1][2]
			  + source_vec->z * m->m[2][2] + m->m[3][2];
	w = source_vec->x * m->m[0][3] + source_vec->y * m->m[1][3]
		+ source_vec->z * m->m[2][3] + m->m[3][3];
	if (w != 0)
	{
		result_vec->x /= w;
		result_vec->y /= w;
		result_vec->z /= w;
	}
}
