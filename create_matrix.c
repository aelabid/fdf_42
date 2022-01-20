/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 19:52:27 by aelabid           #+#    #+#             */
/*   Updated: 2022/01/09 20:22:29 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

int	numberofrows(int fd, int *nbrow)
{
	int		i;
	char	*str;

	i = 0;
	str = get_next_line(fd);
	if (str == NULL)
	{
		write(1, "Invalide file", 13);
		exit(1);
	}
	while (str != NULL)
	{
		free(str);
		str = get_next_line(fd);
		i++;
	}
	*nbrow = i;
	return (i);
}

void	error_map(void)
{
	write(2, "error map", 9);
	exit(1);
}

t_iso	**create_matrix(int numrow, int fd)
{
	t_iso	**matrix;
	int		i;
	int		numcol;
	char	*str;
	int		save;

	i = 0;
	matrix = malloc((numrow + 1) * sizeof(t_iso *));
	if (!matrix)
		return (NULL);
	str = get_next_line(fd);
	save = ft_numofcolumns(str, ' ');
	while (i < numrow)
	{
		free(str);
		numcol = ft_numofcolumns(str, ' ');
		if (numcol != save)
			error_map();
		matrix[i] = creat_line(str, numcol);
		str = get_next_line(fd);
		i++;
	}
	return (matrix);
}
