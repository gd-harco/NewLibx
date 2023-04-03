/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlx_line.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:16:50 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/03 17:36:19 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef NLX_LINE_H
# define NLX_LINE_H
# include "nlx_img.h"
# include "nlx_vec.h"
# include <math.h>

//-----------------STRUCTURES-----------------//

/**
 * @struct s_nlx_line nlx_line.h 
 * @brief Structure to store a line and its properties
 * @ingroup line
 * @ingroup draw
 * @param start The start point of the line. Must be provided.
 * @param end The end point of the line. Must be provided.
 * @param delta_x The difference between the x coordinates
 * of the start and end points. Calculated automatically.
 * @param delta_y The difference between the y coordinates
 * of the start and end points. Calculated automatically.
 * @param var_y The variation of the y coordinate.
 * Used when drawing the line. Determined automatically.
 * @param var_x The variation of the x coordinate.
 * Used when drawing the line. Determined automatically.
*/
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
