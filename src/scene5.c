/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 04:42:54 by smaksymy          #+#    #+#             */
/*   Updated: 2017/10/31 05:35:19 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void	fill_scene5_(t_mlx *i)
{
	i->p.s_point = vector(0, -500, 0);
	i->p.norm = vector(0, 1, 0);
	i->elem[3].color = color(0, 255, 0, 0);
	i->elem[3].elem = &i->p;
	i->elem[3].i = 3;
	i->cone.s_point = vector(0, 0, 0);
	i->cone.rot = vector(1, 1, 1);
	i->cone.a = 10 * (3.141592654 / 180);
	i->elem[4].color = color(255, 255, 255, 0);
	i->elem[4].elem = &i->cone;
	i->elem[4].i = 4;
}

void	fill_scene5(t_mlx *i)
{
	i->s.c = vector(0, 100, 500);
	i->s.r = 150;
	i->elem[0].color = color(0, 0, 255, 0);
	i->elem[0].elem = &i->s2;
	i->elem[0].i = 1;
	i->s2.c = vector(550, 500, 0);
	i->s2.r = 200;
	i->elem[1].color = color(255, 0, 255, 0);
	i->elem[1].elem = &i->s;
	i->elem[1].i = 1;
	i->c.s_point = vector(200, 400, 100);
	i->c.rot = vector(1, 0, 0);
	i->c.r = 200;
	i->elem[2].color = color(255, 0, 0, 0);
	i->elem[2].elem = &i->c;
	i->elem[2].i = 2;
	i->l.s_point = vector(0, 900, -3000);
	fill_scene5_(i);
}

void	scene_5(t_mlx *i, int mx, int p[2], int x[3])
{
	t_r		r_cur;

	r_cur.s_point = vector(800, 500, -2100);
	fill_scene5(i);
	x[0] = p[0] - 1;
	while (++x[0] < p[1])
	{
		while (++x[1] < mx)
			tracing(i, x[1], x[0], r_cur);
		x[1] = -1;
	}
}
