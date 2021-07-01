/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_cub3D.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:44:13 by mboy              #+#    #+#             */
/*   Updated: 2021/06/07 13:50:54 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_CUB3D_H
# define BONUS_CUB3D_H
# include "../../Sources/Utils/Libft/GNL/get_next_line.h"
# include "../../MiniLibX/mlx.h"
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# define ENTER          36
# define EXIT     		53
# define ROTATE_LEFT    123
# define ROTATE_RIGHT	124
# define FORWARD_W_Z	13
# define BACK_S_S		1
# define RIGHT_D_D		2
# define LEFT_A_Q		0
# define TEXT           11
# define COINS          17
# define STR            "Error While Trying to"

typedef struct s_parse
{
	int		mapX;
	int		mapY;
	int		resX;
	int		resY;
	int		play;
	int		playD;
	int		playX;
	int		playY;
	int		letter;
	int		sprites;
	char	**texture;
	char	**map;
}				t_parse;

typedef struct s_key
{
	int	enter;
	int	space_exit;
	int	forward_w_z;
	int	back_s_s;
	int	right_d_d;
	int	left_a_q;
	int	rotate_right;
	int	rotate_left;
}				t_key;

typedef struct s_calc
{
	int		save;
	int		drawEnd;
	int		drawStart;
	int		textNum;
	int		textX;
	int		textY;
	int		textW;
	int		textH;
	int		mapX;
	int		mapY;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	oldDirX;
	double	planX;
	double	planY;
	double	oldPlanX;
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpwallDist;
	double	moveSpeed;
	double	rotSpeed;
	double	lineHeight;
	double	ratio;
	double	wallX;
	double	step;
	double	textPos;
	double	*bufS;
}				t_calc;

typedef struct s_mlx
{
	int		bpp;
	int		len;
	int		cutX;
	int		cutY;
	int		resX;
	int		resY;
	int		endian;
	int		sqr_side;
	void	*win_ptr;
	void	*mlx_ptr;
	void	*img_ptr;
	char	*img_data;
	double	playXR;
	double	playYR;
	int		startX;
	int		endX;
	int		startY;
	int		endY;
}				t_mlx;

typedef struct s_wall
{
	t_mlx	*mlx;
	int		drawEnd;
	int		drawStart;
	int		textNum;
	int		textX;
	int		textY;
	int		textW;
	int		textH;
	int		mapX;
	int		mapY;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	double	wallX;
	double	step;
	double	textPos;
}			t_wall;

typedef struct s_game
{
	t_mlx	**mlx;
	int		coins;
	int		startH;
	int		startW;
	int		numH;
	int		numW;
	int		messW;
	int		messH;
	int		levelW;
	int		levelH;
	int		endW;
	int		endH;
	int		newX;
	int		newY;
	int		drawStartX;
	int		drawStartY;
	int		drawEndX;
	int		drawEndY;
	int		startX;
	int		startY;
	int		textX;
	int		textY;
	int		play;
	int		level;
	double	ratioX;
	double	ratioY;
}				t_game;

typedef struct s_floor
{
	int		textX;
	int		textY;
	double	floorX;
	double	floorY;
	double	floorWX;
	double	floorWY;
	double	dist;
	double	distW;
	double	distP;
	double	W;
}				t_floor;

typedef struct s_sprite
{
	t_mlx	*mlx;
	int		nb;
	int		x;
	int		y;
	int		pick;
	int		stripe;
	int		screenSX;
	int		spriteH;
	int		spriteW;
	int		drawStartY;
	int		drawEndY;
	int		drawStartX;
	int		drawEndX;
	int		texX;
	int		texY;
	double	distS;
	double	spriteX;
	double	spriteY;
	double	invDet;
	double	transX;
	double	transY;
}				t_sprite;

typedef struct s_cub
{
	t_key		*key;
	t_parse		*parse;
	t_calc		*calc;
	t_mlx		*ray;
	t_game		*game;
	t_wall		**wall;
	t_floor		*floor;
	t_sprite	**sprite;
}				t_cub;

int				main(int ac, char **av);
int				parse(char *str, t_cub *cub);
int				parse_check(char *line);
int				parse_line(char *line, t_cub *cub);
int				parse_line_select(char *line, int i, t_cub *cub);
int				parse_play(int x, int y, char c, t_cub *cub);
void			parse_size(char *line, t_cub *cub);
int				parse_res(char *line, t_cub *cub);
int				parse_res_limits(t_cub *cub);
char			*parse_res_fetch(char *line, int i);
int				parse_res_check(char *line);
void			parse_sprite(t_cub *cub, char *line);
int				parse_sprite_pos(t_cub *cub, char map, int x, int y);
int				parse_sprite_struct(t_cub *cub);
int				parse_tab(char *str, t_cub *cub);
int				parse_tab_line(char *str, t_cub *cub, int ret);
int				parse_tab_check(t_cub *cub);
int				parse_tab_check1(t_cub *cub, int y, int x);
int				parse_tab_fetch(char *line, int i, t_cub *cub);
int				parse_text(char *line, t_cub *cub);
int				parse_text_letters(char *line, int i, t_cub *cub);
int				parse_text_fetch(char *line, int text, int start, t_cub *cub);
int				parse_text_check(char *text);
int				parse_text_check1(char *line, int text, int start);
int				play(t_cub *cub);
int				play_struct(t_cub *cub);
void			play_struct_we(t_cub *cub);
void			play_struct_ns(t_cub *cub);
int				output(t_cub *cub);
int				output_start(t_cub *cub);
int				output_play(t_cub *cub);
int				output_level(t_cub *cub);
int				output_end(t_cub *cub);
int				game(t_cub *cub, int n);
int				game_reset(t_cub *cub, int level);
void			game_free(t_cub *cub);
void			game_coins(t_cub *cub);
void			game_draw(t_cub *cub, int n);
int				game_struct(t_cub *cub);
void			game_assign(t_cub *cub, char **game, int i);
char			**game_text(void);
void			prep(t_cub *cub, int n);
void			prep_lev(t_cub *cub);
void			prep_mess(t_cub *cub);
void			prep_num(t_cub *cub);
void			prep_start_end(t_cub *cub, int n);
int				map(t_cub *cub);
int				map_struct(t_cub *cub);
void			map_draw(t_cub *cub);
void			map_sqt(t_cub *cub, int i, int j);
void			map_play(t_cub *cub);
int				ray(t_cub *cub);
void			ray_hit_side(t_cub *cub);
void			ray_perp_h(t_cub *cub);
int				ray_end_start(t_cub *cub);
int				ray_pos_dir(t_cub *cub, int x);
void			ray_delta(t_cub *cub);
void			ray_step_side(t_cub *cub);
void			ray_step_side1(t_cub *cub);
int				walls(t_cub *cub, int x);
int				walls_struct(t_cub *cub);
int				walls_chose(t_cub *cub);
void			walls_calc(t_cub *cub);
void			walls_draw(t_cub *cub, int x);
int				floors(t_cub *cub, int x);
void			floors_struct(t_cub *cub);
void			floors_calc(t_cub *cub, int y);
int				sprites(t_cub *cub);
int				sprites_struct(t_cub *cub);
void			sprites_assign(t_cub *cub, int i);
void			sprites_sort(t_cub *cub);
void			sprites_calc(t_cub *cub, int i);
void			sprites_end_startY(t_cub *cub, int i);
void			sprites_end_startX(t_cub *cub, int i);
void			sprites_draw(t_cub *cub, int i);
void			sprites_draw_loop(t_cub *cub, int i);
int				move(t_cub *cub);
void			move_ver(t_cub *cub);
void			move_hor(t_cub *cub);
void			move_rignt(t_cub *cub);
void			move_left(t_cub *cub);
int				key_press(int keycode, t_cub *cub);
int				key_release(int keycode, t_cub *cub);
int				save(t_cub *cub);
void			save_header(t_cub *cub, int fd);
void			save_loop(t_cub *cub, int fd);
int				ex(t_cub *cub, int error, void *elem);
int				ex_mlx(t_cub *cub, int error);
void			ex_main(int error, void *elem);
void			ex_play(int error);
void			ex_save(int error);
void			gen_pixel(t_mlx *mlx, int x, int y, int color);
void			gen_fullscreen(t_mlx *mlx, int color);
void			gen_sqr(t_mlx *mlx, int sqr, int color, int colorline);
unsigned int	color_wall(t_cub *cub, int n);
unsigned int	color_floor(t_cub *cub, int n);
unsigned int	color_sprite(t_cub *cub, int n);
unsigned int	color_game(t_cub *cub, int n);
int				init(t_cub *cub);
int				init_parse_key_calc(t_cub *cub);
int				init_ray_text_game(t_cub *cub);
void			init_parse(t_parse *parse);
void			init_key(t_key *key);
void			init_mlx(t_mlx *mlx);
void			init_calc1(t_calc *calc);
void			init_calc2(t_calc *calc);
int				init_game1(t_game *game);
void			init_game2(t_game *game);
int				init_wall(t_wall *wall);
int				init_sprite(t_sprite *sprite);
void			init_floor(t_floor *floor);
int				is_map_c(char *line);
int				open_map(char *str);
void			swap(t_cub *cub, int swap1, int swap2);
int				update(t_cub *cub);
int				update1(t_cub *cub, int y, char **tmp);
int				update2(t_cub *cub, int x, int y);
int				update3(t_cub *cub, char **tmp);
int				copy_map(t_cub *cub, char *line, int i);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_nblen(int nb);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
double			ft_sqrt(double nb);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strdup(const char *s1);
size_t			ft_strlen(const char *s);

#endif
