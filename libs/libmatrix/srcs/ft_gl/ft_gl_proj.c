/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gl_proj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdouveno <kdouveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 12:59:25 by kdouveno          #+#    #+#             */
/*   Updated: 2020/01/27 15:24:15 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_gl.h"

t_mat	ft_perspective(float angle, float aspect_ratio, float near, float far)
{
	float left;

	left = tan(angle) * near;
	return (ft_sym_proj(
		left,
		left / aspect_ratio,
		near,
		far
	));
}

t_mat	ft_sym_proj(float right, float top, float near, float far)
{
	t_mat out;

	out = g_id_mat;
	out.a.a = near / right;
	out.b.b = near / top;
	out.c.c = -(far + near) / (far - near);
	out.d.c = -2 * far * near / (far - near);
	out.d.d = 0;
	out.c.d = -1;
	return out;
}