/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:13:09 by kerama            #+#    #+#             */
/*   Updated: 2025/10/17 10:24:41 by kerama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	j;

	if (!dst || !src)
		return (0);
	dst_len = 0;
	while (dst[dst_len] && dst_len < size)
		dst_len++;
	src_len = 0;
	while (src[src_len])
		src_len++;
	j = 0;
	while (src[j] && (dst_len + j + 1) < size)
	{
		dst[dst_len + j] = src[j];
		j++;
	}
	if (dst_len < size)
		dst[dst_len + j] = '\0';
	return (dst_len + src_len);
}
