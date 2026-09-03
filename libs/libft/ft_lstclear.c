/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 22:15:37 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/05/11 13:55:50 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*currentnode;
	t_list	*nextnode;

	if (!lst || !del || *lst == NULL)
		return ;
	currentnode = *lst;
	while (currentnode != NULL)
	{
		nextnode = currentnode->next;
		del(currentnode->content);
		free(currentnode);
		currentnode = nextnode;
	}
	*lst = NULL;
}
