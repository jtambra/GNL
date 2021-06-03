/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtambra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 20:34:14 by jtambra           #+#    #+#             */
/*   Updated: 2021/05/28 17:10:03 by jtambra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void	ft_lstiter_i(t_list *lst, void (*f)(void *, int))
{
	int	i;

	i = 0;
	if (!lst)
		return ;
	if (f)
	{
		while (lst)
		{
			f(lst->content, i);
			lst = lst->next;
			i++;
		}
	}
	else
		return ;
}
