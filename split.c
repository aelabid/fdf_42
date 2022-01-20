/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 12:22:57 by aelabid           #+#    #+#             */
/*   Updated: 2022/01/07 12:22:58 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

static int	ft_gettheworld(const char *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	ft_numofsplit(const char *s, char spl)
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

static void	ft_inits(int *i, int *k)
{
	*i = -1;
	*k = -1;
}

static void	ft_free(char **spl)
{
	int	j;

	j = -1;
	while (spl[++j])
		free(spl[j]);
	free(spl);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**spl;
	int		k;

	ft_inits(&i, &k);
	if (!s)
		return (NULL);
	spl = malloc((ft_numofsplit(s, c) + 1) * sizeof(char *));
	if (spl == 0)
		return (NULL);
	while (s[++i])
	{
		if (s[i] != c)
		{
			spl[++k] = ft_substr(s, i, ft_gettheworld(s + i, c));
			if (!spl[k])
			{
				ft_free(spl);
				return (NULL);
			}
			i = i + ft_gettheworld(s + i, c) - 1;
		}
	}
	spl[++k] = NULL;
	return (spl);
}
