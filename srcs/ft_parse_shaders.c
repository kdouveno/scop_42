/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_shaders.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdouveno <kdouveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 11:02:28 by kdouveno          #+#    #+#             */
/*   Updated: 2020/01/11 15:35:35 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"
#include "../includes/test_globals.h"


void	ft_parse_shaders(t_obj *obj){
	obj->vertex_sh = g_vertex_shader_source;
	obj->fragment_sh = g_fragment_shader_source;
}
