/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlx_mat_multiply.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:00:50 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/22 16:41:35 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file nlx_mat_multiply.c
 * @brief
 * @details This file contains the function to multiply matrices.
 * It is used to create the world matrix by multiplying
 * the translation matrix by the rotation matrix.
 * It is also used to multiply the vector map by the
 * world matrix to get the screen coordinates of the points
 * @author gd-harco
 * @date 2023-04-08
 * @version 1.0
 */

#include "nlx_mat.h"

/**
 * @brief Multiply a matrix by a vector.
 * @details This function multiplies a matrix by a vector,\n
 * resulting in a vector that can be used to draw a point on the screen.
 * @param m matrix to multiply.
 * @param s_vec vector to multiply.
 * @param r_vec vector containing the result of the multiplication.
 */
void	multiply_vector_matrix(t_matrix *m, t_vec3d *s_vec, t_vec3d *r_vec)
{
	r_vec->x = s_vec->x * m->m[0][0] + s_vec->y * m->m[1][0]
		+ s_vec->z * m->m[2][0] + s_vec->w * m->m[3][0];
	r_vec->y = s_vec->x * m->m[0][1] + s_vec->y * m->m[1][1]
		+ s_vec->z * m->m[2][1] + s_vec->w * m->m[3][1];
	r_vec->z = s_vec->x * m->m[0][2] + s_vec->y * m->m[1][2]
		+ s_vec->z * m->m[2][2] + s_vec->w * m->m[3][2];
	r_vec->w = s_vec->x * m->m[0][3] + s_vec->y * m->m[1][3]
		+ s_vec->z * m->m[2][3] + s_vec->w * m->m[3][3];
}

/**
 * @brief Multiply a matrix by a matrix.
 * @details This function multiplies a matrix by a matrix,\n
 * returning a matrix that can be used to create the world matrix.
 * @param m1 First matrix to multiply.
 * @param m2 Second matrix to multiply.
 * @allocated_on Stack
 * @return t_matrix the result of the multiplication.
 */
t_matrix	multiply_matrix_matrix(t_matrix *m1, t_matrix *m2)
{
	t_matrix	result;
	int			y;
	int			x;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			result.m[x][y] = m1->m[x][0] * m2->m[0][y]
				+ m1->m[x][1] * m2->m[1][y]
				+ m1->m[x][2] * m2->m[2][y]
				+ m1->m[x][3] * m2->m[3][y];
			x++;
		}
		y++;
	}
	return (result);
}
