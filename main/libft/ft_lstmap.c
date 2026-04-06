/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:47:46 by kerama            #+#    #+#             */
/*   Updated: 2025/10/16 09:58:04 by kerama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static t_list	*ft_in_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

static void	ft_in_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*head;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	head = *lst;
	while (head->next)
	{
		head = head->next;
	}
	head->next = new;
}

void	ft_in_lstclear(t_list **lst, void (*del)(void *))
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

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;

	if (!lst || !f)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_node = ft_in_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_in_lstclear(&new_list, del);
			return (NULL);
		}
		ft_in_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
