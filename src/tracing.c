/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 04:44:43 by smaksymy          #+#    #+#             */
/*   Updated: 2017/10/31 05:39:29 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

int		take_hit(t_mlx *t, t_r *r, double l, int i)
{
	int		c_elem;
	int		n_elem;

	c_elem = -1;
	t->max = 200000.0;
	if (ft_strequ(t->av, "5"))
		n_elem = 5;
	else
		n_elem = 1;
	while (++i < n_elem)
		if (hit(&t->elem[i], r, t, l) == 1)
			c_elem = i;
	return (c_elem);
}

t_r		take_sh(t_mlx *i, t_r *r)
{
	t_r		r_sh;

	i->z = v_zoom(&r->r_dir, i->max);
	i->re_p = v_sum(&r->s_point, &i->z);
	i->l_range = v_sub(&i->l.s_point, &i->re_p);
	r_sh.s_point = i->re_p;
	r_sh.r_dir = norm(&i->l_range);
	return (r_sh);
}

void	draw_pix(t_mlx *i, int c_elem, t_cd *dir, double l[3])
{
	t_cd	norm;
	t_col	c_dark;

	norm = take_norm(&(i->elem[c_elem]), &i->re_p, dir);
	c_dark = i->elem[c_elem].color;
	c_dark.a = 230 * (1 - v_cos(&norm, dir));
	if (v_cos(&norm, dir) >= 0.94)
	{
		c_dark.r += (255 - c_dark.r) * v_cos(&norm, dir) * 15;
		c_dark.g += (255 - c_dark.g) * v_cos(&norm, dir) * 15;
		c_dark.b += (255 - c_dark.b) * v_cos(&norm, dir) * 15;
	}
	pixel_put(i, l[1], l[2], c_dark);
}

void	put_point(t_mlx *i, t_r *r_sh, double l[3], int c_elem)
{
	if (take_hit(i, r_sh, l[0], -1) == -1)
		draw_pix(i, c_elem, &r_sh->r_dir, l);
	else
	{
		i->elem[c_elem].color.a = 230;
		pixel_put(i, l[1], l[2], (i->elem[c_elem].color));
	}
}

void	tracing(t_mlx *i, int x, int y, t_r r_cur)
{
	t_r		r_sh;
	double	l;
	int		c_elem;
	double	w[3];

	w[0] = l;
	w[1] = x;
	w[2] = y;
	r_cur.r_dir = check_rotation(i, x, y, &r_cur.r_dir);
	c_elem = take_hit(i, &r_cur, 250000, -1);
	if (c_elem >= 0)
	{
		r_sh = take_sh(i, &r_cur);
		l = sqrt(v_op(&i->l_range, &i->l_range));
		put_point(i, &r_sh, w, c_elem);
	}
}
