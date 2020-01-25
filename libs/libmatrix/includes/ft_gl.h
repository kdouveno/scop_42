/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gl.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdouveno <kdouveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:47:44 by kdouveno          #+#    #+#             */
/*   Updated: 2020/01/15 10:50:55 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ft_mat.h"

typedef t_fm44 t_mat;
typedef t_fm14 t_vec;
static const t_mat g_id_mat = {
		{1,0,0,0},
		{0,1,0,0},
		{0,0,1,0},
		{0,0,0,1}
};

t_mat	ft_trans_mat(float x, float y, float z);
t_mat	ft_scale_mat(float x, float y, float z);
t_mat	ft_rot_mat(float x, float y, float z, float angle);
