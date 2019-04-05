/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 13:31:40 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/04/04 15:55:24 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H                                //if we dont have header file...
# define FILLIT_H                               //...define it

# include <fcntl.h>                             //man 2 open()
# include <sys/types.h>                         //man 2 read
# include <sys/uio.h>                           //man 2 read
# include <unistd.h>                            //man 2 read

# define     OK       0
# define     ERROR    -1

//this is the structure for STEP 5
typedef struct s_number_of_symbols{
    int hash;
    int dot;
    int new_line;
}   t_number_of_symbols;

//this is the structure for STEP 11
typedef struct  s_tetr{
    int     x[4];
    int     y[4];
    char    name_for_tetr;   
}   t_tetr;

#endif