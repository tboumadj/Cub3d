/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:21:10 by tboumadj          #+#    #+#             */
/*   Updated: 2023/02/20 22:37:33 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     LIBFT_H
# define    LIBFT_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

# define BUFFER_SIZE 42

//--------------Get_Next_Line-------------------//
size_t		ft_strlen(const char *str);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_read(int fd, char *str);
char		*ft_line(char *str);
char		*ft_save(char *str);
char		*get_next_line(int fd);

//---------------PRINTF-----------------//
int			ft_printf(const char *format, ...);
int			ft_pourcentdi(int nb);
int			ft_pourcentp(unsigned long long ptr);
int			ft_pourcents(char *s);
int			ft_pourcenttwice(void);
int			ft_pourcentu(unsigned int nb);
int			ft_pourcentx(unsigned int num);
int			ft_pourcentupperx(unsigned int num);
int			ft_putchar(int c);
int			ft_search_arg(va_list arg, const char format);
void		ft_putnbrx(unsigned int num);
int			ft_strintx(unsigned int nb);
int			ft_strintupperx(unsigned int nb);
void		ft_putnbrupperx(unsigned int num);
int			ft_strintu(unsigned int nb);
void		ft_putnbrp(unsigned long long num);
int			ft_strintp(unsigned long long nb);
int			ft_strint(int nb);

//------------LIBFT------------------------//
int			ft_atoi(const char *str);
char		*ft_itoa(int n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strdup(const char *s);

#endif
