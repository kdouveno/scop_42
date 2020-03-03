/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdouveno <kdouveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 08:21:47 by kdouveno          #+#    #+#             */
/*   Updated: 2020/03/03 16:37:15 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H
# define GL_SILENCE_DEPRECATION
# define BZ(var) (bzero(&var, sizeof(var)))
#include <stdbool.h>
#include <stddef.h>
#include "../libs/glad/includes/glad.h"
#include "../libs/libmatrix/includes/ft_gl.h"
#include "ft_obj.h"


//	GL INIT {
	int				ft_load_shaders(t_obj *obj);                      
	void			ft_load_objs(t_obj *obj);
//	}
//	Loop renderer {
	void			ft_loop(void *data);
//	}
#endif