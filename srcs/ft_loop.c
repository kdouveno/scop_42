/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdouveno <kdouveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 10:09:29 by kdouveno          #+#    #+#             */
/*   Updated: 2020/01/14 10:45:09 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"
#include <stdio.h>

void	ft_loop(void *data){
	t_obj *obj;

	obj = data;
	printf("is it looping\n");
	glClear(GL_COLOR_BUFFER_BIT);
	glUseProgram(obj->shader_programm);
	glBindVertexArray(obj->voa);
	glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}