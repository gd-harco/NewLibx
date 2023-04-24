/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlx_mat_rot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:05:03 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/24 12:02:31 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file nlx_mat_rot.c
 *
 * @brief file containing every function related to rotation matrix in nlx
 *
 * @author gd-harco
 * @date 2023-04-03
 * @version 1.0
 */

#include "nlx_mat.h"

/**
 * @brief Create a rotation matrix object for the x axis.
 * @param angle The angle to rotate by.
 * @allocated_on Heap (must be freed)
 * @return t_matrix* The rotation matrix created.
 */
t_matrix	*get_x_rotation_matrix(float angle)
{
	t_matrix	*rot_matrix;

	rot_matrix = create_identity_matrix();
	if (!rot_matrix)
		return (NULL);
	rot_matrix->m[1][1] = cosf(angle * 0.5f);
	rot_matrix->m[1][2] = sinf(angle * 0.5f);
	rot_matrix->m[2][1] = -sinf(angle * 0.5f);
	rot_matrix->m[2][2] = rot_matrix->m[1][1];
	return (rot_matrix);
}

/**
 * @brief Create a rotation matrix object for the y axis.
 * @param angle The angle to rotate by.
 * @allocated_on Heap (must be freed)
 * @return t_matrix* The rotation matrix created.
 */
t_matrix	*get_y_rotation_matrix(float angle)
{
	t_matrix	*rot_matrix;

	rot_matrix = create_identity_matrix();
	if (!rot_matrix)
		return (NULL);
	rot_matrix->m[0][0] = cosf(angle);
	rot_matrix->m[0][2] = sinf(angle);
	rot_matrix->m[2][0] = -rot_matrix->m[0][2];
	rot_matrix->m[2][2] = rot_matrix->m[0][0];
	return (rot_matrix);
}

/**
 * @brief Create a rotation matrix object for the z axis.
 * @param angle The angle to rotate by.
 * @allocated_on Heap (must be freed)
 * @return t_matrix* The rotation matrix created.
 */
t_matrix	*get_z_rotation_matrix(float angle)
{
	t_matrix	*rot_matrix;

	rot_matrix = create_identity_matrix();
	if (!rot_matrix)
		return (NULL);
	rot_matrix->m[0][0] = cosf(angle);
	rot_matrix->m[0][1] = sinf(angle);
	rot_matrix->m[1][0] = -rot_matrix->m[0][1];
	rot_matrix->m[1][1] = rot_matrix->m[0][0];
	return (rot_matrix);
}
