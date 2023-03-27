/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlx_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:17:30 by gd-harco          #+#    #+#             */
/*   Updated: 2023/03/26 19:52:27 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "nlx_matrix.h"

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
