#include "nlx_mat.h"

t_matrix	get_world_matrix(t_matrix *rot_z, t_matrix *rot_x,
						t_matrix *rot_y, t_matrix *trans)
{
	t_matrix	world_matrix;

	world_matrix = multiply_matrix_matrix(rot_z, rot_x);
	world_matrix = multiply_matrix_matrix(&world_matrix, rot_y);
	world_matrix = multiply_matrix_matrix(&world_matrix, trans);
	return (world_matrix);
}
