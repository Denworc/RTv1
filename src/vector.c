/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 04:58:40 by smaksymy          #+#    #+#             */
/*   Updated: 2017/10/31 05:26:02 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

double	v_op(t_cd *v1, t_cd *v2)
{
	double	v;

	v = (v1->x * v2->x) + (v1->y * v2->y) + (v1->z * v2->z);
	return (v);
}

t_cd	norm(t_cd *v)
{
	t_cd	v1;
	double	l;

	l = sqrt(v_op(v, v));
	v1 = v_zoom(v, 1 / l);
	return (v1);
}

t_col	color(double b, double g, double r, double a)
{
	t_col	res;

	res.r = r;
	res.g = g;
	res.b = b;
	res.a = a;
	return (res);
}

t_cd	vector(double x, double y, double z)
{
	t_cd	res;

	res.x = x;
	res.y = y;
	res.z = z;
	return (res);
}

t_cd	c_norm(t_cd *s_point, t_c *cl)
{
	t_cd	norme;
	t_cd	c;
	double	temp;

	norme = v_sub(s_point, &cl->s_point);
	temp = v_op(&norme, &cl->rot);
	c = v_zoom(&cl->rot, temp);
	norme = v_sub(&norme, &c);
	norme = norm(&norme);
	return (norme);
}
