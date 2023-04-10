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
t_matrix	get_world_matrix(t_matrix *rot_z, t_matrix *rot_x,
						t_matrix *rot_y, t_matrix *trans)
{
	t_matrix	world_matrix;

	world_matrix = multiply_matrix_matrix(rot_z, rot_x);
	world_matrix = multiply_matrix_matrix(&world_matrix, rot_y);
	world_matrix = multiply_matrix_matrix(&world_matrix, trans);
	return (world_matrix);
}
