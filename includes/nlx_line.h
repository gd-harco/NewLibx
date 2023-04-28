/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   nlx_line.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:16:50 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/09 18:55:46 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file nlx_line.h
 *
 * @brief Header file for the line module of the nlx library
 *
 * @ingroup line
 * @ingroup draw
 * @author gd-harco
 * @date 2023/03/23
 * @version 1.2
 */

#ifndef NLX_LINE_H
# define NLX_LINE_H
# include "nlx_img.h"
# include "nlx_vec.h"
# include <math.h>
# include <stdbool.h>

//-----------------STRUCTURES-----------------//

/**
 * @brief Structure representing a 2D point
 * @ingroup line
 * @details This structure is used to represent a 2D point
 * @param x x coordinate of the point
 * @param y y coordinate of the point
 */
typedef struct s_2d_point
{
	int	x;
	int	y;
}		t_2d_point;

/**
 * @brief Structure containg all info for a line
 *
 * @ingroup line
 *
 * @param start the starting point of the line
 * @param end the ending point of the line
 * @param error_x the error on the x axis
 * @param error_y the error on the y axis
 * @param diff_x the difference between the x coordinates
 * of the starting and ending points
 * @param diff_y the difference between the y coordinates
 * of the starting and ending points
 * @param starting_error_x the starting error on the x axis
 * @param starting_error_y the starting error on the y axis
 * @param x_incr the incrementation of the x coordinate
 * @param y_incr the incrementation of the y coordinate
 * @param is_visible a boolean indicating if the line is visible
 */
typedef struct s_nlx_line
{
	t_2d_point	start;
	t_2d_point	end;
	int			error_x;
	int			error_y;
	int			diff_x;
	int			diff_y;
	int			starting_error_x;
	int			starting_error_y;
	int			x_incr;
	int			y_incr;
	bool		is_visible;
}				t_nlx_line;

//-----------------FUNCTIONS-----------------//

t_nlx_line	*create_line(t_vec3d *p1, t_vec3d *p2, t_img *img);
void		fill_line_infos(t_nlx_line *line);
void		clip(t_nlx_line *to_check, t_img *img);

#endif
