/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmat14_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdouveno <kdouveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 13:13:03 by kdouveno          #+#    #+#             */
/*   Updated: 2020/01/14 13:44:45 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mat.h"

t_fm14	ft_fm14_add(t_fm14 a, t_fm14 b)
{
	return ((t_fm14){a.a + b.a, a.b + b.b, a.c + b.c, a.d + b.d});
}

t_fm14	ft_fm14_neg(t_fm14 a)
{
	return ((t_fm14){-a.a, -a.b, -a.c, -a.d});
}

t_fm14	ft_fm14_spro(t_fm14 a, float s)
{
	return ((t_fm14){s * a.a, s * a.b, s * a.c, s * a.d});
}

