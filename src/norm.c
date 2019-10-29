/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 04:55:29 by smaksymy          #+#    #+#             */
/*   Updated: 2017/10/31 05:30:34 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

t_cd	s_norm(t_cd *s_point, t_s *s)
{
	t_cd	norme;
	double	h;

	norme = v_sub(s_point, &s->c);
	h = v_op(s_point, &s->c);
	norme = v_zoom(&norme, 1 / h);
	return (norme);
}

t_cd	p_norm(t_p *p, t_cd *s)
{
	t_cd	norme;

	norme = p->norm;
	if (v_cos(&norme, s) < 0)
		norme = v_zoom(&norme, -1);
	return (norme);
}

t_cd	cone_norm(t_cd *s_point, t_cone *cone)
{
	t_cd	norme;
	t_cd	c;
	double	temp;

	norme = v_sub(s_point, &cone->s_point);
	temp = v_op(&norme, &cone->rot);
	c = v_zoom(&cone->rot, temp);
	c = v_zoom(&c, (1 + pow(tan(cone->a), 2)));
	norme = v_sub(&norme, &c);
	norme = norm(&norme);
	return (norme);
}

t_cd	take_norm(t_elem *elem, t_cd *s_point, t_cd *s)
{
	t_cd	norm;

	norm = vector(0, 0, 0);
	if (elem->i == 1)
		return (s_norm(s_point, (t_s *)(elem->elem)));
	else if (elem->i == 2)
		return (c_norm(s_point, (t_c *)(elem->elem)));
	else if (elem->i == 3)
		return (p_norm((t_p *)(elem->elem), s));
	else if (elem->i == 4)
		return (cone_norm(s_point, (t_cone *)(elem->elem)));
	return (norm);
}

t_cd	cone_take(t_r *r, t_cone *cone, t_cd *dist)
{
	t_cd	a;

	a.x = v_op(&r->r_dir, &r->r_dir) - (1 + pow(tan(cone->a), 2)) *
		pow(v_op(&r->r_dir, &cone->rot), 2);
	a.y = 2 * (v_op(&r->r_dir, dist) - (1 + pow(tan(cone->a), 2)) *
				(v_op(&r->r_dir, &cone->rot) * v_op(dist, &cone->rot)));
	a.z = v_op(dist, dist) - (1 + pow(tan(cone->a), 2)) *
		pow(v_op(dist, &cone->rot), 2);
	return (a);
}
