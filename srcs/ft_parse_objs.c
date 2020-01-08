/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_objs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdouveno <kdouveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 15:17:21 by kdouveno          #+#    #+#             */
/*   Updated: 2020/01/08 15:58:34 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_parse_objs.h"
#include "../includes/test_globals.h"

t_obj ft_parse_obj(){
	return ((t_obj){vertices, faces});
}