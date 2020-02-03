/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdouveno <kdouveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:45:59 by kdouveno          #+#    #+#             */
/*   Updated: 2020/02/03 16:10:22 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

void	usage()
{
	printf("usage: ./scop <ObjFileName>");
	exit(1);
}

void	error(char *msg){
	printf("[FATAL ERROR]: %s", msg);
	exit(1);
}