/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:16:14 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/04/04 17:44:41 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int main(int ac, char **av)
{
    char     *tetr_stor;
    t_tetr   **tetrimino;
    if (ac != 2)
    {
        ft_putstr("Input error!\n");
        return (0);                             //if we have an error(nb of input files is not 1) we exit the program here     
    }
    tetr_stor = reading_tetriminoes(av[1]);
    tetrimino = extract_tetr(tetr_stor);
    return (0);
}