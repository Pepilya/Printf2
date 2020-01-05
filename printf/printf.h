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

/*typedef struct		s_list
{
	char			*content;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;*/

typedef struct          s_spec{
    char *flags;
    int  width;
    int  acc;
    char *accFlag;
    int  mod;
    char type;
    char *text;
    int  isPercent;
    struct s_spec *next;
    struct s_spec *prev;
}                       t_spec;

/* ft_printf */

void ft_printf(const char *f, ...);

/* ParsingString */

t_spec *checkString(const char *f);
t_spec *getSpec(t_spec *sp);
int isSpec(const char *f, int i);
void valid(const char *s, t_spec *sp);

/* CreateSpecifiers.c */

int setAccuracy(t_spec *sp, const char *s, int i);
int isUniq(char *flags, char c);
int toInt(char *s, int start, int len);
int wrongSymbols(char c);
void setMod(t_spec *sp, char *s, int i);

/* CreateListSpecifiers.c */
t_spec *getSpec(t_spec *sp);
void init(t_spec *sp);

/* PrintChar */
void printChar(t_spec *sp, char c);

/* PrintString */
void printString(t_spec *sp, char *s);

/* PRINT INTEGER */

/* PrintNumSigned.c */
void printNum(t_spec *sp, long long int d);
char *changeNumType(t_spec *sp, long long int d);

/* PrintNumUnsigned.c */
void printUnsignedNum(t_spec *sp, unsigned long long int d);
char *changeUnNumType(t_spec *sp, unsigned long long int d);
void toUpper(char *str);

/* PrintNumSpecifiers.c */
int isDecimal(t_spec *sp);
void cutLength(t_spec *sp);
void printWidth(t_spec *sp, char *toPrint);
void printAccuracy(t_spec *sp, char *toPrint);


#endif
