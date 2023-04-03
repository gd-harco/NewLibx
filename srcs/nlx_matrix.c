/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlx_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:01:04 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/03 16:54:12 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "nlx_matrix.h"
#include <math.h>

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

t_matrix	get_projection_matrix(t_proj_m *data)
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

t_vec3d	multiply_matrix_vector(t_matrix m, t_vec3d *v)
{
	t_vec3d	*new_v;
	float	w;

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
