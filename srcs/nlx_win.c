/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlx_win.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:42:41 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/22 16:44:39 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file nlx_win.c
 *
 * @brief file containing every function related to windows in nlx
 *
 * @author gd-harco
 * @date 2023-04-03
 * @version 1.0
 */
#include "nlx_win.h"

/**
 * @brief Initialize a window
 * @details The function first initialize the mlx pointer in the t_win structure
 * then it creates a new window with the mlx pointer and the other parameters
 * @param win the structure containing the window and the mlx information
 * @param width the width of the window to create
 * @param height the height of the window to create
 * @param title the title of the window to create
 */
void	nlx_win_init(t_win *win, int width, int height, char *title)
{
	win->mlx = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx, width, height, title);
	win->width = width;
	win->height = height;
}
