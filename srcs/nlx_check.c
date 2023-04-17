/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlx_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:25:51 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/13 11:26:05 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "nlx_check.h"

bool	is_pixel_in_img(t_2d_point to_check, int height, int width)
{
	if (to_check.x < 0 || to_check.x >= width)
		return (false);
	if (to_check.y < 0 || to_check.y >= height)
		return (false);
	return (true);
}
