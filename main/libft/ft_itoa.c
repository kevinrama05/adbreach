/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 09:51:34 by kerama            #+#    #+#             */
/*   Updated: 2025/10/20 17:12:01 by kerama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

#include <stdlib.h>
#include "libft.h"

static int	ft_digits(int n)
{
	int	digits;

	if (n == 0)
		return (1);
	digits = 0;
	while (n != 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

static void	ft_is_negative(int *sign, int *num)
{
	if (*num < 0)
	{
		*sign = 1;
		if (*num == -2147483648)
			*num = 2147483647;
		else
			*num = -(*num);
	}
	else
		*sign = 0;
}

char	*ft_itoa(int n)
{
	int		sign;
	int		len;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	ft_is_negative(&sign, &n);
	len = ft_digits(n) + sign;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len-- > sign)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	if (sign)
		str[0] = '-';
	return (str);
}

// int main(void)
// {
// 	int n = 1654684;
// 	printf("Number: %s\n", ft_itoa(n));
// 	return 0;
// }