/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validaton.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:11:31 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/04/04 01:16:11 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
//<<<<<<<<<<<<<<<<<<<<<<<STEP 9>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//this fuction checks the position of the # comparatively each other
int     valid_neighbor(char **tetr_store, int y, int x)
{
    int     num_of_neighbors;

    num_of_neighbors = 0;
    if (tetr_store[y][x - 1] == '#')
        num_of_neighbors++;
    if (tetr_store[y][x + 1] == '#')
        num_of_neighbors++;
    if (tetr_store[y - 1][x] == '#')
        num_of_neighbors++;
    if (tetr_store[y + 1][x] == '#')
        num_of_neighbors++;
    return (num_of_neighbors);
}
//<<<<<<<<<<<<<<<<<<<<<<<STEP 8>>>>>>>>>>>>>>>>>>>>>>>>>>>>
int     check_neighbors(char **tetr_stor)
{
   //x and y - coordinates of the # position on the map
   int      x;
   int      y;
   int      num_of_neighbors;
   int      num_of_hashes;

   x = 0;
   y = 0;
   num_of_neighbors = 0;
   num_of_hashes = 0;
   while (tetr_stor[y][x] != '\0')
   {
       x = 0;
       while (tetr_stor[y][x] != '\n')
       {
           if (tetr_stor[y][x] == '#')
           {
               num_of_hashes++;
               num_of_neighbors += valid_neighbors(tetr_stor, y, x);
           }
           x++;
       }
       y++;
   }
   if (num_of_hashes % 4 != 0)
        return (ERROR);
   return (OK);
}
//<<<<<<<<<<<<<<<<<<<<<<<STEP 7>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//this function checks if we have 4x4 map
int     check_if_valid_map(char **tetr_stor)
{
    int     rows;
    int     colomns;
    int     i;
    int     j;
    

    rows = 0;
    colomns = 0;
    i = 0;
    j = 0;
   
    while (tetr_stor[i][j])
    {
        if (tetr_stor[i][0] == '\n')
            i++;
        while (tetr_stor[i][j] != '\n')
        {
            colomns++;
            j++;
        }
        if (colomns != 4)
            return (ERROR);
        colomns = 0;
        j = 0;
        rows++;
        i++;
    }
    if (rows % 4 != 0)
        return (ERROR);
    return (OK);
}
