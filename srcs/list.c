/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:09:12 by jcorwin           #+#    #+#             */
/*   Updated: 2019/02/02 19:09:08 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list			*list_new(int data)
{
	t_list		*new;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		STOP;
	new->data = data;
	new->order = 0;
	new->color = 0;
	new->next = new;
	new->prev = new;
	return (new);
}

t_list			*list_pushback(t_list *start, t_list *new)
{
	t_list		*end;

	if (!start)
		return (new);
	end = start;
	while (end->next != start)
		end = end->next;
	end->next = new;
	new->prev = end;
	new->next = start;
	start->prev = new;
	return (start);
}

t_list			*list_pushfront(t_list *start, t_list *new)
{
	list_pushback(start, new);
	return (new);
}

t_list			*list_cut(t_list *start, t_list *node)
{
	if (!start || !node)
		return (start);
	if (start->next == start)
		start = NULL;
	else if (node == start)
		start = start->next;
	if (node)
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		node->next = node;
		node->prev = node;
	}
	return (start);
}

t_list			*list_del(t_list *start)
{
	t_list	*cur;
	t_list	*prev;

	if (!start)
		return (NULL);
	cur = start->next;
	while (cur != start)
	{
		prev = cur;
		cur = cur->next;
		free(prev);
	}
	free(start);
	return (NULL);
}
