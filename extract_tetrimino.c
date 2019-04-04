/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_tetrimino.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:36:00 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/04/03 18:45:38 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

//<<<<<<<<<<<<<<<<<<<<<<<STEP 4>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//next function checks if the symbols itself are valid
static int  not_valid_symbol(char *tetr_stor)                   //the returned value is static because next itteration we not gonna start from the beggining again
{
    int     i;

    i = 0;
    while (tetr_stor[i] != '\0')                                //iterating through tetriminoes
    {
        if(tetr_stor[i] != '#' && tetr_stor[i] != '.' && tetr_stor[i] != '\n')
        {
            return (ERROR);                                     //value is not valid and we quit the function
        }
        i++;
    }
    return (OK);                                                //the tetriminoes are valid
}
//<<<<<<<<<<<<<<<<<<<<<<<STEP 3>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//checking if the tetrimino is valid
int     check_if_valid_tetr(char *tetr_stor)
{
    if (not_valid_symbol(tetr_stor))
    {
        return (ERROR);
    }
    if (not_valid_tetrimino(tetr_stor))
    {
        return (ERROR);
    }
}

//<<<<<<<<<<<<<<<<<<<<<<<STEP 2>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//the next function extends the storage
static  char   *append_stor(int size, char *tetr_stor)          //the returned value is static because next itteration we not gonna start from the beggining again
{
    char    *additional_stor;
    int     old_len;                                            //this is just a number, the old storage is tetr_stor

    additional_stor = malloc(sizeof(char) * size);              //alloc memory for additional storage
    ft_memset(additional_stor, 0, size);                        //fill the additional storage with 21 0-ros every time
    old_len = ft_strlen(tetr_stor);                             //here we calculate the len of tetr_stor and keep it in an integer
    ft_memcpy(additional_stor, tetr_stor, old_len);             //copying next tertrimito from old tetrimino storage to additional instead of 0-ros
    ft_strdel(tetr_stor);                                       //after copying we have to free the storage to avoid leeks
    return(additional_stor);                                    //return "rewritten" storage
}
//<<<<<<<<<<<<<<<<<<<<<<<STEP 1>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//read the text from the file and return valid tetrimino(which is text from the file):
char        *extract_tetrimino(char *file_name)
{
    int     fd;
    int     return_value;
    char    *buff;
    char    *tetr_stor;                                         //storage for tetrimino
    int     size;                                               //for additional storage(21+)

    fd = open(file_name, O_RDONLY);
    buff = ft_strnew(21);                                       //alloc with malloc string of 21 chars in memmory
    tetr_stor = ft_strnew(21);
    size = 21;                                                  //additional size (just a number)
    while ((return_value = read(fd, buff, 21)) > 0)             //reads 21 bytes (one by one tetrimino) till we go to the 0 (end of the file)
    {
        //chech if th e tetrimino is valid:
        //ft_strcat copies the tetrimino from the buff and keeps it in storage 
        ft_strcat(tetr_stor, buff);
        
        size += 21;                                             //every time we extending the additional size for storing new(next) tretrimino
        
        //here we call the function which appends the size or storage
        tetr_stor = append_stor(size, tetr_stor);               //assigning "rewritten" storage to tetrimino (line 27)
        ft_memset(buff, 0, 21);                                 //here we are "cleaning" the buff(fill with 0-ros) to be able temporary keeping next tetrimino
    }
    //we have to check if all the tetriminoes from file are valid
    if (check_if_valid_tetr(tetr_stor))
    {
        ft_putstr("Error\n");                                   //if check_if_valid fails
        return (ERROR);                                         //finish the program here
    } 
    return (tetr_stor);                                         //everything is valid, we return the tetrimino
}