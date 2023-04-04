/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlx_matrix.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:15:08 by gd-harco          #+#    #+#             */
/*   Updated: 2023/03/29 10:57:17 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef NLX_MATRIX_H
# define NLX_MATRIX_H

# include "nlx_vec.h"
# include <math.h>

//-----------------STRUCTURES-----------------//

typedef struct s_matrix
{
	double	m[4][4];
}				t_matrix;

typedef struct s_proj_info
{
	t_matrix	m;
	double		z_near;
	double		z_far;
	double		fov;
	double		aspect_ratio;
}	t_proj_info;

//-----------------FUNCTIONS-----------------//

void		create_identity_matrix(t_matrix *m);
t_matrix	get_projection_matrix(t_proj_info *data);
t_vec3d		*multiply_matrix_vector(t_matrix m, t_vec3d *v);

#endif
