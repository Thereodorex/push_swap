/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:09:49 by jcorwin           #+#    #+#             */
/*   Updated: 2019/02/02 19:07:45 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"
# include <stdlib.h>

# define SWAP(list) list = o_swap(list)
# define PUSH(a, b) a = o_push(a, &(b))
# define ROT(a) if (a) a = a->next
# define RROT(a) if (a) a = a->prev
//# define PRINT(a, b) list_print("A", a); list_print("B", b)
# define STOP {ft_fprintf(2, "Error\n"); exit(0);}
//# define USAGE "usage: push_swap [-vcs] number1 number2 ...\n"
//# define MAL "Error: malloc returned nothing\n"
# define DO(p, c) {do_op(p, c); com_print(c); if (p->d.on) psw_debug(p, c);}
# define DO_C(p, c) {do_op(p, c); if (p->d.on) psw_debug(p, c);}

typedef enum	e_com
{
	sa = 1,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr,
	err
}				t_com;

typedef struct	s_c
{
	int		c_rr;
	int		c_rrr;
	int		c_ra;
	int		c_rb;
	int		c_rra;
	int		c_rrb;
}				t_c;

typedef struct	s_list
{
	int					data;
	int					order;
	int					color;
	struct s_list		*next;
	struct s_list		*prev;
}				t_list;

typedef struct	s_debug
{
	int			on;
	int			color;
	int			step;
}				t_debug;

typedef struct	s_param
{
	t_list		*a;
	t_list		*b;
	t_list		*com;
	t_debug		d;
}				t_param;

t_list			*list_new(int data);
t_list			*list_pushback(t_list *start, t_list *new);
t_list			*list_pushfront(t_list *start, t_list *new);
t_list			*list_cut(t_list *start, t_list *node);
t_list			*list_del(t_list *start);
void			list_print(char *name, t_list *start);

t_list			*o_swap(t_list *start);
t_list			*o_push(t_list *dst, t_list **src);
void			do_op(t_param *p, t_com com);

void			com_print(t_com com);
void			get_args(t_param *p, int argc, char **argv, int i);
void			psw_debug(t_param *p, t_com com);

int				check(t_param *p);
void			psw_main(t_param *p);
void			psw_simple(t_param *p, int max);
t_c				step(t_param *p, t_c cm);
int				set_order(t_list *a);
int				c_sum(t_c *cm);

#endif
