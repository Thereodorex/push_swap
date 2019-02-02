/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 12:06:08 by jcorwin           #+#    #+#             */
/*   Updated: 2019/02/02 19:11:39 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int				main(int argc, char **argv)
{
	t_param		p;

	p.a = NULL;
	p.b = NULL;
	p.d.on = 0;
	p.d.color = 0;
	p.d.step = 0;
	get_args(&p, argc, argv, 0);
	if (p.a)
		psw_main(&p);
	list_del(p.a);
	list_del(p.b);
	return (0);
}
