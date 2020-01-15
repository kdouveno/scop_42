/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmat44_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdouveno <kdouveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 13:37:10 by kdouveno          #+#    #+#             */
/*   Updated: 2020/01/15 10:17:22 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mat.h"

t_fm44	ft_fm44_add(t_fm44 a, t_fm44 b)
{
	return ((t_fm44){
		ft_fm14_add(a.a, b.a),
		ft_fm14_add(a.b, b.b),
		ft_fm14_add(a.c, b.c),
		ft_fm14_add(a.d, b.d)
	});
}

t_fm44	ft_fm44_spro(t_fm44 a, float s)
{
	return ((t_fm44){
		ft_fm14_spro(a.a, s),
		ft_fm14_spro(a.b, s),
		ft_fm14_spro(a.c, s),
		ft_fm14_spro(a.d, s)
	});
}

t_fm14	ft_fm44_fm14_pro(t_fm44 a, t_fm14 b)
{
	return (
		(t_fm14){
			a.a.a * b.a + a.b.a * b.b + a.c.a * b.c + a.d.a * b.d,
			a.a.b * b.a + a.b.b * b.b + a.c.b * b.c + a.d.b * b.d,
			a.a.c * b.a + a.b.c * b.b + a.c.c * b.c + a.d.c * b.d,
			a.a.d * b.a + a.b.d * b.b + a.c.d * b.c + a.d.d * b.d
		}
	);
}

t_fm44	ft_fm44_pro(t_fm44 a, t_fm44 b)
{
	return (
		(t_fm44){
			ft_fm44_fm14_pro(a, b.a),
			ft_fm44_fm14_pro(a, b.b),
			ft_fm44_fm14_pro(a, b.c),
			ft_fm44_fm14_pro(a, b.d)
		}
	);
}