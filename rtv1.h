/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 14:43:25 by smaksymy          #+#    #+#             */
/*   Updated: 2017/10/31 06:18:49 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _RTV1_H
# define _RTV1_H

# include "./libft/libft.h"
# include <mlx.h>
# include <pthread.h>
# include <math.h>

typedef	struct s_mlx	t_mlx;
typedef	struct s_cd		t_cd;
typedef	struct s_f		t_f;
typedef	struct s_col	t_col;
typedef	struct s_r		t_r;
typedef	struct s_ls		t_ls;
typedef	struct s_elem	t_elem;
typedef	struct s_s		t_s;
typedef	struct s_c		t_c;
typedef	struct s_l		t_l;
typedef	struct s_cone	t_cone;
typedef	struct s_p		t_p;

struct					s_col
{
	double				r;
	double				g;
	double				b;
	double				a;
};

struct					s_cd
{
	double				x;
	double				y;
	double				z;
};

struct					s_elem
{
	void				*elem;
	int					i;
	t_col				color;
};

struct					s_s
{
	double				r;
	t_col				color;
	t_cd				c;
};

struct					s_c
{
	double				r;
	t_cd				s_point;
	t_cd				rot;
	t_col				color;
};

struct					s_r
{
	t_cd				s_point;
	t_cd				r_dir;
};

struct					s_p
{
	t_cd				s_point;
	t_cd				norm;
	t_col				color;
};

struct					s_cone
{
	t_cd				s_point;
	t_cd				rot;
	double				a;
	t_col				color;
};

struct					s_l
{
	t_cd				s_point;
	t_col				pow;
};

struct					s_mlx
{
	void				*mlx;
	void				*win;
	char				*title;
	double				rotx;
	double				roty;
	double				rotz;
	double				max;
	t_cd				re_p;
	t_cd				l_range;
	t_cd				z;
	void				*img;
	char				*tab;
	int					bpp;
	int					sl;
	int					e;
	char				*av;
	int					fn;
	int					ch;
	t_elem				elem[8];
	t_l					l;
	t_l					l2;
	t_c					c;
	t_c					c2;
	t_s					s;
	t_s					s2;
	t_p					p;
	t_p					p2;
	t_cone				cone;
	t_cone				cone2;
};

struct					s_f
{
	t_mlx				*i;
	int					y;
};

void					my_run(t_mlx *i, char *av);
void					my_hooks(t_mlx *i);
int						key_hook(int keycode, t_mlx *info);
void					init_info(t_mlx *i);
void					make_im(t_mlx *i);
void					add_f(t_mlx *i);
void					*operate_fl(void *th);
void					scene_3(t_mlx *i, int mx, int p[2], int x[3]);
void					fill_scene3(t_mlx *i);
void					scene_2(t_mlx *i, int mx, int p[2], int x[3]);
void					fill_scene2(t_mlx *i);
void					scene_1(t_mlx *i, int mx, int p[2], int x[3]);
void					fill_scene1(t_mlx *i);
void					scene_4(t_mlx *i, int mx, int p[2], int x[3]);
void					fill_scene4(t_mlx *i);
void					scene_5(t_mlx *i, int mx, int p[2], int x[3]);
void					fill_scene5(t_mlx *i);
void					fill_scene5_(t_mlx *i);
void					tracing(t_mlx *i, int x, int y, t_r r_cur);
void					put_point(t_mlx *i, t_r *r_sh, double l[3], int c_elem);
void					draw_pix(t_mlx *i, int c_elem, t_cd *dir, double l[3]);
t_r						take_sh(t_mlx *i, t_r *r);
int						take_hit(t_mlx *t, t_r *r, double l, int i);
t_cd					check_rotation(t_mlx *i, int x, int y, t_cd *dir);
t_cd					check_rot_x(t_cd *v, double a);
t_cd					check_rot_y(t_cd *v, double a);
t_cd					check_rot_z(t_cd *v, double a);
int						hit(t_elem *elem, t_r *r, t_mlx *i, double max);
int						hit_s(t_r *r, void *elem, t_mlx *i, double max);
int						hit_c(t_r *r, t_c *c, t_mlx *i, double max);
int						hit_cone(t_r *r, t_cone *cone, t_mlx *i, double max);
int						hit_p(t_r *r, void *elem, t_mlx *i, double max);
t_cd					c_take(t_r *r, t_c *c, t_cd *dist);
t_cd					cone_take(t_r *r, t_cone *cone, t_cd *dist);
t_cd					take_norm(t_elem *elem, t_cd *s_point, t_cd *s);
t_cd					cone_norm(t_cd *s_point, t_cone *cone);
t_cd					p_norm(t_p *p, t_cd *s);
t_cd					s_norm(t_cd *s_point, t_s *s);
t_cd					c_norm(t_cd *s_point, t_c *cl);
t_cd					vector(double x, double y, double z);
t_col					color(double b, double g, double r, double a);
t_cd					norm(t_cd *v);
double					v_op(t_cd *v1, t_cd *v2);
t_cd					v_zoom(t_cd *v, double f);
t_cd					v_sum(t_cd *v1, t_cd *v2);
t_cd					v_sub(t_cd *v1, t_cd *v2);
double					v_cos(t_cd *v1, t_cd *v2);
void					pixel_put(t_mlx *i, int x, int y, t_col c);
int						exit_hook(t_mlx *info);
int						ft_error_check(int n);

#endif
