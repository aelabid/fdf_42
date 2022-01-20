/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 12:13:27 by aelabid           #+#    #+#             */
/*   Updated: 2022/01/18 17:57:58 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include"mlx.h"
# include<stdlib.h>
# include"get_next_line.h"
# include<math.h>

typedef struct t_iso
{
	int		height;
	int		color;
}	t_iso;

typedef struct s_data {
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}				t_data;

typedef struct s_mlx
{
	void	*img;
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx;

typedef struct s_point
{
	int	x;
	int	y;
}				t_point;
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		numberofrows(int fd, int *nbrow);
int		ft_atoi(const char *c);
int		ft_convert(char *str);
char	**ft_split(char const *s, char c);
int		openfd(char *ac);
t_iso	*creat_line(char *str, int numcol);
int		ft_numofcolumns(char *s, char spl);
t_iso	**create_matrix(int numrow, int fd);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	iso(int *x, int *y, int z);
void	line(t_point *f, t_point *s, t_data img, int color);
void	drawmap(int zoom, t_data img, int fd, char *path);
int		ft_zoom(char *path);
int		handle_input(int keysym, t_mlx *mlx);
#endif
