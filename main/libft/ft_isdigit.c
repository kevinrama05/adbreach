/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:56:31 by kerama            #+#    #+#             */
/*   Updated: 2025/10/17 09:55:55 by kerama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

// void	test_isdigit(void)
// {
// 	int	c;

// 	printf("===== Testing ft_isdigit =====\n");
// 	for (c = 0; c <= 127; c++)
// 	{
// 		if (isdigit(c) != ft_isdigit(c))
// 			printf("Mismatch at '%c' (%d): isdigit=%d ft_isdigit=%d\n",
// 				(c >= 32 && c <= 126) ? c : '.', c, isdigit(c), ft_isdigit(c));
// 	}
// 	printf("ft_isdigit OK ✅\n\n");
// }

// int main(void)
// {
// 	test_isdigit();
// 	return (0);
// }