/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlx_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:18:54 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/03 21:58:21 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file nlx_line.c
 *
 * @brief file containing every function related to lines in nlx
 *
 * @author gd-harco
 * @date 2023-04-03
 */
#include "nlx_line.h"
#include "nlx_img.h"
#include "nlx_color.h"
#include <stdlib.h>
#include <stdbool.h>

bool		is_pixel_in_img(int x, int y, int height, int width);
t_nlx_line	create_straight_line(t_vec3d p1, t_vec3d p2);
void		nlx_draw_straight_line(t_img *img, t_nlx_line *to_draw, int color);

/**
 * @brief draw a line on the image
 * @details this function uses the Bresenham algorithm to draw a line
 * using the function nlx_pixel_put.
 * if the line is vertical, the function nlx_draw_straight_line is called
 * @param img image to draw on, as a t_img structure
 * @param to_draw line to draw on the image, as a t_nlx_line structure
 * @param color color of the line to draw (in hexa) or as defined in nlx_color.h
 * @see nlx_color.h
 * @return nothing
 */
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

/**
 * @brief simplified version of nlx_draw_line for straight lines
 * @param img image to draw on, as a t_img structure
 * @param to_draw line to draw on the image, as a t_nlx_line structure
 * @param color color of the line to draw (in hexa) or as defined in nlx_color.h
 * @see nlx_color.h
 * @return nothing
 */
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

/**
 * @brief Create a line object
 * @details create a line object from two points.
 * The order of the point doesn't matter, the function will determine it.
 * if the line is a straight line, the function will call create_straight_line
 * @param p1 first point of the line
 * @param p2 second point of the line
 * @return t_nlx_line the line object created
 */
t_nlx_line	create_line(t_vec3d p1, t_vec3d p2)
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
	new_line.delta_x = fabs(new_line.end.x - new_line.start.x);
	new_line.delta_y = fabs(new_line.end.y - new_line.start.y);
	new_line.var_y = 0;
	if (new_line.end.y < new_line.start.y)
		new_line.var_y = -1;
	else if (new_line.end.y > new_line.start.y)
		new_line.var_y = 1;
	new_line.var_x = 1;
	return (new_line);
}

/**
 * @brief Create a straight line object
 * @details create a straight line object from two points.
 * The order of the point doesn't matter, the function will determined it.
 * @param p1 first point of the line
 * @param p2 second point of the line
 * @return t_nlx_line the line object created
 */
t_nlx_line	create_straight_line(t_vec3d p1, t_vec3d p2)
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
	straight.delta_y = fabs(straight.end.y - straight.start.y);
	straight.var_y = 1;
	straight.var_x = 0;
	return (straight);
}

/**
 * @brief check if a pixel is in the image
 * @param x x coordinate of the pixel
 * @param y y coordinate of the pixel
 * @param height height of the image
 * @param width width of the image
 * @return true if the pixel is in the image, false otherwise
 */
bool	is_pixel_in_img(int x, int y, int height, int width)
{
	if (x >= 0 && x < width)
	{
		if (y >= 0 && y < height)
			return (true);
	}
	return (false);
}
