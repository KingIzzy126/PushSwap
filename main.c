/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismailalashqar <ismailalashqar@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:24:12 by ismailalash       #+#    #+#             */
/*   Updated: 2024/09/19 12:38:32 by ismailalash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int main(int argc, char **argv)
// {
//     t_stacks    *s;
//     int         i;

    
//     printf("start prgram:");
//     i = 0;
//     while (i < argc)
//     {
//         printf("%s ", argv[i]);
//         i++;
//     }
//     printf("\n");
//     printf("Checking format of arguments...\n");
//     scan_format(argc, argv);
//     printf("Arguments format is valid.\n");
//     s = malloc(sizeof * s);
//     if (s == NULL)
//     {
//         printf("Memory allocation failed for t_stacks.\n");
//         exit (1);
//     }
//     printf("Memory allocated for t_stacks.\n");
//     initialize_stack(argc, argv, s);
//     printf("Stacks initialized. a_size: %d, b_size: %d\n", s->a_size, s->b_size);
//     connect_args(argc, argv, s);
//     parse_nums(s);
//     printf("Arguments concatenated into: %s\n", s->join_args);
//     printf("Checking for duplicates or sorted array...\n");
//     exit_if_dupes_or_sorted(s, 0);
//     printf("No duplicates or sorted array found.\n");
//     create_index(s);
//     printf("Index created. Stack A: ");
//     i = 0;
//     while (i < s->a_size)
//     {
//         printf("%d ", s->stack_a[i]);
//         i++;
//     }
//     printf("\n");
//     if (s->a_size == 2 && s->stack_a[0] > s->stack_a[1])
//     {
//         printf("Swapping two elements in stack_a.\n");
//         swap("sa", s->stack_a, s->a_size);
//     }
//     else if (s->a_size == 3)
//     {
//         printf("Sorting three elements.\n");
//         sort_three(s);
//     }
//     else if (s->a_size >= 4 && s->a_size <= 5)
//     {
//         printf("Sorting four to five elements.\n");
//         sort_four_to_five(s);
//     }
//     else
//     {
//         printf("Sorting using radix sort.\n");
//         radix_sort(s);
//     }
//     printf("Final check for duplicates or sorted array...\n");
//     exit_if_dupes_or_sorted(s, 1);
//     free_and_exit_with_msg(s, "Error\n");
//     return (0);
// }

int main(int argc, char **argv)
{
    t_stacks    *s;
    
    scan_format(argc, argv);
    s = malloc(sizeof * s);
    if (s == NULL)
        exit (1);
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