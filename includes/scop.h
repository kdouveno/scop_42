/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdouveno <kdouveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 08:21:47 by kdouveno          #+#    #+#             */
/*   Updated: 2020/01/15 10:57:44 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H
# define GL_SILENCE_DEPRECATION
#include <stdbool.h>
#include <stddef.h>
#include "../libs/glad/includes/glad.h"

typedef const char*	t_shader;

typedef struct		s_obj
{
	unsigned		v_size;
	unsigned		i_size;
	unsigned		shader_program;
	unsigned		voa;
	const unsigned	*indices;
	const float		*vertices;
	t_shader		vertex_sh;
	t_shader		fragment_sh;

}					t_obj;

//	PARSER {
	t_obj			ft_parse_obj(void);

	void		ft_parse_shaders(t_obj *obj);
//	}
//	GL INIT {
	int			ft_load_shaders(t_obj *obj);
	void		ft_load_objs(t_obj *obj);
//	}
//	Loop renderer {
	void	ft_loop(void *data);
//	}
#endif