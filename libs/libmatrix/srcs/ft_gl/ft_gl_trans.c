/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gl_trans.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdouveno <kdouveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 12:06:52 by kdouveno          #+#    #+#             */
/*   Updated: 2020/01/15 10:17:58 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_gl.h"

t_mat	ft_trans_mat(float x, float y, float z)
{
	t_mat out;
	
	out = g_id_mat;
	out.d = (t_vec){x, y, z, 1};
	return (out);
}

t_mat	ft_scale_mat(float x, float y, float z)
{
	t_mat out;

	out = g_id_mat;
	out.a.a = x;
	out.b.b = y;
	out.c.c = z;
	return (out);
}

t_mat	ft_rotation(float x, float y, float z, float angle)
{
	t_fm44		out;
	float		co;
	float		so;
	float		mco;

	co = cos(angle);
	so = sin(angle);
	mco = 1 - co;
	out = (t_fm44){
		{co + x * x * mco, y * x * mco + z * so, z * x * mco - y * so, 0},
		{x * y * mco - z * so, co + y * y * mco, z * y * mco + x * so, 0},
		{x * z * mco + y * so, y * z * mco - x * so, co + z * z * mco, 0},
		{0, 0, 0, 1}
	};
	return out;
} 