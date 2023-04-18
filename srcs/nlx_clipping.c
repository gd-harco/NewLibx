/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlx_clipping.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 08:53:38 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/18 08:53:40 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "nlx_img.h"
#include "nlx_line.h"

static int	compute_code(t_2d_point point, t_img *img);
void		partial_clip(t_nlx_line *line,
				int *c_start, int *c_end, t_img *img);

//https://www.geeksforgeeks.org/line-clipping-set-1-cohen-sutherland-algorithm/
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

int	clip_top_bottom(t_nlx_line *line, int code_outside, t_img *img, int *x)
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

int	clip_left_right(t_nlx_line *line, int code_outside, t_img *img, int *x)
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

void	partial_clip(t_nlx_line *line, int *c_start, int *c_end, t_img *img)
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

// Function to compute region code for a point(x, y)
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
