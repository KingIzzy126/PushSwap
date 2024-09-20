/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 11:53:58 by ialashqa          #+#    #+#             */
/*   Updated: 2024/09/20 20:14:17 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stacks
{
	int		*stack_a;
	int		*stack_b;
	int		a_size;
	int		b_size;
	char	*join_args;
}			t_stacks;

// parsing.c
void		scan_format(int argc, char **argv);
void		connect_args(int argc, char **argv, t_stacks *s);
void		parse_nums(t_stacks *s);
void		exit_if_dupes_or_sorted(t_stacks *s, int i);
int			ft_atol(const char *n, t_stacks *s);

// setup.c
void		free_and_exit_with_msg(t_stacks *s, char *msg);
void		initialize_stack(int argc, char **argv, t_stacks *s);
int			is_empty(char *argv);
void		create_index(t_stacks *s);

// sort.c
int			is_array_sorted(t_stacks *s);
void		sort_three(t_stacks *s);
void		sort_four_to_five(t_stacks *s);
void		radix_sort(t_stacks *s);

// move.c
void		swap(char *str, int *array, int size);
void		push(char *str, t_stacks *s);
void		rotate(int *array, int size, char *direction, char *list);

#endif