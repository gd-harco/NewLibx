/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlx_win.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:42:41 by gd-harco          #+#    #+#             */
/*   Updated: 2023/03/28 13:12:06 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "nlx_win.h"

void	nlx_win_init(t_win *win, int width, int height, char *title)
{
	win->mlx = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx, width, height, title);
}
