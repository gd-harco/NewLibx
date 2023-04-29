/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlx_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 11:32:49 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/29 12:02:47 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file nlx_img.c

 * @brief functions to create an images, using mlx

 * @author gd-harco
 * @date 2023/03/23
 * @version 1.2
 */

#include "nlx_img.h"
#include "nlx_color.h"
#include "nlx_line.h"
#include "nlx_draw.h"
/**
 * @brief create a new image and store it in
 * 			the t_img structure passed as a parameter
 *
 * @param img pointer to the t_img structure to store the image in
 * @param mlx pointer to the mlx structure
 * @param width width of the image to create, in pixels
 * @param height height of the image to create, in pixels
 * @return nothing
 */
void	nlx_new_image(t_img *img, void *mlx, int width, int height)
{
	img->img_ptr = mlx_new_image(mlx, width, height);
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	img->width = width;
	img->height = height;
}

void	nlx_set_background(t_img *img, int color)
{
	int	row;
	int	col;

	row = 0;
	while (row < img->height)
	{
		col = 0;
		while (col < img->width)
		{
			nlx_pixel_put(img, (t_2d_point){col, row}, color);
			col++;
		}
		row++;
	}
}
