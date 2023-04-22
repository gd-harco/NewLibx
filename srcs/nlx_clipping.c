/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlx_clipping.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 08:53:38 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/22 16:46:43 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file nlx_clipping.c

 * @brief file containing every function related to clipping in nlx

 * @author gd-harco
 * @date 2023-04-18
 * @version 1.0
 */

#include "nlx_img.h"
#include "nlx_line.h"

static int	compute_code(t_2d_point point, t_img *img);
static int	clip_top_bottom(
				t_nlx_line *line, int code_outside, t_img *img, int *x);
static int	clip_left_right(
				t_nlx_line *line, int code_outside, t_img *img, int *y);
static void	partial_clip(t_nlx_line *line,
				int *c_start, int *c_end, t_img *img);

/**
 * @brief Nlx's implementation of the Cohen-Sutherland algorithm
 *
 * @see geeksforgeeks.org/line-clipping-set-1-cohen-sutherland-algorithm
 *
 * @param to_check pointer to the line to check
 * @param img pointer to the image to check the line against
 * @return nothing
 */
void	clip(t_nlx_line *to_check, t_img *img)
{
	int	code_start;
	int	code_end;

	code_start = compute_code(to_check->start, img);
	code_end = compute_code(to_check->end, img);
	while (1)
	{
		if ((code_start == INSIDE) && (code_end == INSIDE))
		{
			return ;
		}
		else if (code_start & code_end)
		{
			to_check->is_visible = false;
			return ;
		}
		else
			partial_clip(to_check, &code_start, &code_end, img);
	}
}

/**
 * @brief Function called if the line is partially visible
 *
 * @param line pointer to the line to clip
 * @param c_start pointer to the code of the starting point
 * @param c_end pointer to the code of the ending point
 * @param img pointer to the image to check the line against
 */
static void	partial_clip(t_nlx_line *line, int *c_start, int *c_end, t_img *img)
{
	int	code_outside;
	int	x;
	int	y;

	if (*c_start != 0)
		code_outside = *c_start;
	else
		code_outside = *c_end;
	if (code_outside & TOP || code_outside & BOTTOM)
		y = clip_top_bottom(line, code_outside, img, &x);
	else
		y = clip_left_right(line, code_outside, img, &x);
	if (code_outside == *c_start)
	{
		line->start.x = x;
		line->start.y = y;
		*c_start = compute_code(line->start, img);
	}
	else
	{
		line->end.x = x;
		line->end.y = y;
		*c_end = compute_code(line->end, img);
	}
}

/**
 * @brief Clip the line if it is outside the top or bottom of the image
 *
 * @param line pointer to the line to clip
 * @param code_outside the code of the point outside the image
 * @param img pointer to the image to check the line against
 * @param x pointer to the x coordinate of the clipped point
 * @return int the y coordinate of the clipped point
 */
static int	clip_top_bottom(
				t_nlx_line *line, int code_outside, t_img *img, int *x)
{
	if (code_outside & TOP)
	{
		*x = line->start.x + (line->end.x - line->start.x) * ((img->height - 1)
				- line->start.y) / (line->end.y - line->start.y);
		return (img->height - 1);
	}
	else
	{
		*x = line->start.x + (line->end.x - line->start.x) * (0 - line->start.y)
			/ (line->end.y - line->start.y);
		return (0);
	}
}

/**
 * @brief Clip the line if it is outside the left or right of the image
 *
 * @param line pointer to the line to clip
 * @param code_outside the code of the point outside the image
 * @param img pointer to the image to check the line against
 * @param x pointer to the x coordinate of the clipped point
 * @return int the y coordinate of the clipped point
 */
static int	clip_left_right(
				t_nlx_line *line, int code_outside, t_img *img, int *x)
{
	if (code_outside & RIGHT)
	{
		*x = img->width - 1;
		return (line->start.y + (line->end.y - line->start.y)
			* ((img->width - 1) - line->start.x)
			/ (line->end.x - line->start.x));
	}
	else
	{
		*x = 0;
		return (line->start.y + (line->end.y - line->start.y)
			* (0 - line->start.x) / (line->end.x - line->start.x));
	}
}

/**
 * @brief Compute the code of a point
 *
 * @param point the point to compute the code of
 * @param img the image to check the point against
 * @return the code of the point
 */
int	compute_code(t_2d_point point, t_img *img)
{
	int			code;
	const int	x_min = 0;
	const int	x_max = img->width - 1;
	const int	y_min = 0;
	const int	y_max = img->height - 1;

	code = INSIDE;
	if (point.x < x_min)
		code |= LEFT;
	else if (point.x > x_max)
		code |= RIGHT;
	if (point.y < y_min)
		code |= BOTTOM;
	else if (point.y > y_max)
		code |= TOP;
	return (code);
}
