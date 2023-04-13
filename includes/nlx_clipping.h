#ifndef NLX_CLIPPING_H
# define NLX_CLIPPING_H

# include "nlx_line.h"
# include <stdbool.h>

# define INSIDE 0
# define LEFT 1
# define RIGHT 2
# define BOTTOM 4
# define TOP 8

void	line_clipping(t_nlx_line to_clip, t_img *img);

#endif
