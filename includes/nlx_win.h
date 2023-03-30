/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlx_win.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:41:25 by gd-harco          #+#    #+#             */
/*   Updated: 2023/03/30 15:41:59 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef NLX_WIN_H
# define NLX_WIN_H
# include "../minilibx_linux/mlx.h"

//-----------------STRUCTURES-----------------//

typedef struct s_win
{
	void	*mlx;
	void	*win_ptr;
}	t_win;

//-----------------FUNCTIONS-----------------//

void	nlx_win_init(t_win *win, int width, int height, char *title);

#endif
