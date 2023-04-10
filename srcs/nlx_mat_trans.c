/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlx_mat_trans.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:05:07 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/08 16:05:08 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "nlx_mat.h"

/**
 * @brief Create a translation matrix.
 * @param trans_x The value to translate on the x axis.
 * @param trans_y The value to translate on the y axis.
 * @param trans_z The value to translate on the z axis.
 * @allocated_on Heap (must be freed)
 * @return t_matrix* The transation matrix created.
 */
t_matrix	*get_translation_matrix(float trans_x, float trans_y, float trans_z)
{
	t_matrix	*translation_matrix;

	translation_matrix = create_identity_matrix();
	translation_matrix->m[3][0] = trans_x;
	translation_matrix->m[3][1] = trans_y;
	translation_matrix->m[3][2] = trans_z;
	return (translation_matrix);
}
