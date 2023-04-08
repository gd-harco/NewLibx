#include "nlx_matrix.h"

/**
 * @brief Create a rotation matrix object for the x axis
 * @param angle The angle to rotate by
 * @return t_matrix* The rotation matrix allocated on the heap.
 */
t_matrix	*get_x_rotation_matrix(float angle)
{
	t_matrix	*rot_matrix;

	rot_matrix = create_identity_matrix();
	rot_matrix->m[1][1] = cosf(angle);
	rot_matrix->m[1][2] = -sinf(angle);
	rot_matrix->m[2][1] = sinf(angle);
	rot_matrix->m[2][2] = cosf(angle);
	return (rot_matrix);
}

/**
 * @brief Create a rotation matrix object for the y axis
 * @param angle The angle to rotate by
 * @return t_matrix* The rotation matrix allocated on the heap.
 */
t_matrix	*get_y_rotation_matrix(float angle)
{
	t_matrix	*rot_matrix;

	rot_matrix = create_identity_matrix();
	rot_matrix->m[0][0] = cosf(angle);
	rot_matrix->m[0][2] = sinf(angle);
	rot_matrix->m[2][0] = -sinf(angle);
	rot_matrix->m[2][2] = cosf(angle);
	return (rot_matrix);
}

/**
 * @brief Create a rotation matrix object for the z axis
 * @param angle The angle to rotate by
 * @return t_matrix* The rotation matrix allocated on the heap.
 */
t_matrix	*get_z_rotation_matrix(float angle)
{
	t_matrix	*rot_matrix;

	rot_matrix = create_identity_matrix();
	rot_matrix->m[0][0] = cosf(angle);
	rot_matrix->m[0][1] = -sinf(angle);
	rot_matrix->m[1][0] = sinf(angle);
	rot_matrix->m[1][1] = cosf(angle);
	return (rot_matrix);
}
