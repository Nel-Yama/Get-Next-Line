/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-yama <nel-yama@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 23:32:28 by nel-yama          #+#    #+#             */
/*   Updated: 2025/05/14 23:32:28 by nel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*usrc;
	unsigned char		*udst;
	size_t				i;

	if (dst == src || len == 0)
		return (dst);
	usrc = (const unsigned char *)src;
	udst = (unsigned char *)dst;
	i = 0;
	if (udst > usrc && udst < usrc + len)
	{
		while (len--)
			udst[len] = usrc[len];
	}
	else
	{
		while (i < len)
		{
			udst[i] = usrc[i];
			i++;
		}
	}
	return (dst);
}

static char	*append_and_free(char *line, char *buff)
{
	char	*joined;

	joined = ft_strjoin(line, buff);
	free(line);
	return (joined);
}

static void	preserve_buffer(char *buff)
{
	char	*newline;
	size_t	size;

	newline = ft_strchr(buff, '\n');
	size = ft_strlen(buff, 0) - (newline - buff + 1);
	ft_memmove(buff, newline + 1, size);
	buff[size] = 0;
}

static char	*read_and_append(char *line, char *buff, int fd)
{
	ssize_t		num_read;

	num_read = read(fd, buff, BUFFER_SIZE);
	if (num_read <= 0)
	{
		buff[0] = 0;
		if (*line)
			return (line);
		free(line);
		return (NULL);
	}
	while (num_read > 0)
	{
		buff[num_read] = 0;
		line = append_and_free(line, buff);
		if (ft_strchr(line, '\n'))
		{
			preserve_buffer(buff);
			return (line);
		}
		num_read = read(fd, buff, BUFFER_SIZE);
	}
	buff[num_read] = 0;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strdup(buff);
	if (ft_strchr(line, '\n'))
	{
		preserve_buffer(buff);
		return (line);
	}
	line = read_and_append(line, buff, fd);
	return (line);
}
/**
int main(int argc, char **argv)
{
    int     fd;
    char    *line;

    if (argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return (1);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return (1);
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Line: %s", line); // line already includes '\n' if present
        free(line);
    }

    close(fd);
    return (0);
}
**/
