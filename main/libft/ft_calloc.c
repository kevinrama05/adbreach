/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:23:52 by kerama            #+#    #+#             */
/*   Updated: 2025/10/20 17:10:22 by kerama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	size_t			total;
	size_t			i;
	unsigned char	*p;

	if (nmemb == 0 || size == 0)
		return (malloc(1));
	if (nmemb > ((size_t) - 1) / size)
		return (NULL);
	total = nmemb * size;
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	p = (unsigned char *)ptr;
	i = 0;
	while (i < total)
	{
		p[i] = 0;
		i++;
	}
	return (ptr);
}

// void	print_bytes(const char *label, unsigned char *ptr, size_t n)
// {
// 	size_t i;

// 	printf("%s: ", label);
// 	for (i = 0; i < n; i++)
// 		printf("%02x ", ptr[i]);
// 	printf("\n");
// }

// void	test_calloc(size_t count, size_t size)
// {
// 	void	*orig;
// 	void	*mine;

// 	printf("Testing calloc(%zu, %zu):\n", count, size);

// 	orig = calloc(count, size);
// 	mine = ft_calloc(count, size);

// 	if (!orig || !mine)
// 	{
// 		printf("Allocation failed\n");
// 		free(orig);
// 		free(mine);
// 		return;
// 	}

// 	print_bytes("calloc   ", (unsigned char *)orig, count * size);
// 	print_bytes("ft_calloc", (unsigned char *)mine, count * size);

// 	free(orig);
// 	free(mine);
// 	printf("-------------------------\n");
// }

// int	main(void)
// {
// 	test_calloc(5, sizeof(int));
// 	test_calloc(10, 1);
// 	test_calloc(3, 8);
// 	test_calloc(0, 5); // edge case
// 	test_calloc(5, 0); // edge case

// 	return (0);
// }
