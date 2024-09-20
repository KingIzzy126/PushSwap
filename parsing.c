/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismailalashqar <ismailalashqar@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:16:10 by ismailalash       #+#    #+#             */
/*   Updated: 2024/09/19 12:38:42 by ismailalash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void scan_format(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	if (argc < 2)
		free_and_exit_with_msg(NULL, "");
	while (++i < argc)
	{
		j = 0;
		if (is_empty(argv[i]) || !argv[i][0])
			free_and_exit_with_msg(NULL, "Error\n");
		while (argv[i][j] != '\0')
		{
			if ((!(ft_isdigit(argv[i][j])) && (argv[i][j] != ' ')
			&& (argv[i][j] != '-' && argv[i][j] != '+' && argv[i][j] != ' '))
			|| (argv[i][j] == '-' && argv[i][j + 1] == '\0')
			|| (argv[i][j] == '+' && argv[i][j + 1] == '\0')
			|| (argv[i][j] == '-' && argv[i][j + 1] == ' ')
			|| (argv[i][j] == '+' && argv[i][j + 1] == ' '))
				free_and_exit_with_msg(NULL, "Error\n");
			j++;
		}
	}
}

void connect_args(int argc, char **argv, t_stacks *s)
{
	char	*temp;
	char	*temp2;
	int		i;

	i = 0;
	temp2 = ft_strdup("");
	while (++i < argc && argv[i] != NULL)
	{
		temp = ft_strjoin(temp2, argv[i]);
		if (temp2)
			free(temp2);
		if (i != argc - 1)
		{
			temp2 = ft_strjoin(temp, " ");
			if (temp)
				free(temp);
			temp = temp2;
		}
	}
	s->join_args = ft_strdup(temp);
	if (s->join_args == NULL)
		free_and_exit_with_msg(s, "Error\n");
	if (temp)
		free(temp);
}

// void parse_nums(t_stacks *s)
// {
//     char    **temp;
//     int     i;
//     int     j;

//     j = 0;
//     temp = ft_split(s->join_args, ' ');  // Split the concatenated string into individual arguments

//     // Debug: Check if ft_split worked properly
//     if (!temp)
//     {
//         printf("Error: ft_split failed to split the arguments.\n");
//         free_and_exit_with_msg(s, "Error\n");
//     }

//     // Debug: Print the split strings
//     printf("Split strings:\n");
//     i = 0;
//     while (temp[i] != NULL && temp[i][0] != '\0')
//     {
//         printf("temp[%d] = %s\n", i, temp[i]);  // Print each split string

//         // Convert each string to an integer using ft_atol and store in stack_a
//         s->stack_a[j] = ft_atol(temp[i], s);  

//         // Debug: Print the converted integer value
//         printf("stack_a[%d] = %d\n", j, s->stack_a[j]);

//         free(temp[i]);  // Free the string after it's been used
//         j++;
//         i++;
//     }
//     free(temp);  // Free the array of strings

//     // Debug: Final check for stack_a values
//     printf("Final stack_a values:\n");
//     for (i = 0; i < s->a_size; i++)
//     {
//         printf("stack_a[%d] = %d\n", i, s->stack_a[i]);
//     }
// }

void    parse_nums(t_stacks *s)
{
	char	**temp;
	int		i;
	int		j;

	j = 0;
	temp = ft_split(s->join_args, ' ');
	i = 0;
	while (temp[i] != NULL && temp[i][0] != '\0')
	{
		s->stack_a[j] = ft_atol(temp[i], s);
		free(temp[i]);
        j++;
        i++;
	}
	free(temp);
}

void    exit_if_dupes_or_sorted(t_stacks *s, int i)
{
	int	j;

	j = 0;
	if (i == 0)
	{
		while (i < s->a_size)
		{
			j = i + 1;
			while (j < s->a_size)
			{
				if (s->stack_a[i] == s->stack_a[j])
					free_and_exit_with_msg(s, "Error\n");
				j++;
			}
			i++;
		}
	}
	if (is_array_sorted(s))
		free_and_exit_with_msg(s, NULL);
}

void    create_index(t_stacks *s)
{
    int i;
    int j;
    int k;
    int *new_a;
    
    new_a = malloc(s->a_size * sizeof *new_a);
    if (new_a == NULL)
        free_and_exit_with_msg(s, "Error\n");
    i = 0;
    while (i < s->a_size)
    {
        k = 0;
        j = 0;
        while (j < s->a_size)
            k += s->stack_a[i] > s->stack_a[j++];
        new_a[i] = k;
        i++;
    }
    i = s->a_size;
    while (i--)
        s->stack_a[i] = new_a[i];
    free(new_a);
}

int ft_atol(const char *n, t_stacks *s)
{
	int			i;
	long		sign;
	long long	res;

	res = 0;
	sign = 1;
	i = 0;
	while (n[i] == ' ' || (n[i] >= '\t' && n[i] <= '\r'))
		i++;
	if ((n[i] == '+' || n[i] == '-'))
	{
		if (n[i] == '-')
			sign = -1;
		i++;
	}
	while (n[i])
	{
		if (!(n[i] >= '0' && n[i] <= '9'))
			free_and_exit_with_msg(s, "Error\n");
		res = res * 10 + (n[i++] - '0');
		if ((res * sign) < INT_MIN || (res * sign) > INT_MAX
			|| ft_strlen(n) > 11)
			free_and_exit_with_msg(s, "Error\n");
	}
	return ((int)(res * sign));
}