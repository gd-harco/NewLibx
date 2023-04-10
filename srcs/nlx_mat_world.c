#include "nlx_mat.h"

/**
 * @brief Create the world matrix
 * @details The world matrix is the product of
 * the rotation matrices and the translation matrix.\n
 * This is the matrix that will be used to transform the vector map.
 * @param rot_z the rotation matrix for the z axis.
 * @param rot_x the rotation matrix for the x axis.
 * @param rot_y the rotation matrix for the y axis.
 * @param trans the translation matrix.
 * @allocated_on Stack
 * @return t_matrix the world matrix.
 */
t_matrix	get_world_matrix(t_world_i *world)
{
	t_matrix	world_matrix;

	world_matrix = multiply_matrix_matrix
		(world->rot->z_rot_m, world->rot->x_rot_m);
	world_matrix = multiply_matrix_matrix
		(&world_matrix, world->rot->y_rot_m);
	world_matrix = multiply_matrix_matrix
		(&world_matrix, world->trans->m);
	return (world_matrix);
}
