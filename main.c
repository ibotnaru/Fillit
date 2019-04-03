/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:16:14 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/04/02 13:29:39 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int main(int ac, char **av)
{
    char    *tetrimino;
    if (ac != 2)
    {
        ft_putstr("Input error!\n");
        return (0);                             //if we have an error(nb of input files is not 1) we exit the program here     
    }
    tetrimino = extract_tetrimino(av[1]);
    return (0);
}