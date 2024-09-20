/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:24:12 by ismailalash       #+#    #+#             */
/*   Updated: 2024/09/20 20:15:54 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	*s;

	scan_format(argc, argv);
	s = malloc(sizeof * s);
	if (s == NULL)
		exit(1);
	initialize_stack(argc, argv, s);
	connect_args(argc, argv, s);
	parse_nums(s);
	exit_if_dupes_or_sorted(s, 0);
	create_index(s);
	if (s->a_size == 2 && s->stack_a[0] > s->stack_a[1])
		swap("sa", s->stack_a, s->a_size);
	else if (s->a_size == 3)
		sort_three(s);
	else if (s->a_size >= 4 && s->a_size <= 5)
		sort_four_to_five(s);
	else
		radix_sort(s);
	exit_if_dupes_or_sorted(s, 1);
	free_and_exit_with_msg(s, "Error\n");
	return (0);
}
