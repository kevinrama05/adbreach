/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:56:48 by kerama            #+#    #+#             */
/*   Updated: 2025/10/17 09:48:18 by kerama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int	ft_isalnum(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'));
}

// void	test_isalnum(void)
// {
// 	int	c;

// 	printf("===== Testing ft_isalnum =====\n");
// 	for (c = 0; c <= 127; c++)
// 	{
// 		if (isalnum(c) != ft_isalnum(c))
// 			printf("Mismatch at '%c' (%d): isalnum=%d ft_isalnum=%d\n",
// 				(c >= 32 && c <= 126) ? c : '.', c, isalnum(c), ft_isalnum(c));
// 	}
// 	printf("ft_isalnum OK ✅\n\n");
// }

// int main(void)
// {
// 	test_isalnum();
// 	return (0);
// }