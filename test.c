#include "include/nlx_color.h"
#include "include/nlx_img.h"
#include "include/nlx_line.h"
#include "include/nlx_vec.h"
#include "minilibx_linux/mlx.h"

void main(void)
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_vec3D	p1;
	t_vec3D	p2;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1280, 720, "TEST");
	nlx_new_image(&img, mlx, 1280, 720);
	p1.x = 640;
	p1.y = 0;
	p2.x = 640;
	p2.y = 719;
	t_nlx_line line = create_line(p1, p2);
	nlx_draw_line(&img, &line, COLOR_BLUE);
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	mlx_loop(mlx);
}
