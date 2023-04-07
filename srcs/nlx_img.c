/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlx_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 11:32:49 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/03 21:07:53 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file nlx_img.c

 * @brief functions to create and draw on images, using mlx

 * @author gd-harco
 * @date 2023/03/23
 */

#include "nlx_img.h"

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

/**
 * @brief draw a pixel on an image
 *
 * @param img pointer to the t_img structure containing the image
 * @param x x coordinate of the pixel
 * @param y y coordinate of the pixel
 * @param color color of the pixel, in hexadecimal
 * or as defined in nlx_color.h
 * @return nothing
 */
void	nlx_pixel_put(t_img	*img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
