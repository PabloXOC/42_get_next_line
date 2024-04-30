/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paxoc01 <paxoc01@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:11:56 by paxoc01           #+#    #+#             */
/*   Updated: 2024/01/10 18:58:29 by paxoc01          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*save_rest_in_static(char *static_in, char *buffer)
{
	size_t	i_pos;
	size_t	f_pos;
	size_t	i;
	char	*static_out;

	if (!(static_in) || !(buffer))
		return (NULL);
	i_pos = 0;
	while (buffer[i_pos] != '\n' && buffer[i_pos] != 0)
		i_pos++;
	if (buffer[i_pos] == '\n' && buffer[i_pos] != 0)
		i_pos++;
	f_pos = ft_strlen(&buffer[i_pos]);
	static_out = (char *) malloc ((f_pos - i_pos + 1) * sizeof(char));
	if (!(static_out))
		return (NULL);
	i = 0;
	while (i < (f_pos - i_pos))
	{
		static_out[i] = buffer[i_pos + i];
		i++;
	}
	static_out[i] = 0;
	free(static_in);
	return (static_out);
}

char	*save_line(char *buffer)
{
	size_t	i_pos;
	size_t	i;
	char	*return_line;

	if (!(buffer))
		return (NULL);
	i_pos = 0;
	while (buffer[i_pos] != '\n' && buffer[i_pos] != 0)
		i_pos++;
	if (buffer[i_pos] == '\n' && buffer[i_pos] != 0)
		i_pos++;
	return_line = (char *) malloc ((i_pos + 1) * sizeof(char));
	if (!(return_line))
		return (NULL);
	i = 0;
	while (i < i_pos)
	{
		return_line[i] = buffer[i];
		i++;
	}
	return_line[i] = 0;
	return (return_line);
}

char	*ft_read_buf(int fd, char *in_buf)
{
	char	buf[BUFFER_SIZE];
	int		len;
	char	*out_buf;

	len = read(fd, buf, sizeof(buf));
	if (len == -1)
		return (NULL);
	buf[len] = 0;
	out_buf = ft_strjoin(in_buf, buf);
	if (!out_buf)
		return (NULL);
	return (out_buf);
}

char	*get_buf(int fd, char *buf)
{
	size_t	len;

	if (!(buf))
		return (NULL);
	while (ft_strchr(buf, '\n') == 0)
	{
		len = ft_strlen(buf);
		buf = ft_read_buf(fd, buf);
		if (buf == NULL)
			return (NULL);
		if (strlen(buf) == len)
			break ;
	}
	return (buf);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*static_var;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (static_var == 0)
	{
		static_var = (char *) malloc (1 * sizeof(char));
		static_var[0] = 0;
	}
	if (ft_strchr(static_var, '\n') == 1)
	{
		line = save_line(static_var);
		static_var = save_rest_in_static(static_var, static_var);
		return (line);
	}
	buf = ft_read_buf(fd, static_var);
	buf = get_buf(fd, buf);
	static_var = save_rest_in_static(static_var, buf);
	line = save_line(buf);
	free(buf);
	return (line);
}

// int	main(void)
// {
// 	int	fd;
// 	int	i;

// 	i = 0;
// 	fd = open("text.txt", O_RDONLY);
// 	while (i < 28)
// 	{
// 		printf("%s", get_next_line(12));
// 		i++;
// 	}
// }
