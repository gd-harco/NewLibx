/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlx_mat_world.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:19:43 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/22 16:19:44 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "nlx_mat.h"

/**
 * @brief Create the world matrix
 * @details The world matrix is the product of
 * the rotation matrices and the translation matrix.\n
 * This is the matrix that will be used to transform the vector map.
 * @param rot_z the rotation matrix for the z axis.
 * @param rot_x the rotation matrix for the x axis.
 * @param rot_y the rotation matrix for the y axis.
 * @param trans the translation matrix.
 * @allocated_on Stack
 * @return t_matrix the world matrix.
 */
t_matrix	*get_world_matrix(t_world_i *world)
{
	t_matrix	*world_matrix;

	world_matrix = malloc(sizeof(t_matrix));
	if (!world_matrix)
		return (NULL);
	*world_matrix = multiply_matrix_matrix
		(world->rot->z_rot_m, world->rot->x_rot_m);
	*world_matrix = multiply_matrix_matrix
		(world_matrix, world->rot->y_rot_m);
	*world_matrix = multiply_matrix_matrix
		(world_matrix, world->trans->m);
	return (world_matrix);
}
