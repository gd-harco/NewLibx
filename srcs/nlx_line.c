/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlx_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:18:54 by gd-harco          #+#    #+#             */
/*   Updated: 2023/03/26 16:25:07 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "nlx_line.h"
#include "nlx_img.h"
#include "nlx_color.h"
#include <stdlib.h>
#include <stdbool.h>

bool		is_pixel_in_img(int x, int y, int height, int width);
t_nlx_line	create_straight_line(t_vec3D p1, t_vec3D p2);
void		nlx_draw_straight_line(t_img *img, t_nlx_line *to_draw, int color);

void	nlx_draw_line(t_img *img, t_nlx_line *to_draw, int color)
{
	int		x;
	int		y;
	float	m;
	float	e;

	if (to_draw->delta_x == 0)
	{
		return (nlx_draw_straight_line(img, to_draw, color));
	}
	m = to_draw->delta_y / to_draw->delta_x;
	x = to_draw->start.x;
	y = to_draw->start.y;
	e = 0;
	while (x <= to_draw->end.x)
	{
		if (is_pixel_in_img(x, y, img->height, img->width))
			nlx_pixel_put(img, x, y, color);
		e -= m;
		x += to_draw->var_x;
		if (e < -0.5)
		{
			y += to_draw->var_y;
			e += 1.0;
		}
	}
}

t_nlx_line	create_line(t_vec3D p1, t_vec3D p2)
{
	t_nlx_line	new_line;

	if (p1.x < p2.x)
	{
		new_line.start = p1;
		new_line.end = p2;
	}
	else if (p1.x > p2.x)
	{
		new_line.start = p2;
		new_line.end = p1;
	}
	else
		return (create_straight_line(p1, p2));
	new_line.delta_x = abs(new_line.end.x - new_line.start.x);
	new_line.delta_y = abs(new_line.end.y - new_line.start.y);
	new_line.var_y = 0;
	if (new_line.end.y < new_line.start.y)
		new_line.var_y = -1;
	else if (new_line.end.y > new_line.start.y)
		new_line.var_y = 1;
	new_line.var_x = 1;
	return (new_line);
}

t_nlx_line	create_straight_line(t_vec3D p1, t_vec3D p2)
{
	t_nlx_line	straight;

	if (p1.y < p2.y)
	{
		straight.start = p1;
		straight.end = p2;
	}
	else
	{
		straight.start = p2;
		straight.end = p1;
	}
	straight.delta_x = 0;
	straight.delta_y = abs(straight.end.y - straight.start.y);
	straight.var_y = 1;
	straight.var_x = 0;
	return (straight);
}

void	nlx_draw_straight_line(t_img *img, t_nlx_line *to_draw, int color)
{
	int		y;

	y = to_draw->start.y;
	while (y <= to_draw->end.y)
	{
		if (is_pixel_in_img(to_draw->start.x, y, img->height, img->width))
			nlx_pixel_put(img, to_draw->start.x, y, color);
		y++;
	}
}

bool	is_pixel_in_img(int x, int y, int height, int width)
{
	if (x >= 0 && x < width)
	{
		if (y >= 0 && y < height)
			return (true);
	}
	return (false);
}
