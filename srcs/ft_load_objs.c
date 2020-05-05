/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_objs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karldouvenot <karldouvenot@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 10:23:02 by kdouveno          #+#    #+#             */
/*   Updated: 2020/05/02 20:57:53 by karldouveno      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"


void	ft_load_objs(t_obj *obj){ // gros caca a changer
	unsigned vbo, voa, ebo;

	glGenVertexArrays(1, &voa); 
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);
	glBindVertexArray(voa);
	
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, obj->faces_size, obj->faces_vbo, GL_STATIC_DRAW);

	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glBindVertexArray(0);
}
