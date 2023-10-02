/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:13:03 by lduheron          #+#    #+#             */
/*   Updated: 2023/09/17 16:33:04 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	ft_strlcpy(char *dst, char *src, unsigned int size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && (i + 1) < size)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

size_t	get_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t			len_s;
	size_t			new_len;
	char			*nchain;

	if (s == NULL)
		nchain = NULL;
	else
	{
		len_s = ft_strlen(s);
		new_len = 0;
		if (start <= len_s)
			new_len = get_min(len_s - start, len);
		else
			start = len_s;
		nchain = malloc((new_len + 1) * sizeof(char));
		if (nchain != NULL)
			ft_strlcpy(nchain, s + start, new_len + 1);
	}
	return (nchain);
}
