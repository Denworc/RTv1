/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sum.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 05:00:33 by smaksymy          #+#    #+#             */
/*   Updated: 2017/10/31 05:30:20 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void	pixel_put(t_mlx *i, int x, int y, t_col c)
{
	int		z;

	z = y * i->sl + x * (i->bpp / 8);
	if (x < 1000 && x > 0 && y < 800 && y > 0)
	{
		i->tab[z] = c.b;
		i->tab[z + 1] = c.g;
		i->tab[z + 2] = c.r;
		i->tab[z + 3] = c.a;
	}
}

double	v_cos(t_cd *v1, t_cd *v2)
{
	double	cos;

	cos = (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z) /
		(sqrt(v1->x * v1->x + v1->y * v1->y + v1->z * v1->z)
		* sqrt(v2->x * v2->x + v2->y * v2->y + v2->z * v2->z));
	return (cos);
}

t_cd	v_sub(t_cd *v1, t_cd *v2)
{
	t_cd	v;

	v.x = v1->x - v2->x;
	v.y = v1->y - v2->y;
	v.z = v1->z - v2->z;
	return (v);
}

t_cd	v_sum(t_cd *v1, t_cd *v2)
{
	t_cd	v;

	v.x = v1->x + v2->x;
	v.y = v1->y + v2->y;
	v.z = v1->z + v2->z;
	return (v);
}

t_cd	v_zoom(t_cd *v, double f)
{
	t_cd	v1;

	v1.x = v->x * f;
	v1.y = v->y * f;
	v1.z = v->z * f;
	return (v1);
}
