/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdouveno <kdouveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 10:47:36 by kdouveno          #+#    #+#             */
/*   Updated: 2020/01/14 15:13:21 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct		s_fm14{
	float			a;
	float			b;
	float			c;
	float			d;
}					t_fm14;

typedef union		e_fmat14{
	float			t[4];
	t_fm14			l;
}					t_fmat14;


typedef struct		s_fm44{
	t_fm14			a;
	t_fm14			b;
	t_fm14			c;
	t_fm14			d;
}					t_fm44;

typedef union		e_fmat44{
	t_fmat14		m[4];
	float			t[16];
	t_fm44			l;
}					t_fmat44;

//					fm14
t_fm14	ft_fm14_add(t_fm14 a, t_fm14 b);
t_fm14	ft_fm14_neg(t_fm14 a);
t_fm14	ft_fm14_spro(t_fm14 a, float s);
//					fm44
t_fm44	ft_fm44_add(t_fm44 a, t_fm44 b);
t_fm44	ft_fm44_spro(t_fm44 a, float s);
t_fm14	ft_fm44_fm14_pro(t_fm44 a, t_fm14 b);
t_fm44	ft_fm44_pro(t_fm44 a, t_fm44 b);