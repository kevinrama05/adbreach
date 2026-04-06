/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 09:44:25 by kerama            #+#    #+#             */
/*   Updated: 2025/10/19 09:52:16 by kerama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static int	ft_is_sep(char c, char ch)
{
	return (c == ch);
}

static int	ft_count_words(char const *str, char ch)
{
	int	count;
	int	in_word;
	int	i;

	count = 0;
	in_word = 0;
	i = 0;
	while (str[i])
	{
		if (ft_is_sep(str[i], ch))
			in_word = 0;
		else if (!in_word)
		{
			in_word = 1;
			count++;
		}
		i++;
	}
	return (count);
}

static int	ft_word_len(char const *str, char ch)
{
	int	len;

	len = 0;
	while (str[len] && !ft_is_sep(str[len], ch))
		len++;
	return (len);
}

static char	*ft_strdup_range(char const *str, int len)
{
	char	*dup;
	int		i;

	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		words;
	int		i;
	int		j;
	int		len;

	words = ft_count_words(s, c);
	tab = malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (!ft_is_sep(s[i], c))
		{
			len = ft_word_len(&s[i], c);
			tab[j++] = ft_strdup_range(&s[i], len);
			i += len;
		}
		else
			i++;
	}
	tab[j] = 0;
	return (tab);
}

// static void	print_split_result(char **result)
// {
// 	int	i;

// 	if (!result)
// 	{
// 		printf("Result is NULL\n");
// 		return;
// 	}
// 	i = 0;
// 	while (result[i])
// 	{
// 		printf("result[%d] = \"%s\"\n", i, result[i]);
// 		i++;
// 	}
// 	printf("Total substrings: %d\n\n", i);
// }

// int	main(void)
// {
// 	char	**result;

// 	printf("=== Testing ft_split ===\n\n");

// 	// 1️⃣ Normal case
// 	printf("Test 1: \"Hello World 42\" (sep=' ')\n");
// 	result = ft_split("Hello World 42", ' ');
// 	print_split_result(result);
// 	// Free memory
// 	for (int i = 0; result && result[i]; i++)
// 		free(result[i]);
// 	free(result);

// 	// 2️⃣ Multiple consecutive separators
// 	printf("Test 2: \"Hello   42   Network\" (sep=' ')\n");
// 	result = ft_split("Hello   42   Network", ' ');
// 	print_split_result(result);
// 	for (int i = 0; result && result[i]; i++)
// 		free(result[i]);
// 	free(result);

// 	// 3️⃣ Leading and trailing separators
// 	printf("Test 3: \"  split this please  \" (sep=' ')\n");
// 	result = ft_split("  split this please  ", ' ');
// 	print_split_result(result);
// 	for (int i = 0; result && result[i]; i++)
// 		free(result[i]);
// 	free(result);

// 	// 4️⃣ String with only separators
// 	printf("Test 4: \"     \" (sep=' ')\n");
// 	result = ft_split("     ", ' ');
// 	print_split_result(result);
// 	for (int i = 0; result && result[i]; i++)
// 		free(result[i]);
// 	free(result);

// 	// 5️⃣ Empty string
// 	printf("Test 5: \"\" (sep=' ')\n");
// 	result = ft_split("", ' ');
// 	print_split_result(result);
// 	for (int i = 0; result && result[i]; i++)
// 		free(result[i]);
// 	free(result);

// 	// 6️⃣ Different separator character
// 	printf("Test 6: \"apple,banana,cherry\" (sep=',')\n");
// 	result = ft_split("apple,banana,cherry", ',');
// 	print_split_result(result);
// 	for (int i = 0; result && result[i]; i++)
// 		free(result[i]);
// 	free(result);

// 	// 7️⃣ NULL input
// 	printf("Test 7: NULL string\n");
// 	result = ft_split(NULL, ' ');
// 	print_split_result(result);

// 	return (0);
// }