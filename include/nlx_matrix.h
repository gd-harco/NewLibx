/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlx_matrix.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:15:08 by gd-harco          #+#    #+#             */
/*   Updated: 2023/03/26 16:18:24 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef NLX_MATRIX_H
# define NLX_MATRIX_H

# include "nlx_vec.h"
# include "libft.h"

typedef struct s_matrix
{
	double	m[4][4];
}				t_matrix;

void	init_matrix(t_matrix *m);

#endif
