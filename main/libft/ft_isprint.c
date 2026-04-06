/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:57:19 by kerama            #+#    #+#             */
/*   Updated: 2025/10/17 10:03:41 by kerama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

// void	test_isprint(void)
// {
// 	int	c;

// 	printf("===== Testing ft_isprint =====\n");
// 	for (c = 0; c <= 127; c++)
// 	{
// 		if (isprint(c) != ft_isprint(c))
// 			printf("Mismatch at '%c' (%d): isprint=%d ft_isprint=%d\n",
// 				(c >= 32 && c <= 126) ? c : '.', c, isprint(c), ft_isprint(c));
// 	}
// 	printf("ft_isprint OK ✅\n\n");
// }

// int main(void)
// {
// 	test_isprint();
// 	return 0;
// }