/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_tetrimino.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 13:44:50 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/04/04 17:44:13 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

//<<<<<<<<<<<<<<<<<<<<<<<STEP 12>>>>>>>>>>>>>>>>>>>>>>>>>>>>
t_tetr    *extract_tetr(char   **tetr_stor)
{
    int     y;
    int     x;
    t_tetr  *block_of_hashes;                                                //this block comtains the positions of the #-es(4 of them)

    y = 0;
    x = 0;
    while (tetr_stor[y][x])
    {
        x = 0;
        while (tetr_stor[y][x] != '\n')
        {
            //if we found a # we sent the position to the structure
            if (tetr_stor[y][x] == '#')
            {
                block_of_hashes->x = x;
            }
        }
    }
}

//<<<<<<<<<<<<<<<<<<<<<<<STEP 11>>>>>>>>>>>>>>>>>>>>>>>>>>>>
t_tetr    **storing_tetr(char   *tetr_stor)
{
    //tis is our storage in which we will keep the extracted tetriminoes (#-es without .-ts)
    t_tetr      **storage;                                                   //storage is a structure which contains structures(tetriminoes)
    int         num_of_tetrs;
    int         temp;
    char        name_of_tetr;
    int         counter;

    temp = 0;
    counter = 0;
    name_of_tetr = 'A';                                                      //we are going to name the tetreminoes in alphabetical order starting with A
    num_of_tetrs = (ft_strlen(tetr_stor + 1) / 21);                          //we counting how many tetriminoes by dividing the size of the whole file(and 1 for the last \n) by 21  
    storage = (t_tetr **)malloc(sizeof(t_tetr) * num_of_tetrs);              //we alloc memory size of tetr_stor for storage and it has enough space for all tetriminios
    while (counter < num_of_tetrs)
    {
        
    }

}
