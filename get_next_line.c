/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/07 17:53:19 by mdekker       #+#    #+#                 */
/*   Updated: 2023/02/25 18:04:28 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*concat(char *line, char *buff, int bufflen)
{
	t_concat_vars	v;

	v.i = 0;
	v.found = 0;
	v.j = 0;
	if (!bufflen)
		bufflen = 1;
	v.size = bufflen + 1;
	if (line != NULL)
		v.size += ft_strlen(line);
	v.new = ft_calloc(v.size, sizeof(char));
	if (!v.new)
		return (free(line), NULL);
	while (line != NULL && line[v.i])
	{
		v.new[v.i] = line[v.i];
		v.i++;
	}
	ft_copy_magic(&v, bufflen, buff);
	v.new[v.i] = '\0';
	return (free(line), v.new);
}

char	*read_line(t_gnl_buffer *buffer, char *line, int fd)
{
	int	found;
	int	bufflen;

	bufflen = 1;
	found = 0;
	while (bufflen > 0 && !found)
	{
		bufflen = read(fd, buffer->buff, BUFFER_SIZE);
		buffer->length = bufflen;
		if (bufflen == 0)
			break ;
		if (bufflen < 0)
		{
			free(line);
			return (NULL);
		}
		line = concat(line, buffer->buff, bufflen);
		if (ft_strchr_nl(buffer->buff, buffer->length))
			found = 1;
		get_remaining_buff(buffer);
	}
	return (line);
}

void	get_remaining_buff(t_gnl_buffer *buffer)
{
	int	i;
	int	j;

	i = 0;
	while (i < buffer->length && buffer->buff[i] != '\n')
		i++;
	if (i < buffer->length)
		i++;
	j = 0;
	while (i < buffer->length)
	{
		buffer->buff[j] = buffer->buff[i];
		i++;
		j++;
	}
	buffer->length = j;
}

char	*get_next_line(int fd)
{
	static t_gnl_buffer	buffer;
	char				*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (buffer.length > 0)
	{
		if (ft_strchr_nl(buffer.buff, buffer.length))
		{
			line = concat(line, buffer.buff, buffer.length);
			get_remaining_buff(&buffer);
			return (line);
		}
		else
		{
			line = concat(line, buffer.buff, buffer.length);
			buffer.length = 0;
		}
	}
	line = read_line(&buffer, line, fd);
	return (line);
}
