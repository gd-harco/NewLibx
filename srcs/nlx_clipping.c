
#include "nlx_clipping.h"
#include "nlx_img.h"
#include "debug.h"

static int	compute_code(t_2d_point point, t_img *img);
void		partial_clip(t_nlx_line *to_check, int code_start, int code_end, t_img *img);

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
			partial_clip(to_check, code_start, code_end, img);
	}
}


void	partial_clip(t_nlx_line *to_check, int code_start, int code_end, t_img *img)
{
	int	code_outside;
	int	x;
	int	y;

	if (code_start != 0)
		code_outside = code_start;
	else
		code_outside = code_end;
	if (code_outside & TOP)
	{
		x = to_check->start.x + (to_check->end.x - to_check->start.x) * ((img->height - 1) - to_check->start.y) / (to_check->end.y - to_check->start.y);
		y = img->height - 1;
	}
	else if (code_outside & BOTTOM)
	{
		x = to_check->start.x + (to_check->end.x - to_check->start.x) * (0 - to_check->start.y) / (to_check->end.y - to_check->start.y);
		y = 0;
	}
	else if (code_outside & RIGHT)
	{
		y = to_check->start.y + (to_check->end.y - to_check->start.y) * ((img->height - 1) - to_check->start.x) / (to_check->end.x - to_check->start.x);
		x = img->height - 1;
	}
	else if (code_outside & LEFT)
	{
		y = to_check->start.y + (to_check->end.y - to_check->start.y) * (0 - to_check->start.x) / (to_check->end.x - to_check->start.x);
		x = 0;
	}
	if (code_outside == code_start)
	{
		to_check->start.x = x;
		to_check->start.y = y;
		code_start = compute_code(to_check->start, img);
	}
	else
	{
		to_check->end.x = x;
		to_check->end.y = y;
		code_end = compute_code(to_check->end, img);
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
