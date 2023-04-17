
#include "nlx_clipping.h"
#include "nlx_img.h"
#include "debug.h"

static int compute_code(int x, int y, t_img *img);

//https://www.geeksforgeeks.org/line-clipping-set-1-cohen-sutherland-algorithm/
bool	clip(int *x1, int *y1,
			 int *x2, int *y2, t_img *img)
{
	// Compute region codes for P1, P2
	int code1 = compute_code(*x1, *y1, img);
	int code2 = compute_code(*x2, *y2, img);
	int x_min = 0;
	int x_max = img->width - 1;
	int y_min = 0;
	int y_max = img->height - 1;

	// Initialize line as outside the rectangular window
	bool accept = false;

	while (true) {
		if ((code1 == 0) && (code2 == 0)) {
			// If both endpoints lie within rectangle
			accept = true;
			break;
		}
		else if (code1 & code2) {
			// If both endpoints are outside rectangle,
			// in same region
			break;
		}
		else {
			// Some segment of line lies within the
			// rectangle
			int code_out;
			double x, y;

			// At least one endpoint is outside the
			// rectangle, pick it.
			if (code1 != 0)
				code_out = code1;
			else
				code_out = code2;

			// Find intersection point;
			// using formulas y = y1 + slope * (x - x1),
			// x = x1 + (1 / slope) * (y - y1)
			if (code_out & TOP) {
				// point is above the clip rectangle
				x = *x1 + (*x2 - *x1) * (y_max - *y1) / (*y2 - *y1);
				y = y_max;
				debug_print("x = %f, y = %f\n", x, y);
			}
			else if (code_out & BOTTOM) {
				// point is below the rectangle
				x = *x1 + (*x2 - *x1) * (y_min - *y1) / (*y2 - *y1);
				y = y_min;
				debug_print("x = %f, y = %f\n", x, y);
			}
			else if (code_out & RIGHT) {
				// point is to the right of rectangle
				y = *y1 + (*y2 - *y1) * (x_max - *x1) / (*x2 - *x1);
				x = x_max;
				debug_print("x = %f, y = %f\n", x, y);
			}
			else if (code_out & LEFT) {
				// point is to the left of rectangle
				y = *y1 + (*y2 - *y1) * (x_min - *x1) / (*x2 - *x1);
				x = x_min;
				debug_print("x = %f, y = %f\n", x, y);
			}

			// Now intersection point x, y is found
			// We replace point outside rectangle
			// by intersection point
			if (code_out == code1) {
				*x1 = x;
				*y1 = y;
				code1 = compute_code(*x1, *y1, img);
				debug_print("x1 = %d, y1 = %d\n", *x1, *y1);
			}
			else {
				*x2 = x;
				*y2 = y;
				code2 = compute_code(*x2, *y2, img);
				debug_print("x2 = %d, y2 = %d\n", *x2, *y2);
			}
		}
	}
	return (accept);
}

// Function to compute region code for a point(x, y)
int compute_code(int x, int y, t_img *img)
{
	// initialized as being inside
	int code = INSIDE;
	int	x_min = 0;
	int	x_max = img->width - 1;
	int	y_min = 0;
	int	y_max = img->height - 1;

	if (x < x_min) // to the left of rectangle
		code |= LEFT;
	else if (x > x_max) // to the right of rectangle
		code |= RIGHT;
	if (y < y_min) // below the rectangle
		code |= BOTTOM;
	else if (y > y_max) // above the rectangle
		code |= TOP;

	return code;
}
