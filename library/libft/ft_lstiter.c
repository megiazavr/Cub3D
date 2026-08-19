/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 22:15:51 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/05/10 22:48:28 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*currentnode;

	currentnode = lst;
	if (!lst || !f)
		return ;
	while (currentnode != NULL)
	{
		f(currentnode->content);
		currentnode = currentnode->next;
	}
}
