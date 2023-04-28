/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlx_img.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 11:48:30 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/28 18:12:58 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file nlx_img.h
 *
 * @brief Header file for the image management module of the nlx library
 *
 * @ingroup image
 * @author gd-harco
 * @date 2023/03/23
 * @version 1.2
 */

#ifndef NLX_IMG_H
# define NLX_IMG_H
# include "../minilibx_linux/mlx.h"

# define INSIDE 0
# define LEFT 1
# define RIGHT 2
# define BOTTOM 4
# define TOP 8

//-----------------STRUCTURES-----------------//

/**
 * @struct s_img
 * @brief Structure to store an image and its properties
 * @param img The image pointer. Automaticly generated
 * @param addr The address of the image. Automaticly generated
 * @param bits_per_pixel The number of bits per pixel. Automaticly generated
 * @param line_length The length of a line in the image. Automaticly generated
 * @param endian The endian of the image. Automaticly generated
 * @param width The width of the image, in pixels. Must be specified
 * @param height The height of the image, in pixels. Must be specified
 */
typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}			t_img;

//-----------------FUNCTIONS-----------------//

void	nlx_new_image(t_img *img, void *mlx, int width, int height);

#endif
