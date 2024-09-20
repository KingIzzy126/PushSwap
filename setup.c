/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:39:23 by ismailalash       #+#    #+#             */
/*   Updated: 2024/09/20 20:14:22 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_and_exit_with_msg(t_stacks *s, char *msg)
{
	if (msg != NULL)
		ft_printf("%s", msg);
	if (s != NULL)
	{
		if (s->stack_a != NULL)
			free(s->stack_a);
		if (s->stack_b != NULL)
			free(s->stack_b);
		if (s->join_args != NULL)
			free(s->join_args);
		free(s);
	}
	exit(1);
}

int	is_empty(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!ft_isspace(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

void	initialize_stack(int argc, char **argv, t_stacks *s)
{
	int	i;

	i = 0;
	s->a_size = 0;
	s->b_size = 0;
	while (--argc)
	{
		if (word_count(argv[i + 1], ' '))
			s->a_size += word_count(argv[i + 1], ' ');
		else
			s->a_size++;
		i++;
	}
	s->stack_a = malloc(s->a_size * sizeof * s->stack_a);
	if (s->stack_a == NULL)
		free_and_exit_with_msg(s, "Error\n");
	s->stack_b = malloc(s->a_size * sizeof * s->stack_b);
	if (s->stack_b == NULL)
		free_and_exit_with_msg(s, "Error\n");
}

void	create_index(t_stacks *s)
{
	int	i;
	int	j;
	int	k;
	int	*new_a;

	new_a = malloc(s->a_size * sizeof * new_a);
	if (new_a == NULL)
		free_and_exit_with_msg(s, "Error\n");
	i = -1;
	while (++i < s->a_size)
	{
		k = 0;
		j = -1;
		while (++j < s->a_size)
			if (s->stack_a[i] > s->stack_a[j])
				k++;
		new_a[i] = k;
	}
	i = s->a_size;
	while (i--)
		s->stack_a[i] = new_a[i];
	free(new_a);
}
