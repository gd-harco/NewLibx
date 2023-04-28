/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlx_draw.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:54:31 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/28 10:08:48 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file nlx_draw.h
 *
 * @brief Header file for the draw module of the nlx library
 *
 * @author gd-harco
 * @date 2023/04/27
 * @version 1.2
 */

#ifndef NLX_DRAW_H
# define NLX_DRAW_H

# include "nlx_line.h"
# include "nlx_color.h"

//-----------------FUNCTIONS-----------------//

void	nlx_pixel_put(t_img	*img, t_2d_point to_put, int color);
void	nlx_draw_points(t_img *img, t_nlx_line *to_draw, int color);
void	nlx_draw_line(t_img *img, t_nlx_line *to_draw, int color);
void	nlx_draw_line(t_img *img, t_nlx_line *to_draw, int color);
void	nlx_draw_points(t_img *img, t_nlx_line *to_draw, int color);
void	draw_straight_line(t_2d_point start, t_2d_point end, t_img *img);
void	draw_low_slope(t_2d_point start, t_nlx_line params, t_img *img);
void	draw_high_slope(t_2d_point start, t_nlx_line params, t_img *img);

#endif
