/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtambra <talya_1998@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 21:41:55 by jtambra           #+#    #+#             */
/*   Updated: 2021/01/20 02:32:57 by jtambra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_check(char *remainder, int count)
{
	if ((count == -1) || (count == 0 && !remainder))
		return (count);
	return (1);
}

int		ft_n_exist(char **ptr_n, char **remainder)
{
	**ptr_n = '\0';
	(*ptr_n)++;
	if (!(*remainder = ft_strdup(*ptr_n)))
		return (-1);
	return (0);
}

int		ft_rem_exist(char **remainder, char **line, char **ptr_n)
{
	char	*box;

	if ((*ptr_n = (ft_strchr(*remainder, '\n'))))
	{
		**ptr_n = '\0';
		(*ptr_n)++;
		box = *line;
		if (!(*line = ft_strjoin(*line, *remainder)))
			return (-1);
		free(box);
		box = *remainder;
		if (!(*remainder = ft_strdup(*ptr_n)))
			return (-1);
	}
	else
	{
		box = *line;
		if (!(*line = ft_strjoin(*line, *remainder)))
			return (-1);
		free(box);
		box = *remainder;
		*remainder = NULL;
	}
	free(box);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	int			count;
	char		buf[BUFFER_SIZE + 1];
	static char	*remainder;
	char		*ptr_n;
	char		*box;

	count = 0;
	ptr_n = NULL;
	if (fd < 0 || BUFFER_SIZE < 1 || !line || (!((*line) = malloc(1))))
		return (-1);
	*line[0] = 0;
	if (remainder && (ft_rem_exist(&remainder, line, &ptr_n) == -1))
		return (-1);
	while (!remainder && (count = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[count] = '\0';
		if ((ptr_n = (ft_strchr(buf, '\n'))))
			if ((ft_n_exist(&ptr_n, &remainder)) == -1)
				return (-1);
		box = *line;
		if (!(*line = ft_strjoin(*line, buf)))
			return (-1);
		free(box);
	}
	return (ft_check(remainder, count));
}
