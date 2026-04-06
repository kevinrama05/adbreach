/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:23:12 by kerama            #+#    #+#             */
/*   Updated: 2025/10/17 10:32:16 by kerama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	num = 0;
	while (nptr[i] && ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		num = num * 10 + (nptr[i] - '0');
		i++;
	}
	return (num * sign);
}

// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>
// #include "libft.h"

// int main(void)
// {
// 	/* ===== Character functions ===== */
// 	printf("ft_isalpha('A'): %d\n", ft_isalpha('A'));
// 	printf("ft_isdigit('4'): %d\n", ft_isdigit('4'));
// 	printf("ft_isalnum('9'): %d\n", ft_isalnum('9'));
// 	printf("ft_isascii(127): %d\n", ft_isascii(127));
// 	printf("ft_isprint('!'): %d\n", ft_isprint('!'));
// 	printf("ft_toupper('a'): %d\n", ft_toupper('a'));
// 	printf("ft_tolower('A'): %d\n", ft_tolower('A'));

// 	/* ===== String functions ===== */
// 	char str1[] = "Hello";
// 	char str2[] = "World";
// 	char buffer[20];

// 	printf("ft_strlen(\"Hello\"): %zu\n", ft_strlen(str1));
// 	printf("ft_strlcpy(buffer, str1, 20): %zu, buffer=%s\n",
// 		ft_strlcpy(buffer, str1, 20), buffer);
// 	printf("ft_strlcat(buffer, str2, 20): %zu, buffer=%s\n",
// 		ft_strlcat(buffer, str2, 20), buffer);
// 	printf("ft_strchr(\"Hello\", 'e'): %s\n", ft_strchr(str1, 'e'));
// 	printf("ft_strrchr(\"Hello\", 'l'): %s\n", ft_strrchr(str1, 'l'));
// 	printf("ft_strncmp(\"abc\", \"abd\", 2): %d\n", 
//  ft_strncmp("abc", "abd", 2));
// 	printf("ft_strnstr(\"Hello World\", \"World\", 11): %s\n",
// 		ft_strnstr("Hello World", "World", 11));
// 	printf("ft_strdup(\"Libft\"): %s\n", ft_strdup("Libft"));

// 	/* ===== Memory functions ===== */
// 	char mem1[10] = "abcdef";
// 	char mem2[10] = "abcdef";
// 	char mem3[10] = "123456";

// 	ft_memset(mem1, 'X', 3);
// 	printf("ft_memset: %s\n", mem1);

// 	ft_bzero(mem1, 2);
// 	printf("ft_bzero: %s\n", mem1);

// 	ft_memcpy(mem2, mem3, 3);
// 	printf("ft_memcpy: %s\n", mem2);

// 	ft_memmove(mem2 + 2, mem2, 3);
// 	printf("ft_memmove overlap: %s\n", mem2);

// 	printf("ft_memchr(\"Hello\", 'e', 5): %s\n",
// 		(char *)ft_memchr("Hello", 'e', 5));
// 	printf("ft_memcmp(\"abc\", \"abd\", 3): %d\n", ft_memcmp("abc", "abd", 3));

// 	/* ===== Conversion functions ===== */
// 	printf("ft_atoi(\"  -42\"): %d\n", ft_atoi("  -42"));

// 	int *arr = ft_calloc(5, sizeof(int));
// 	printf("ft_calloc(5, sizeof(int)): %p\n", arr);
// 	free(arr);

// 	/* ===== Advanced string functions ===== */
// 	printf("ft_substr(\"LibftProject\", 5, 7): %s\n",
// 		ft_substr("LibftProject", 5, 7));
// 	printf("ft_strjoin(\"Hello\", \"World\"): %s\n",
// 		ft_strjoin("Hello", "World"));
// 	printf("ft_strtrim(\"  libft  \", \" \"): %s\n",
// 		ft_strtrim("  libft  ", " "));
// 	char **split = ft_split("This is Libft", ' ');
// 	printf("ft_split: %s | %s | %s\n", split[0], split[1], split[2]);
// 	free(split[0]); free(split[1]); free(split[2]); free(split);

// 	printf("ft_itoa(-123): %s\n", ft_itoa(-123));
// 	printf("ft_strmapi(\"abc\", f): (not tested here)\n");

// 	char s[] = "abcdef";
// 	ft_striteri(s, NULL);
// 	printf("ft_striteri result: %s\n", s);

// 	ft_putendl_fd("Hello Libft", 1);
// 	ft_putnbr_fd(42, 1);
// 	ft_putchar_fd('\n', 1);

// 	return (0);
// }
