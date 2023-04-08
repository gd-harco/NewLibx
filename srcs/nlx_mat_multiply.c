/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlx_mat_multiply.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:00:50 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/08 16:04:58 by gd-harco         ###   ########lyon.fr   */
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
 */

#include "nlx_mat.h"

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

/**
 * @brief Multiply a matrix by a matrix
 * @details this function multiplies a matrix by a matrix,
 * returning a matrix that can be used to create the world matrix
 * @param m1 first matrix to multiply
 * @param m2 second matrix to multiply
 * @return t_matrix the result of the multiplication
 */
t_matrix	multiply_matrix_matrix(t_matrix *m1, t_matrix *m2)
{
	t_matrix	result;
	int			row;
	int			col;
	int			i;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			i = 0;
			result.m[row][col] = 0;
			while (i < 4)
			{
				result.m[row][col] += m1->m[row][i] * m2->m[i][col];
				i++;
			}
			col++;
		}
		row++;
	}
	return (result);
}
