/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlx_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:18:54 by gd-harco          #+#    #+#             */
/*   Updated: 2023/03/23 18:25:16 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nlx_line.h"
#include "nlx_img.h"
#include "nlx_color.h"
#include <stdlib.h>

t_nlx_line	*create_line(t_vec3D p1, t_vec3D p2)
{
	t_nlx_line	*new_line;

	new_line = malloc(sizeof(t_nlx_line));
	if (p1.x < p2.x)
	{
		new_line->start = p1;
		new_line->end = p2;
	}
	else
	{
		new_line->start = p2;
		new_line->end = p1;
	}
	new_line->delta_x = new_line->end.x - new_line->start.x;
	new_line->delta_y = new_line->end.y - new_line->start.y;
	return (new_line);
}

void	nlx_draw_line(t_img *img, t_nlx_line *to_draw, int color)
{
	if (to_draw->delta_y > 0)
		nlx_draw_downward(img, to_draw, color);
	// else
		// nlx_draw_upward(img, to_draw, color);
}

void	nlx_draw_downward(t_img *img, t_nlx_line *to_draw, int color)
{
	int		x;
	int		y;

	x = to_draw->start.x;
	y = to_draw->start.y;
	to_draw->d = 2 * to_draw->delta_y - to_draw->delta_x;
	while (x < to_draw->end.x)
	{
		if ((x >= 0 && y >= 0)
			&& (x < img->height && y < img->width))
			nlx_pixel_put(img, x, y, COLOR_BLUE);
		if (to_draw->d < 0)
			to_draw->d += 2 * to_draw->delta_y;
		else
		{
			to_draw->d += 2 * (to_draw->delta_y - to_draw->delta_x);
			y++;
		}
	x++;
	}
}
