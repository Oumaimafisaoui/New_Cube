/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:05:19 by ataji             #+#    #+#             */
/*   Updated: 2023/02/08 11:15:04 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*str;
	char		*ptr;
	int			i;

	str = (char *)src;
	ptr = (char *)dst;
	i = 0;
	if (!dst && !src)
		return (NULL);
	while (n--)
	{
		ptr[i] = str[i];
		i++;
	}
	return (ptr);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;
	unsigned char	*s;
	unsigned char	*d;

	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	i = 0;
	if (!s && !d)
		return (NULL);
	if (src >= dst)
		ft_memcpy(d, s, len);
	else
		while (i < len--)
			d[len] = s[len];
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	sl1;
	size_t	sl2;
	char	*str;

	i = -1;
	j = 0;
	if (!s1)
	{
		sl2 = ft_strlen(s2);
		str = ft_strdup(s2);
		return (str);
	}
	sl1 = ft_strlen (s1);
	sl2 = ft_strlen (s2);
	str = (char *)malloc((sl1 + sl2 + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (++i < sl1)
		str[i] = s1[i];
	while (j < sl2)
		str[i++] = s2[j++];
	str[i] = '\0';
	return (free(s1), str);
}
