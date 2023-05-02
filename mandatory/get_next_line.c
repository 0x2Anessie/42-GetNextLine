/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nessie <nessie@student.42.fr>  	        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:26:15 by nessie	           #+#    #+#             */
/*   Updated: 2023/03/29 15:38:40 by nessie	          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *stash)
{
	char	*buff;
	int		nbr_of_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	nbr_of_bytes = 1;
	while (!ft_strchr(stash, '\n') && nbr_of_bytes != 0)
	{
		nbr_of_bytes = read(fd, buff, BUFFER_SIZE);
		if (nbr_of_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[nbr_of_bytes] = '\0';
		stash = ft_strjoin(stash, buff);
	}
	free(buff);
	return (stash);
}

char	*ft_line(char *stash)
{
	int		size;
	int		i;
	char	*str;

	size = 0;
	if (!stash[size])
		return (NULL);
	while (stash[size] && stash[size] != '\n')
		size++;
	str = (char *)malloc(sizeof(char) * (size + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		str[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		str[i] = stash[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_rab(char *stash)
{
	int		i;
	int		size;
	char	*rab;

	size = 0;
	while (stash[size] && stash[size] != '\n')
		size++;
	if (!stash[size])
	{
		free(stash);
		return (NULL);
	}
	rab = (char *)malloc(sizeof(char) * (ft_strlen(stash) - size + 1));
	if (!rab)
		return (NULL);
	size++;
	i = 0;
	while (stash[size])
		rab[i++] = stash[size++];
	rab[i] = '\0';
	free(stash);
	return (rab);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stash = ft_read(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_line(stash);
	stash = ft_rab(stash);
	return (line);
}
/*
int	main()
{
	int	fd;
	char	*line;

	fd = open("texte1.txt", O_RDONLY);
	line = get_next_line(fd);
	int i = 1;
	while (line)
	{
		printf("line %d: %s", i, line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (0);
}*/