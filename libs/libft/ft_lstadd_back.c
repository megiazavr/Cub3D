/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 22:15:07 by ncruz-ne          #+#    #+#             */
/*   Updated: 2026/09/03 18:13:27 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_node)
{
	t_list	*currentlastnode;

	if (!new_node || !lst)
		return ;
	if (*lst == NULL)
	{
		*lst = new_node;
		return ;
	}
	currentlastnode = ft_lstlast(*lst);
	currentlastnode->next = new_node;
}
