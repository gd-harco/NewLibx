#include "nlx_mat.h"

/**
 * @brief Get the translation matrix object
 * @details this function returns a translation matrix
 * based on the information about the translation passed in parameter
 * @param data structure containing the data needed to create the matrix
 * @return t_matrix the translation matrix allocated on the heap. Must be freed
 */
t_matrix	*get_translation_matrix(float trans_x, float trans_y, float trans_z)
{
	t_matrix	*translation_matrix;

	translation_matrix = create_identity_matrix();
	translation_matrix->m[3][0] = trans_x;
	translation_matrix->m[3][1] = trans_y;
	translation_matrix->m[3][2] = trans_z;
	return (translation_matrix);
}
