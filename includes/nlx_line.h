/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlx_line.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:16:50 by gd-harco          #+#    #+#             */
/*   Updated: 2023/03/26 16:07:18 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef NLX_LINE_H
# define NLX_LINE_H
# include "nlx_img.h"
# include "nlx_vec.h"

//-----------------STRUCTURES-----------------//

typedef struct s_nlx_line
{
	t_vec3D	start;
	t_vec3D	end;
	float	delta_x;
	float	delta_y;
	int		var_y;
	int		var_x;
}				t_nlx_line;

//-----------------FUNCTIONS-----------------//

t_nlx_line	create_line(t_vec3D p1, t_vec3D p2);
void		nlx_draw_line(t_img *img, t_nlx_line *to_draw, int color);

#endif
