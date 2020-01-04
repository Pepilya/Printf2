/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipepelia <ipepelia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 13:03:35 by ipepelia          #+#    #+#             */
/*   Updated: 2019/10/23 18:03:00 by ipepelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct          s_spec{
    char *flags;
    int  width;
    int  acc;
    char *accFlag;
    int  mod;
    char type;
    char *text;
    struct s_spec *next;
    struct s_spec *prev;
}                       t_spec;

#endif
