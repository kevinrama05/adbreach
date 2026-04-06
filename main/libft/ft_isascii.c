/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:57:07 by kerama            #+#    #+#             */
/*   Updated: 2025/10/17 09:53:28 by kerama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

// void	test_isascii(void)
// {
// 	int	c;

// 	printf("===== Testing ft_isascii =====\n");
// 	for (c = 0; c <= 255; c++)
// 	{
// 		if (isascii(c) != ft_isascii(c))
// 			printf("Mismatch at (%d): isascii=%d ft_isascii=%d\n",
// 				c, isascii(c), ft_isascii(c));
// 	}
// 	printf("ft_isascii OK ✅\n\n");
// }

// int main(void)
// {
// 	test_isascii();
// 	return (0);
// }