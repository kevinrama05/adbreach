/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:56:10 by kerama            #+#    #+#             */
/*   Updated: 2025/10/17 09:53:13 by kerama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

// void	test_isalpha(void)
// {
// 	int	c;

// 	printf("===== Testing ft_isalpha =====\n");
// 	for (c = 0; c <= 127; c++)
// 	{
// 		if (isalpha(c) != ft_isalpha(c))
// 			printf("Mismatch at '%c' (%d): isalpha=%d ft_isalpha=%d\n",
// 				(c >= 32 && c <= 126) ? c : '.', c, isalpha(c), ft_isalpha(c));
// 	}
// 	printf("ft_isalpha OK ✅\n\n");
// }

// int main(void)
// {
// 	test_isalpha();
// 	return (0);
// }