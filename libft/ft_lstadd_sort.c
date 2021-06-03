/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtambra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 19:58:53 by jtambra           #+#    #+#             */
/*   Updated: 2021/05/28 20:41:37 by jtambra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstadd_sort(t_list **sorted, t_list *lst, int (*f)(void *, void *))
{
	t_list	*current;
	t_list	*previous;
	//проверки на наличие

	previous = 0;
	current = *sorted;
	while (current->next)
	{
		//printf("%d\n", lst->content.value);
		if (f(current->content, lst->content) > 0)
			break;
		previous = current;
		current = current->next;
	}
	if (!previous)
		*sorted = lst;
	else
		previous->next = lst;
	lst->next = current;
}
