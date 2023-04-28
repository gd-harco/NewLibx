/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlx_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:18:54 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/28 18:13:28 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file nlx_line.c
 *
 * @brief file containing every function related to lines in nlx
 *
 * @author gd-harco
 * @date 2023-04-03
 * @version 1.2
 */
#include "nlx_line.h"
#include "nlx_img.h"
#include "nlx_color.h"

/**
 * @brief create a line
 * @param p1 first point of the line
 * @param p2 second point of the line
 * @allocated_on Heap (must be freed)
 * @return a pointer to the line
 */
t_nlx_line	*create_line(t_vec3d *p1, t_vec3d *p2, t_img *img)
{
	t_nlx_line	*line;

	line = malloc(sizeof(t_nlx_line));
	if (!line)
		return (NULL);
	line->start.x = p1->x + 0.5f;
	line->start.y = p1->y + 0.5f;
	line->end.x = p2->x + 0.5f;
	line->end.y = p2->y + 0.5f;
	line->is_visible = true;
	if (p1->is_behind_camera || p2->is_behind_camera)
		line->is_visible = false;
	else
		clip(line, img);
	fill_line_infos(line);
	return (line);
}

/**
 * @brief Fill the line infos
 *
 * @details This function will fill the line infos
 * @param line the line to fill
 * @return nothing
 */
void	fill_line_infos(t_nlx_line *line)
{
	line->error_x = abs((int)(line->end.x - line->start.x + 0.5f));
	line->error_y = abs((int)(line->end.y - line->start.y + 0.5f));
	line->diff_x = 2 * line->error_x;
	line->diff_y = 2 * line->error_y;
	line->starting_error_x = line->error_x;
	line->starting_error_y = line->error_y;
	line->x_incr = 1;
	if (line->start.x > line->end.x)
		line->x_incr = -1;
	line->y_incr = 1;
	if (line->start.y > line->end.y)
		line->y_incr = -1;
}
