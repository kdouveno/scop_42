/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_globals.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdouveno <kdouveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 14:20:17 by kdouveno          #+#    #+#             */
/*   Updated: 2020/01/21 14:27:30 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_GLOBALS
#define TEST_GLOBALS
#include "stdio.h"

// static const float g_vertices[] = {
// 		-1.0f, 1.0f, 0.2f, // A face
// 		-0.6f, 1.0f, 0.2f,
// 		0.0f, -0.6f, 0.2f,
// 		0.6f, 1.0f, 0.2f,
// 		1.0f, 1.0f, 0.2f,
// 		0.0f, -1.0f, 0.2f,
		
// 		-1.0f, 1.0f, -0.2f, // B face
// 		-0.6f, 1.0f, -0.2f,
// 		0.0f, -0.6f, -0.2f,
// 		0.6f, 1.0f, -0.2f,
// 		1.0f, 1.0f, -0.2f,
// 		0.0f, -1.0f, -0.2f
// 	};
// static const unsigned g_indices[] = {
// 		0, 1, 5, // A face
// 		1, 5, 2,
// 		5, 2, 3,
// 		5, 3, 4,

// 		6, 7, 11, // B face
// 		7, 11, 8,
// 		11, 8, 9,
// 		11, 8, 10,

// 		0, 6, 5, // periph
// 		6, 5, 11,
// 		5, 11, 4,
// 		11, 4, 10,
// 		4, 10, 3,
// 		10, 3, 9,
// 		3, 9, 2,
// 		9, 2, 8,
// 		2, 8, 1,
// 		8, 1, 7,
// 		1, 7, 0,
// 		7, 0, 6
// 	};
static const float g_vertices[] = {
	.5,.5,.5,
	.5,.5,-.5,
	.5,-.5,.5,
	.5,-.5,-.5,
	-.5,.5,-.5,
	-.5,-.5,-.5,
	-.5,.5,.5,
	-.5,-.5,.5
};


static const unsigned g_indices[] = {
	0, 1, 2,
	1, 2, 3,

	1, 3, 4,
	3, 4, 5,

	4, 5, 6,
	5, 6, 7,

	6, 7, 0,
	7, 0, 2,

	1, 4, 6,
	1, 6, 0,

	2, 5, 7,
	2, 3, 5	
};



static const char *g_vertex_shader_source = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
	"uniform mat4 transmat;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = transmat * vec4(aPos, 1.0);\n"
    "}\0";
static const char *g_fragment_shader_source = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";

#endif // TEST_GLOBALS
