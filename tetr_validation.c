/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetr_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 19:08:21 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/04/03 00:08:39 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

//<<<<<<<<<<<<<<<<<<<<<<<STEP 6>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//next function checks if the number(stored in structure) of #, . , \n in tetrimino is valid
int    check_if_valid_num(t_number_of_symbols *total)
{
    //if there are no #(or less than 4), then we have 0 tetriminos or if 
    if (total->hash < 4)
        return (ERROR);                              //invalid number(error)
    //if we have invalid number of #-es
    if (total->hash % 4 != 0)
        return (ERROR);                              //invalid number(error)
    //check if the number of dots is valid(we need to have 12 dots in one tetrimino)
    if (total->dot % 12 != 0)
        return (ERROR);                              //invalid number(error)
    //check if the number of \n is valid
    if ((total->new_line + 1) % 5 != 0)              //(total->new_line + 1) - if we have 2 new lines in the end of the file
        return (ERROR);                              //error  is defined in header file
    //if everything is correct we return 0
    return (OK);
}

//<<<<<<<<<<<<<<<<<<<<<<<STEP 5>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//next function counts if the amount of symbols is valid
int     not_valid_tetrimino(char *tetr_stor)
{
    //we are counting the number of #, . , \n in tetr_store (the file) and storing it into the scructure
    t_number_of_symbols *total;
    int     i;
    int     how_many_tetr;                                                      //keep in this var the number of the tetrimino in the file 

    i = 0;
    how_many_tetr = 0;
    
    total = malloc(sizeof(t_number_of_symbols));                                //alloc memmory for the structure(3 ints) to keep the number of hashes, dots and \n-s
    total->hash = 0;
    total->dot = 0;
    total->new_line = 0;
    
    while(tetr_stor[i])
    {
        if (tetr_stor[i] == '#')                                                //counting total #-es in tetrimino
            total->hash++;
        else if (tetr_stor[i] == '.')                                           //counting total .-s in tetrimino
            total->dot++;
        else if (tetr_stor[i] == '\n')                                          //counting total \n-s in tetrimino
            total->new_line++;
        i++;
    }
    if (check_if_valid_num(total) != OK)
        return (ERROR);
    how_many_tetr = total->hash / 4;                                            //because we have four '#' in one tetrimino 
    
}