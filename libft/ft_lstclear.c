/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doji <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 19:43:49 by doji              #+#    #+#             */
/*   Updated: 2024/05/18 19:43:50 by doji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*head;
	t_list	*tmp;

	head = *lst;
	while (head)
	{
		tmp = head -> next;
		(*del)(head -> content);
		free(head);
		head = tmp;
	}
	*lst = NULL;
}
