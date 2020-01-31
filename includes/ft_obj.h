/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_obj.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdouveno <kdouveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 15:20:01 by kdouveno          #+#    #+#             */
/*   Updated: 2020/01/31 16:57:23 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OBJ_H
# define FT_OBJ_H
# include "../libs/libmatrix/includes/ft_gl.h"
# include <stdio.h>

typedef const char*	t_shader;

typedef struct		s_obj
{
	unsigned		v_size;
	unsigned		i_size;
	unsigned		shader_program;
	unsigned		voa;
	const unsigned	*indices;
	const float		*vertices;
	t_mat			obj_mat;
	t_mat			wld_mat;
	t_shader		vertex_sh;
	t_shader		fragment_sh; 
}					t_obj;

//	PARSER {
	t_obj			ft_parse_obj_file(FILE *file);

	void			ft_parse_shaders(t_obj *obj);
//	}
#endif