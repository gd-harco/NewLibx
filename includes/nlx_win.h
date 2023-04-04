/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlx_win.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:41:25 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/03 21:07:08 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file nlx_win.h
 *
 * @brief header file for the window management
 *
 * @author gd-harco
 * @date 2023/03/27
 */
#ifndef NLX_WIN_H
# define NLX_WIN_H
# include "../minilibx_linux/mlx.h"

//-----------------STRUCTURES-----------------//

/**
 * @struct s_win
 * @brief Structure to store a window and its properties
 * @param mlx The mlx pointer. Automaticly generated
 */
typedef struct s_win
{
	void	*mlx;
	void	*win_ptr;
}	t_win;

//-----------------FUNCTIONS-----------------//

void	nlx_win_init(t_win *win, int width, int height, char *title);

#endif
