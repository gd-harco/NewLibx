/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlx_line.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:16:50 by gd-harco          #+#    #+#             */
/*   Updated: 2023/03/29 10:56:50 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef NLX_LINE_H
# define NLX_LINE_H
# include "nlx_img.h"
# include "nlx_vec.h"
# include <math.h>

//-----------------STRUCTURES-----------------//

typedef struct s_nlx_line
{
	t_vec3d	start;
	t_vec3d	end;
	int		delta_x;
	int		delta_y;
	int		var_y;
	int		var_x;
}				t_nlx_line;

//-----------------FUNCTIONS-----------------//

t_nlx_line	create_line(t_vec3d p1, t_vec3d p2);
void		nlx_draw_line(t_img *img, t_nlx_line *to_draw, int color);

#endif
