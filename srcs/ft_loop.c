/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdouveno <kdouveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 10:09:29 by kdouveno          #+#    #+#             */
/*   Updated: 2020/08/07 16:50:49 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"
#include "../libs/libmatrix/includes/ft_gl.h"
#include <sys/time.h>
#include <stdio.h>

void	ft_loop(void *data){
	t_obj			*obj;
	unsigned int	transformLoc;
	struct timeval  tv;
	double 			time;
	t_vec			tmp;
	
	gettimeofday(&tv, NULL);
	time = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000 ;
	time = (long)time % 5000;
	obj = data;
	t_mat trans = g_id_mat;

	tmp = ft_fm14_unit((t_vec){0.0f, 1.0f, 0.0f, 1.0f});
	trans = ft_fm44_pro(trans, ft_perspective(0.5f, 1.f, .1f, 20));
	trans = ft_fm44_pro(trans, ft_trans_mat(0.0f, 0.0f, -2.0f));
	trans = ft_fm44_pro(trans, ft_rot_mat(tmp.a, tmp.b, tmp.c, (int)time % 5000 * 2 * M_PI / 5000));
	trans = ft_fm44_pro(trans, ft_scale_mat(.2,.2,.2));

	glClear(GL_COLOR_BUFFER_BIT);
	glUseProgram(obj->shader_program);
	transformLoc = glGetUniformLocation(obj->shader_program, "transmat");
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, (float*)&trans);
	glBindVertexArray(obj->vao);
	glDrawArrays(GL_TRIANGLES, 0, obj->faces_size * 3);
	glBindVertexArray(0);
}