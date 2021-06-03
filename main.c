/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtambra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 22:28:06 by jtambra           #+#    #+#             */
/*   Updated: 2021/06/03 22:31:48 by jtambra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
	int		fd;
	char	*line;

	int count = 1;
	int i = 1;

	while (i <= argc)
	{
		fd = open(argv[i], O_RDONLY);
		while ((count = get_next_line(fd, &line)) > 0)
		{
			printf("%s\n",line);
			free(line);
		}
		i++;
	}
	return (0);
}
