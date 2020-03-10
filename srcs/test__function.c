#include "../includes/ft_obj.h"
#include "../includes/ft_parse_objs.h"

void				each_print_vector(void *ptr, size_t index){
	t_vec	*vec;

	(void)index;
	vec = (t_vec*)ptr;
	printf("%f %f %f %f\n", vec->a, vec->b, vec->c, vec->d);
}

void				each_print_indices(void *ptr, size_t index){
	t_face_indices	*indices;

	(void)index;
	indices = (t_face_indices*)ptr;
	printf("f %d/%d/%d %d/%d/%d %d/%d/%d\n",
			indices->v1,
			indices->vt1,
			indices->vn1,
			indices->v2,
			indices->vt2,
			indices->vn2,
			indices->v3,
			indices->vt3,
			indices->vn3
	);
}

void				test__print_parse_obj(t_obj_parsing *obj)
{
	printf("v ");
	lst_each_i(obj->v, &each_print_vector);
	printf("vt ");
	lst_each_i(obj->vt, &each_print_vector);
	printf("vn ");
	lst_each_i(obj->vn, &each_print_vector);
	lst_each_i(obj->f, &each_print_indices);
}

void				test__print_parsed_obj_vbo(t_obj *t_obj)
{
	size_t i;

	i = 0;
	while (i < t_obj->faces_size)
	{
		printf("f%lu\n"
		"\t%8.6f %8.6f %8.6f | %8.6f %8.6f | %8.6f %8.6f %8.6f\n"
		"\t%8.6f %8.6f %8.6f | %8.6f %8.6f | %8.6f %8.6f %8.6f\n"
		"\t%8.6f %8.6f %8.6f | %8.6f %8.6f | %8.6f %8.6f %8.6f\n",
			i,
			t_obj->faces_vbo[i].f1.vx,
			t_obj->faces_vbo[i].f1.vy,
			t_obj->faces_vbo[i].f1.vz,
			t_obj->faces_vbo[i].f1.vtx,
			t_obj->faces_vbo[i].f1.vty,
			t_obj->faces_vbo[i].f1.vnx,
			t_obj->faces_vbo[i].f1.vny,
			t_obj->faces_vbo[i].f1.vnz,
			t_obj->faces_vbo[i].f2.vx,
			t_obj->faces_vbo[i].f2.vy,
			t_obj->faces_vbo[i].f2.vz,
			t_obj->faces_vbo[i].f2.vtx,
			t_obj->faces_vbo[i].f2.vty,
			t_obj->faces_vbo[i].f2.vnx,
			t_obj->faces_vbo[i].f2.vny,
			t_obj->faces_vbo[i].f2.vnz,
			t_obj->faces_vbo[i].f3.vx,
			t_obj->faces_vbo[i].f3.vy,
			t_obj->faces_vbo[i].f3.vz,
			t_obj->faces_vbo[i].f3.vtx,
			t_obj->faces_vbo[i].f3.vty,
			t_obj->faces_vbo[i].f3.vnx,
			t_obj->faces_vbo[i].f3.vny,
			t_obj->faces_vbo[i].f3.vnz
		);
		i++;
	}
}