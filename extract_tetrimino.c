/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_tetrimino.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 13:44:50 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/04/04 21:12:47 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

//<<<<<<<<<<<<<<<<<<<<<<<STEP 12>>>>>>>>>>>>>>>>>>>>>>>>>>>>
static  t_tetr    *extract_tetr(char   **tetr_stor)
{
    int     y;
    int     x;
    t_tetr  *block_of_hashes;                                                //this block comtains the positions of the #-es(4 of them)
    int     i;
    int     j;
    int     counter;

    y = 0;
    x = 0;
    i = 0;
    j = 0;
    counter = 0;
    while (counter < 21)
    {
        x = 0;
        i = 0;
        j = 0;
        while (tetr_stor[y][x] != '\n')
        {
            //if we found a # we sent the position to the structure block_of_hashes
            if (tetr_stor[y][x] == '#')
            {
                block_of_hashes->x[i] = x;
                block_of_hashes->y[j] = y;
                i++;
                j++;
            }
            x++;
        }
        y++;
        counter++;
    }
    return (block_of_hashes);
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
        storage[counter] = extract_tetr(tetr_stor);
        storage[counter]->name_for_tetr = name_of_tetr;
        counter++;
        name_of_tetr++;
    }
    storage[counter] = '\0';                                                 //to avoid leaks
    return(storage);
}
