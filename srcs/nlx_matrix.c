/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlx_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:01:04 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/04 15:18:18 by gd-harco         ###   ########lyon.fr   */
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
 * @details this function transform the 4x4 identity matrix
 * passed in parameter into an identity matrix
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
 * @return t_matrix the projection matrix allocated on the stack
 * @todo check with vfries if better to allocate on the heap
 */
t_matrix	get_projection_matrix(t_proj_info *data)
{
	t_matrix	proj_matrix;

	create_identity_matrix(&proj_matrix);
	proj_matrix.m[0][0] = data->aspect_ratio * (1 / (tan(data->fov / 2)));
	proj_matrix.m[1][1] = 1 / (tan(data->fov / 2));
	proj_matrix.m[2][2] = data->z_far / (data->z_far - data->z_near);
	proj_matrix.m[3][2] = (-data->z_far * data->z_near)
		/ (data->z_far - data->z_near);
	proj_matrix.m[2][3] = 1;
	return (proj_matrix);
}

/**
 * @brief Multiply a matrix by a vector
 * @details this function multiplies a matrix by a vector,
 * returning a vector that can be used to draw a point on the screen
 * @param m matrix to multiply
 * @param v vector to multiply
 * @return t_vec3d the vector resulting of the multiplication,
 * allocated on the heap
 */
t_vec3d	multiply_vector_matrix(t_matrix m, t_vec3d *v)
{
	t_vec3d	*new_v;
	float	w;

	//TODO secure malloc
	new_v = malloc(sizeof(t_vec3d));
	new_v->x = v->x * m.m[0][0] + v->y * m.m[1][0]
		+ v->z * m.m[2][0] + m.m[3][0];
	new_v->y = v->x * m.m[0][1] + v->y * m.m[1][1]
		+ v->z * m.m[2][1] + m.m[3][1];
	new_v->z = v->x * m.m[0][2] + v->y * m.m[1][2]
		+ v->z * m.m[2][2] + m.m[3][2];
	w = v->x * m.m[0][3] + v->y * m.m[1][3]
		+ v->z * m.m[2][3] + m.m[3][3];
	if (w != 0)
	{
		new_v->x /= w;
		new_v->y /= w;
		new_v->z /= w;
	}
	return (*new_v);
}
