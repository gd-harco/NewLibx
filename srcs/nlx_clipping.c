
#include "nlx_clipping.h"
#include "nlx_img.h"

//https://www.geeksforgeeks.org/line-clipping-set-1-cohen-sutherland-algorithm/

static int	compute_code(t_2d_point to_check, t_img *img)
{
	int	code;

	code = INSIDE;
	if (to_check.x < 0)
		code |= LEFT;
	else if (to_check.x >= img->width)
		code |= RIGHT;
	if (to_check.y < 0)
		code |= BOTTOM;
	else if (to_check.y >= img->height)
		code |= TOP;
	return (code);
}

void	line_clipping(t_nlx_line to_clip, t_img *img)
{
	int		code_start;
	int		code_end;
	bool	accept;

	code_start = compute_code(to_clip.start, img);
	code_end = compute_code(to_clip.end, img);
	accept = false;
	while (1)
	{
		if (code_start == 0 && code_end == 0)
		{
			accept = true;
			break ;
		}
		else if (code_start & code_end)
			break ;
		else
		{

		}
	}
}
