
#include "nlx_clipping.h"
#include "nlx_img.h"
#include "debug.h"

static int compute_code(t_2d_point point, t_img *img);

//https://www.geeksforgeeks.org/line-clipping-set-1-cohen-sutherland-algorithm/
void	clip(t_nlx_line *to_check, t_img *img)
{
	// Compute region codes for P1, P2
	int code_start = compute_code(to_check->start, img);
	int code_end = compute_code(to_check->end, img);
	int x_min = 0;
	int x_max = img->width - 1;
	int y_min = 0;
	int y_max = img->height - 1;

	while (1) {
		if ((code_start == INSIDE) && (code_end == INSIDE)) {
			// If both endpoints lie within rectangle
			return ;
		}
		else if (code_start & code_end)
		{
			to_check->is_visible = false;
			return ;
		}
		else {
			// Some segment of line lies within the
			// rectangle
			int code_outside;
			int x, y;

			// At least one endpoint is outside the
			// rectangle, pick it.
			if (code_start != 0)
                code_outside = code_start;
			else
                code_outside = code_end;

			// Find intersection point;
			// using formulas y = y1 + slope * (x - x1),
			// x = x1 + (1 / slope) * (y - y1)
			if (code_outside & TOP)
			{
				// point is above the clip rectangle
				x = to_check->start.x + (to_check->end.x - to_check->start.x) * (y_max - to_check->start.y) / (to_check->end.y - to_check->start.y);
				y = y_max;
			}
			else if (code_outside & BOTTOM)
			{
                // point is below the rectangle
				x = to_check->start.x + (to_check->end.x - to_check->start.x) * (y_min - to_check->start.y) / (to_check->end.y - to_check->start.y);
				y = y_min;
			}
			else if (code_outside & RIGHT)
			{
				// point is to the right of rectangle
				y = to_check->start.y + (to_check->end.y - to_check->start.y) * (x_max - to_check->start.x) / (to_check->end.x - to_check->start.x);
				x = x_max;

			}
			else if (code_outside & LEFT)
			{
				// point is to the left of rectangle
				y = to_check->start.y + (to_check->end.y - to_check->start.y) * (x_min - to_check->start.x) / (to_check->end.x - to_check->start.x);
				x = x_min;
			}

			// Now intersection point x, y is found
			// We replace point outside rectangle
			// by intersection point
			if (code_outside == code_start) {
				to_check->start.x = x;
				to_check->start.y = y;
                code_start = compute_code(to_check->start, img);
			}
			else {
				to_check->end.x = x;
				to_check->end.y = y;
                code_end = compute_code(to_check->end, img);
			}
		}
	}
}

// Function to compute region code for a point(x, y)
int compute_code(t_2d_point point, t_img *img)
{
	// initialized as being inside
	int code = INSIDE;
	const int	x_min = 0;
	const int	x_max = img->width - 1;
	const int	y_min = 0;
	const int	y_max = img->height - 1;

	if (point.x < x_min) // to the left of rectangle
		code |= LEFT;
	else if (point.x > x_max) // to the right of rectangle
		code |= RIGHT;
	if (point.y < y_min) // below the rectangle
		code |= BOTTOM;
	else if (point.y > y_max) // above the rectangle
		code |= TOP;

	return code;
}
