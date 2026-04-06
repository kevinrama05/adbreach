/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:03:41 by kerama            #+#    #+#             */
/*   Updated: 2025/10/17 09:40:12 by kerama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

// void	print_bytes(const char *label, unsigned char *buf, size_t n)
// {
// 	size_t i;

// 	printf("%s: ", label);
// 	for (i = 0; i < n; i++)
// 		printf("%02x ", buf[i]); // print each byte in hex
// 	printf("\n");
// }

// void	test_bzero(size_t n)
// {
// 	unsigned char	buf1[20] = "HelloWorld";
// 	unsigned char	buf2[20] = "HelloWorld";

// 	printf("Before:\n");
// 	print_bytes("bzero   ", buf1, 10);
// 	print_bytes("ft_bzero", buf2, 10);

// 	bzero(buf1, n);
// 	ft_bzero(buf2, n);

// 	printf("After bzero(%zu):\n", n);
// 	print_bytes("bzero   ", buf1, 10);
// 	print_bytes("ft_bzero", buf2, 10);
// 	printf("-------------------------\n");
// }

// int	main(void)
// {
// 	test_bzero(0);
// 	test_bzero(3);
// 	test_bzero(5);
// 	test_bzero(10);

// 	return (0);
// }