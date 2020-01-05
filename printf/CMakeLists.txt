cmake_minimum_required(VERSION 3.15)
project(printf C)

set(CMAKE_C_STANDARD 99)

add_executable(printf main.c libft/ft_itoa_base.c libft/ft_atoi.c libft/ft_strchr.c libft/ft_strdel.c libft/ft_strsub.c libft/ft_bzero.c libft/ft_strlen.c libft/ft_strnew.c libft/ft_strncpy.c libft/ft_strsub_mod.c
        libft/ft_itoa.c libft/ft_putchar.c libft/ft_putstr.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_strdup.c libft/ft_toupper.c libft/ft_isalpha.c libft/ft_itoa_base_long.c libft/ft_itoa_base_ulong.c ParsingString.c AddSpecifiers.c CreateListSpecifiers.c PrintString.c PrintChar.c PrintNumSigned.c PrintNumSpecifiers.c PrintNumUnsigned.c ft_printf.c)