/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_objs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdouveno <kdouveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 10:23:02 by kdouveno          #+#    #+#             */
/*   Updated: 2020/08/07 15:43:02 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"


void	ft_load_objs(t_obj *obj){ // gros caca a changer
	unsigned vbo, vao, ebo;

	glGenVertexArrays(1, &vao); 
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);
	glBindVertexArray(vao);
	
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, obj->faces_size * sizeof(t_face), obj->faces_vbo, GL_STATIC_DRAW);
	printf("%lu %lu", obj->faces_size, obj->faces_size * sizeof(t_face));
	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(sizeof(float) * 3));
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(sizeof(float) * 5));
	glEnableVertexAttribArray(0);

	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glBindVertexArray(0);
	obj->vao = vao;
}
