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
 * @param world The world structure.
 * @allocated_on Heap (must be freed)
 * @return t_matrix* The translation matrix created.
 */
t_matrix	*get_translation_matrix(t_trans_info *trans)
{
	t_matrix	*translation_matrix;

	translation_matrix = create_identity_matrix();
	translation_matrix->m[3][0] = trans->translate_x;
	translation_matrix->m[3][1] = trans->translate_y;
	translation_matrix->m[3][2] = trans->translate_z;
	return (translation_matrix);
}
