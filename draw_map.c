/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 11:44:16 by aelabid           #+#    #+#             */
/*   Updated: 2022/01/19 17:02:06 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

int	number_col_matx(t_iso *mat)
{
	int	i;

	i = 0;
	while (mat[i].color != -1)
		i++;
	return (i);
}

t_point	*init(int x, int y)
{
	t_point	*p;

	p = malloc(sizeof(t_point));
	if (!p)
	{
		write(2, "error Malloc", 12);
		exit(1);
	}
	p->x = x;
	p->y = y;
	return (p);
}

t_point	*project(t_point *p, int z, int zoom)
{
	p->x *= zoom;
	p->y *= zoom;
	iso(&p->x, &p->y, z);
	p->x += 900;
	p->y += 200;
	return (p);
}

void	drawmap(int zoom, t_data img, int fd, char *path)
{
	int		i;
	int		j;
	int		nbrow;
	t_iso	**matrix;

	numberofrows(fd, &nbrow);
	matrix = create_matrix(nbrow, openfd(path));
	i = -1;
	while (++i < nbrow)
	{
		j = -1;
		while (++j < number_col_matx(matrix[i]))
		{
			if (j < number_col_matx(matrix[i]) - 1)
				line(project(init(j, i), (matrix[i])[j].height, zoom), project
					(init(j + 1, i), (matrix[i])[j + 1].height, zoom),
					img, (matrix[i])[j].color);
			if (i < nbrow -1)
				line(project(init(j, i), (matrix[i])[j].height, zoom), project
					(init(j, i + 1), (matrix[i + 1])[j].height, zoom),
					img, (matrix[i])[j].color);
		}
		free(matrix[i]);
	}
	free(matrix);
}
