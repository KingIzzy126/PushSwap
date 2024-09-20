/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:06:44 by ismailalash       #+#    #+#             */
/*   Updated: 2024/09/20 20:11:10 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_array_sorted(t_stacks *s)
{
	int	i;

	i = 0;
	while (i < s->a_size - 1)
	{
		if (s->stack_a[i] > s->stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	sort_three(t_stacks *s)
{
	if (s->stack_a[2] != 2)
	{
		if (s->stack_a[0] == 2)
			rotate(s->stack_a, s->a_size, "up", "a");
		else
			rotate(s->stack_a, s->a_size, "down", "a");
	}
	if (s->stack_a[0] > s->stack_a[1])
		swap("sa", s->stack_a, s->a_size);
}

void	sort_four_to_five(t_stacks *s)
{
	while (s->b_size <= 1)
	{
		if (s->stack_a[0] == 0 || s->stack_a[0] == 1)
			push("pb", s);
		else
			rotate(s->stack_a, s->a_size, "up", "a");
	}
	if (s->stack_b[0] == 0)
		swap("sb", s->stack_b, s->b_size);
	if (s->stack_a[2] != 4)
	{
		if (s->stack_a[0] == 4)
			rotate(s->stack_a, s->a_size, "up", "a");
		else
			rotate(s->stack_a, s->a_size, "down", "a");
	}
	if (s->stack_a[0] > s->stack_a[1])
		swap("sa", s->stack_a, s->a_size);
	push("pa", s);
	push("pa", s);
}

static void	radix_sort_stack_b(t_stacks *s, int b_size, int bit_size, int j)
{
	while (b_size-- && j <= bit_size && !is_array_sorted(s))
	{
		if (((s->stack_b[0] >> j) & 1) == 0)
			rotate(s->stack_b, s->b_size, "up", "b");
		else
			push("pa", s);
	}
	if (is_array_sorted(s))
		while (s->b_size != 0)
			push("pa", s);
}

void	radix_sort(t_stacks *s)
{
	int	j;
	int	bit_size;
	int	size;

	bit_size = 0;
	size = s->a_size;
	while (size > 1 && ++bit_size)
		size /= 2;
	j = -1;
	while (++j <= bit_size)
	{
		size = s->a_size;
		while (size-- && !is_array_sorted(s))
		{
			if (((s->stack_a[0] >> j) & 1) == 0)
				push("pb", s);
			else
				rotate(s->stack_a, s->a_size, "up", "a");
		}
		radix_sort_stack_b(s, s->b_size, bit_size, j + 1);
	}
	while (s->b_size != 0)
		push("pa", s);
}
