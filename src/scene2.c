/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 04:39:59 by smaksymy          #+#    #+#             */
/*   Updated: 2017/10/31 04:40:59 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void	fill_scene2(t_mlx *i)
{
	i->p.s_point = vector(0, -500, 0);
	i->p.norm = vector(0, 1, 0);
	i->elem[0].color = color(0, 255, 0, 0);
	i->elem[0].elem = &i->p;
	i->elem[0].i = 3;
	i->l.s_point = vector(2900, 1900, -1600);
}

void	scene_2(t_mlx *i, int mx, int p[2], int x[3])
{
	t_r		r_cur;

	r_cur.s_point = vector(800, 500, -2100);
	fill_scene2(i);
	x[0] = p[0] - 1;
	while (++x[0] < p[1])
	{
		while (++x[1] < mx)
			tracing(i, x[1], x[0], r_cur);
		x[1] = -1;
	}
}
