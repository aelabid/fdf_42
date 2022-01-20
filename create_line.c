/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 08:22:34 by aelabid           #+#    #+#             */
/*   Updated: 2022/01/15 19:34:14 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	free_tab(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i] != NULL)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

int	ft_numofcolumns(char *s, char spl)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == spl)
			i++;
		if (s[i] != '\0')
			k++;
		while (s[i] && s[i] != spl)
			i++;
	}
	return (k);
}

void	err_malloc(t_iso *line)
{
	if (!line)
		write(2, "error Malloc", 12);
	exit(1);
}

void	file_line(t_iso *line, int hgt, int i)
{
	(line[i]).height = hgt;
	(line[i]).color = 0xffffff;
}

t_iso	*creat_line(char *str, int numcol)
{
	char	**split;
	char	**splitcolor;
	t_iso	*line;
	int		i;

	i = -1;
	split = ft_split(str, ' ');
	line = malloc((numcol + 1) * sizeof(t_iso));
	if (!line)
		err_malloc(line);
	while (++i < numcol)
	{
		if (ft_numofcolumns(split[i], ',') == 2)
		{
			splitcolor = ft_split(split[i], ',');
			(line[i]).height = ft_atoi(splitcolor[0]);
			(line[i]).color = ft_convert(splitcolor[1]);
			free_tab(splitcolor);
		}
		else
			file_line(line, ft_atoi(split[i]), i);
	}
	free_tab(split);
	line[i].color = -1;
	return (line);
}

// int	numberofrows(int fd, int *nbrow)
// {
// 	int		i;
// 	char	*str;
// 	i = 0;
// 	str = get_next_line(fd);
// 	if (str == NULL)
// 	{
// 		write(1, "Invalide file", 13);
// 		exit(1);
// 	}
// 	while (str != NULL)
// 	{
// 		free(str);
// 		str = get_next_line(fd);
// 		i++;
// 	}
// 	*nbrow = i;
// 	return (i);
// }
// t_iso	**create_matrix(int numrow, char *path, int fd)
// {
// 	t_iso		**matrix;
// 	char	*col;
// 	int		i;
// 	int		j;
// 	int		numcol;
// 	char *str;
// 	i = 0;
// 	j = 0;
// 	matrix = malloc((numrow + 1) * sizeof(t_iso *));
// 	if (!matrix)
// 		return (NULL);
// 	str = get_next_line(fd);
// 	while (i < numrow)
// 	{
// 		free(str);
// 	 	numcol = ft_numofcolumns(str, ' ');
// 		matrix[i] = creat_line(str, numcol);
// 		str = get_next_line(fd);
// 		i++;
// 	}
// 	return (matrix);
// }