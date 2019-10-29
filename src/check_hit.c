/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_hit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 04:50:47 by smaksymy          #+#    #+#             */
/*   Updated: 2017/10/31 05:29:39 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

t_cd	c_take(t_r *r, t_c *c, t_cd *dist)
{
	t_cd	a;

	a.x = v_op(&r->r_dir, &r->r_dir) - pow(v_op(&r->r_dir, &c->rot), 2);
	a.y = 2 * (v_op(&r->r_dir, dist) - (v_op(&r->r_dir, &c->rot) *
										v_op(dist, &c->rot)));
	a.z = v_op(dist, dist) - pow(v_op(dist, &c->rot), 2) - c->r * c->r;
	return (a);
}

int		hit_p(t_r *r, void *elem, t_mlx *i, double max)
{
	double	d;
	t_cd	pl;
	t_p		*p;
	double	t;

	p = (t_p *)(elem);
	d = v_op(&p->norm, &r->r_dir);
	if (fabs(d) > 0.001)
	{
		pl = v_sub(&p->s_point, &r->s_point);
		t = v_op(&pl, &p->norm) / d;
		if (t > 0.001 && t < i->max)
		{
			i->max = t - 0.1;
			if (i->max > max)
				return (0);
			return (1);
		}
		else
			return (0);
	}
	return (0);
}

int		hit_cone(t_r *r, t_cone *cone, t_mlx *i, double max)
{
	t_cd	dist;
	t_cd	tab;
	t_cd	tab1;
	double	d;
	int		ret;

	ret = 0;
	dist = v_sub(&cone->s_point, &r->s_point);
	cone->rot = norm(&cone->rot);
	tab = cone_take(r, cone, &dist);
	d = tab.y * tab.y - 4 * tab.x * tab.z;
	if (d < 0)
		return (ret);
	tab1.x = (tab.y - sqrt(d)) / (2 * tab.x);
	tab1.y = (tab.y + sqrt(d)) / (2 * tab.x);
	(tab1.x > 0.001) && (tab1.x < i->max) ? ret = 1 : 0;
	(tab1.x > 0.001) && (tab1.x < i->max) ? i->max = tab1.x : 0;
	(tab1.y > 0.001) && (tab1.y < i->max) ? ret = 1 : 0;
	(tab1.y > 0.001) && (tab1.y < i->max) ? i->max = tab1.y : 0;
	i->max -= 0.01;
	if (i->max > max)
		return (0);
	return (ret);
}

int		hit_c(t_r *r, t_c *c, t_mlx *i, double max)
{
	t_cd	dist;
	t_cd	tab;
	t_cd	tab1;
	double	d;
	int		ret;

	ret = 0;
	dist = v_sub(&c->s_point, &r->s_point);
	c->rot = norm(&c->rot);
	tab = c_take(r, c, &dist);
	d = tab.y * tab.y - 4 * tab.x * tab.z;
	if (d < 0)
		return (ret);
	tab1.x = (tab.y - sqrt(d)) / (2 * tab.x);
	tab1.y = (tab.y + sqrt(d)) / (2 * tab.x);
	(tab1.x > 0.001) && (tab1.x < i->max) ? ret = 1 : 0;
	(tab1.x > 0.001) && (tab1.x < i->max) ? i->max = tab1.x : 0;
	(tab1.y > 0.001) && (tab1.y < i->max) ? ret = 1 : 0;
	(tab1.y > 0.001) && (tab1.y < i->max) ? i->max = tab1.y : 0;
	i->max -= 0.01;
	if (i->max > max)
		return (0);
	return (ret);
}

int		hit_s(t_r *r, void *elem, t_mlx *i, double max)
{
	t_cd	dist;
	t_cd	tab;
	t_cd	tab1;
	t_s		*s;
	int		ret;

	ret = 0;
	s = (t_s *)(elem);
	dist = v_sub(&s->c, &r->s_point);
	tab.x = v_op(&r->r_dir, &dist);
	tab.y = tab.x * tab.x - v_op(&dist, &dist) + s->r * s->r;
	if (tab.y < 0.0)
		return (0);
	tab1.x = tab.x - sqrt(tab.y);
	tab1.y = tab.x + sqrt(tab.y);
	(tab1.x > 0.001) && (tab1.x < i->max) ? ret = 1 : 0;
	(tab1.x > 0.001) && (tab1.x < i->max) ? i->max = tab1.x : 0;
	(tab1.y > 0.001) && (tab1.y < i->max) ? ret = 1 : 0;
	(tab1.y > 0.001) && (tab1.y < i->max) ? i->max = tab1.y : 0;
	i->max -= 0.01;
	if (i->max > i->max)
		return (0);
	return (ret);
}
