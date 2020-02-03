/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_obj.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdouveno <kdouveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 15:20:01 by kdouveno          #+#    #+#             */
/*   Updated: 2020/02/03 16:46:06 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OBJ_H
# define FT_OBJ_H
# include "../libs/libmatrix/includes/ft_gl.h"
# include <stdio.h>


typedef const char*	t_shader;

typedef struct		s_face_indices{
	unsigned int	v1;
	unsigned int	vn1;
	unsigned int	vt1;
	unsigned int	v2;
	unsigned int	vn2;
	unsigned int	vt2;
	unsigned int	v3;
	unsigned int	vn3;
	unsigned int	vt3;
}					t_face_indices;

typedef struct		s_face{
	float			v1;
	float			vn1;
	float			vt1;
	float			v2;
	float			vn2;
	float			vt2;
	float			v3;
	float			vn3;
	float			vt3;
}					t_face;

typedef struct		s_obj
{
	unsigned		faces_size;
	t_face			*faces_vbo;
	unsigned		shader_program;
	const unsigned	*indices;
	const float		*vertices;
	t_mat			obj_mat;
	t_mat			wld_mat;
	t_shader		vertex_sh;
	t_shader		fragment_sh;
	char			*name;
}					t_obj;

//	PARSER {
	t_obj			ft_parse_obj_file(FILE *file);

	void			ft_parse_shaders(t_obj *obj);
//	}
#endif