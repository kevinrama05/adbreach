/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:22:10 by kerama            #+#    #+#             */
/*   Updated: 2025/10/15 13:39:05 by kerama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*head;
	t_list	*to_delete;

	if (!lst)
		return ;
	head = *lst;
	while (head)
	{
		to_delete = head;
		head = head->next;
		del(to_delete->content);
		free(to_delete);
	}
	*lst = NULL;
}
