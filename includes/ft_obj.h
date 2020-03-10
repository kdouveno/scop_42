/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_obj.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdouveno <kdouveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 15:20:01 by kdouveno          #+#    #+#             */
/*   Updated: 2020/03/10 16:19:51 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OBJ_H
# define FT_OBJ_H
# include "../libs/libmatrix/includes/ft_gl.h"
# include <stdio.h>


typedef const char*	t_shader;

typedef struct		s_face_indices{
	int	v1;
	int	vt1;
	int	vn1;
	int	v2;
	int	vt2;
	int	vn2;
	int	v3;
	int	vt3;
	int	vn3;
}					t_face_indices;

typedef struct		s_vertex{
	float			vx;
	float			vy;
	float			vz;
	float			vtx;
	float			vty;
	float			vnx;
	float			vny;
	float			vnz;
}					t_vertex;

typedef struct 		s_face
{
	t_vertex		f1;
	t_vertex		f2;
	t_vertex		f3;
}					t_face;
typedef struct		s_obj
{
	size_t			faces_size;
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