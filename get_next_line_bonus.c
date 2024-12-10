/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pximenez <pximenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:49:13 by pximenez          #+#    #+#             */
/*   Updated: 2024/01/12 12:52:42 by pximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_save_rest_static(char *static_var_in, char *line)
{
	int		i_0;
	int		i_f;
	char	*static_var_out;

	if (static_var_in == NULL)
		return (NULL);
	i_f = ft_strlen(static_var_in);
	i_0 = ft_strlen(line);
	static_var_out = (char *) malloc ((i_f - i_0 + 1) * sizeof(char));
	if (!(static_var_out))
	{
		free(static_var_in);
		return (NULL);
	}
	i_f = 0;
	while (static_var_in[i_0 + i_f] != 0)
	{
		static_var_out[i_f] = static_var_in[i_f + i_0];
		i_f++;
	}
	static_var_out[i_f] = 0;
	free(static_var_in);
	return (static_var_out);
}

char	*ft_save_line(char *static_var_in)
{
	char	*line_out;
	int		i_0;
	int		i_f;

	if (static_var_in == NULL)
		return (NULL);
	i_0 = 0;
	i_f = 0;
	while (static_var_in[i_f] != '\n' && static_var_in[i_f] != 0)
		i_f++;
	if (static_var_in[i_f] == '\n')
		i_f++;
	line_out = (char *) malloc ((i_f + 1) * sizeof(char));
	if (!(line_out))
		return (NULL);
	while (i_0 < i_f)
	{
		line_out[i_0] = static_var_in[i_0];
		i_0++;
	}
	line_out[i_0] = 0;
	return (line_out);
}

char	*ft_add_to_static_2(int bytes_read, char *buf, char *static_var_in)
{
	if (bytes_read == -1)
	{
		if (static_var_in != NULL)
			free(static_var_in);
		if (buf != NULL)
		{
			buf[0] = 0;
			free(buf);
		}
		return (NULL);
	}
	buf[bytes_read] = 0;
	if (!static_var_in)
	{
		if (buf[0] != '\0')
			return (buf);
		free (buf);
		return (NULL);
	}
	if (ft_end(buf, static_var_in) == 0)
		return (NULL);
	static_var_in = ft_strjoin(static_var_in, buf);
	return (static_var_in);
}

char	*ft_add_to_static(int fd, char *static_var_in)
{
	int		bytes_read;
	char	*buf;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		buf = (char *) malloc (BUFFER_SIZE + 1);
		if (!buf)
		{
			if (static_var_in != NULL)
				free(static_var_in);
			return (NULL);
		}
		bytes_read = read(fd, buf, BUFFER_SIZE);
		static_var_in = ft_add_to_static_2(bytes_read, buf, static_var_in);
		if (static_var_in == NULL)
			return (NULL);
		if (ft_strchr(static_var_in, '\n') == 1)
			return (static_var_in);
	}
	return (static_var_in);
}

char	*get_next_line(int fd)
{
	static char	*static_var[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (static_var[fd] != NULL)
	{
		if (ft_strchr(static_var[fd], '\n') == 1)
		{
			line = ft_save_line(static_var[fd]);
			static_var[fd] = ft_save_rest_static(static_var[fd], line);
			return (line);
		}
	}
	static_var[fd] = ft_add_to_static(fd, static_var[fd]);
	line = ft_save_line(static_var[fd]);
	static_var[fd] = ft_save_rest_static(static_var[fd], line);
	return (line);
}

/* int	main(void)
{
	int	fd;
	int	i;

	i = 0;
	fd = open("text_2.txt", O_RDONLY);
	while (i < 1)
	{
		printf("%s", get_next_line(fd));
		i++;
	}
	while(42);
} */
