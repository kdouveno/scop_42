/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exits.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdouveno <kdouveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:02:00 by kdouveno          #+#    #+#             */
/*   Updated: 2020/02/04 15:59:22 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXITS_H
# define FT_EXITS_H
# define OPEN_FILE_ERROR "An error occured while opening file."
# define DYNAMIC_ALLOCATION_ERROR "An error occured while allocating memory (malloc returned null pointer)."

void			usage();
void			error(char *msg);
#endif