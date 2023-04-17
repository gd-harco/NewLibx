/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlx_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:18:54 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/17 15:52:26 by gd-harco         ###   ########lyon.fr   */
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
# include "debug.h"
#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief Draw a line on an image
 * @details The function will create a line from two points
 * @param start the starting point of the line
 * @param params the parameters of the line
 * @param img the image on which the line will be drawn
 */
static void	draw_straight_line(t_2d_point start, t_2d_point end, t_img *img)
{
	if (start.x == end.x)
	{
		if (start.y > end.y)
			return (draw_straight_line(end, start, img));
		while (start.y <= end.y)
		{
			nlx_pixel_put(img, start.x, start.y, COLOR_WHITE);
			start.y++;
		}
	}
	else
	{
		if (start.x > end.x)
			return (draw_straight_line(end, start, img));
		while (start.x <= end.x)
		{
			nlx_pixel_put(img, start.x, start.y, COLOR_WHITE);
			start.x++;
		}
	}
}

/**
 * @brief Draw a line on an image
 * @details The function will create a line from two points
 * @param start the starting point of the line
 * @param params the parameters of the line
 * @param img the image on which the line will be drawn
 */
static void	draw_low_slope(t_2d_point start,
				t_nlx_line params, t_img *img)
{
	int	i;

	i = -1;
	while (++i <= params.starting_error_x)
	{
		nlx_pixel_put(img, start.x, start.y, COLOR_WHITE);
		start.x += params.x_incr;
		params.error_x -= params.diff_y;
		if (params.error_x < 0)
		{
			start.y += params.y_incr;
			params.error_x += params.diff_x;
		}
	}
}

/**
 * @brief Draw a line on an image
 * @details The function will create a line from two points
 * @param start the starting point of the line
 * @param params the parameters of the line
 * @param img the image on which the line will be drawn
 */
static void	draw_high_slope(t_2d_point start,
				t_nlx_line params, t_img *img)
{
	int	i;

	i = -1;
	while (++i <= params.starting_error_y && start.y > 0)
	{
		nlx_pixel_put(img, start.x, start.y, COLOR_WHITE);
		start.y += params.y_incr;
		params.error_y -= params.diff_x;
		if (params.error_y < 0)
		{
			start.x += params.x_incr;
			params.error_y += params.diff_y;
		}
	}
}

/**
 * @brief draw a line on an image
 * @details the function will draw a line on the image with the given color.
 * This function is just here to analyze the slope of the line
 * and call the according function.
 * @param img the image on which the line will be drawn
 * @param to_draw the line to draw
 * @param color the color of the line
 */
void	nlx_draw_line(t_img *img, t_nlx_line *to_draw, int color)
{
	if (to_draw->start.x == to_draw->end.x
		|| to_draw->start.y == to_draw->end.y)
		return (draw_straight_line(to_draw->start, to_draw->end, img));
	if (to_draw->starting_error_x > to_draw->starting_error_y)
		draw_low_slope(to_draw->start, *to_draw, img);
	else
		draw_high_slope(to_draw->start, *to_draw, img);
	(void)color;
}

/**
 * @brief create a line
 * @param p1 first point of the line
 * @param p2 second point of the line
 * @allocated_on Heap (must be freed)
 * @return a pointer to the line
 */
t_nlx_line *create_line(t_vec3d *p1, t_vec3d *p2, t_img *img)
{
	t_nlx_line	*line;

	line = malloc(sizeof(t_nlx_line));
	if (!line)
		return (NULL);
	line->start.x = p1->x + 0.5f;
	line->start.y = p1->y + 0.5f;
	line->end.x = p2->x + 0.5f;
	line->end.y = p2->y + 0.5f;
	//TODO add clipping here before creating every other value in the struct
	line->is_visible = true;
	clip(line, img);
	line->error_x = abs((int)(line->end.x - line->start.x + 0.5f));
	line->error_y = abs((int)(line->end.y - line->start.y + 0.5f));
	line->diff_x = 2 * line->error_x;
	line->diff_y = 2 * line->error_y;
	line->starting_error_x = line->error_x;
	line->starting_error_y = line->error_y;
	line->x_incr = 1;
	if (line->start.x > line->end.x)
		line->x_incr = -1;
	line->y_incr = 1;
	if (line->start.y > line->end.y)
		line->y_incr = -1;
	return (line);
}
