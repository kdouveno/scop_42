/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_mat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdouveno <kdouveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:05:14 by kdouveno          #+#    #+#             */
/*   Updated: 2020/01/27 15:21:22 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mat.h"
#include <stdio.h>
void	ft_print_mat14(t_fm14 in){
	printf("[%f, %f, %f, %f]", in.a, in.b, in.c, in.d);
}

void	ft_print_mat44(t_fm44 in){
	printf(	"[%6.2f, %6.2f, %6.2f, %6.2f]\n"
			"[%6.2f, %6.2f, %6.2f, %6.2f]\n"
			"[%6.2f, %6.2f, %6.2f, %6.2f]\n"
			"[%6.2f, %6.2f, %6.2f, %6.2f].\n",
			in.a.a, in.b.a, in.c.a, in.d.a,
			in.a.b, in.b.b, in.c.b, in.d.b,
			in.a.c, in.b.c, in.c.c, in.d.c,
			in.a.d, in.b.d, in.c.d, in.d.d
	);
}