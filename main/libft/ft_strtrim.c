/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 08:50:33 by kerama            #+#    #+#             */
/*   Updated: 2025/10/17 10:24:56 by kerama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "libft.h"

static size_t	ft_is_set(char ch, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (ch == set[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_not_set(char const *s1, char const *set)
{
	size_t	k;
	size_t	len;

	k = 0;
	len = 0;
	while (s1[k])
	{
		if (ft_is_set(s1[k], set) == 0)
			len++;
		k++;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	j;
	size_t	p;
	char	*s;

	s = (char *)malloc(sizeof(char) * (ft_not_set(s1, set) + 1));
	if (!s)
		return (NULL);
	j = 0;
	p = 0;
	while (s1[j])
	{
		if (ft_is_set(s1[j], set) == 0)
		{
			s[p] = s1[j];
			j++;
			p++;
		}
		else
		{
			j++;
		}
	}
	s[p] = '\0';
	return (s);
}

// int main(void)
// {
// 	const char *s1 = "Hello, how aro you? Yohohohohoho";
// 	const char *set = "Ho";
// 	char *s = ft_strtrim(s1, set);
// 	printf("Original: %s\n", s1);
// 	printf("Trimmed:  %s\n", s);
// 	return 0;
// }