/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlx_line_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:22:54 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/22 16:23:12 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "nlx_line.h"

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
