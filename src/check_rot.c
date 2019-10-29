/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 04:47:50 by smaksymy          #+#    #+#             */
/*   Updated: 2017/10/31 04:50:30 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

int		hit(t_elem *elem, t_r *r, t_mlx *i, double max)
{
	int		res;

	res = 0;
	if (elem->i == 1)
		res = hit_s(r, elem->elem, i, max);
	else if (elem->i == 2)
		res = hit_c(r, elem->elem, i, max);
	else if (elem->i == 3)
		res = hit_p(r, elem->elem, i, max);
	else if (elem->i == 4)
		res = hit_cone(r, elem->elem, i, max);
	return (res);
}

t_cd	check_rot_z(t_cd *v, double a)
{
	t_cd	res;

	res.x = v->x;
	res.y = v->y * cos(a * 3.141592654 / 180.0) +
		v->z * sin(a * 3.141592654 / 180.0);
	res.z = v->z * cos(a * 3.141592654 / 180.0) -
		v->y * sin(a * 3.141592654 / 180.0);
	return (res);
}

t_cd	check_rot_y(t_cd *v, double a)
{
	t_cd	res;

	res.x = v->x * cos(a * 3.141592654 / 180.0) -
		v->z * sin(a * 3.141592654 / 180.0);
	res.y = v->y;
	res.z = v->z * cos(a * 3.141592654 / 180.0) +
		v->x * sin(a * 3.141592654 / 180.0);
	return (res);
}

t_cd	check_rot_x(t_cd *v, double a)
{
	t_cd	res;

	res.x = v->x * cos(a * 3.141592654 / 180.0) +
		v->y * sin(a * 3.141592654 / 180.0);
	res.y = v->y * cos(a * 3.141592654 / 180.0) -
		v->x * sin(a * 3.141592654 / 180.0);
	res.z = v->z;
	return (res);
}

t_cd	check_rotation(t_mlx *i, int x, int y, t_cd *dir)
{
	t_cd	res;

	dir->x = (2 * ((x + 0.5) * 1 / (double)1000) - 1) *
		(tan((60 / 2 * 3.141592654 / 180.0))) * 1000 / (double)700;
	dir->y = (1 - 2 * ((y + 0.5) * 1 / (double)700)) *
		(tan((60 / 2 * 3.141592654 / 180.0)));
	dir->z = 1;
	res = check_rot_x(dir, i->rotx);
	res = check_rot_y(&res, i->roty);
	res = check_rot_z(&res, i->rotz);
	res = norm(&res);
	return (res);
}
