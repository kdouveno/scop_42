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
	lst_each(obj->v, &each_print_vector);
	printf("vt ");
	lst_each(obj->vt, &each_print_vector);
	printf("vn ");
	lst_each(obj->vn, &each_print_vector);
	lst_each(obj->f, &each_print_indices);
}