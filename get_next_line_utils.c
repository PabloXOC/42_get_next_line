/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paxoc01 <paxoc01@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:12:01 by paxoc01           #+#    #+#             */
/*   Updated: 2024/01/07 14:36:40 by paxoc01          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t		len;

	len = 0;
	while (*s != '\0')
	{
		s = s + 1;
		len++;
	}
	return (len);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dst_ptr;
	char	*src_ptr;

	dst_ptr = (char *)dst;
	src_ptr = (char *)src;
	if (dst_ptr == NULL && src_ptr == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dst_ptr[i] = src_ptr[i];
		i++;
	}
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len_1;
	int		len_2;

	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	str = (char *)malloc((len_1 + len_2 + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s1, len_1);
	ft_memcpy(&str[len_1], s2, len_2);
	str[len_1 + len_2] = 0;
	return (str);
}

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == (unsigned char)c)
			return (1);
		i++;
	}
	if (s[i] == (unsigned char)c)
		return (1);
	return (0);
}

// int	main(void)
// {
// 	printf("%s\n", static_var("hello"));
// 	printf("%s\n", static_var("aa"));
// }
