/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismailalashqar <ismailalashqar@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:56:37 by ismailalash       #+#    #+#             */
/*   Updated: 2024/09/18 17:57:38 by ismailalash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_isspace(int c)
{
    if (c == 32 || c == '\t')
        return (1);
    return (0);
}