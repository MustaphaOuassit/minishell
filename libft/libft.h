/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:12:23 by ayafdel           #+#    #+#             */
/*   Updated: 2021/12/21 10:38:14 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int		ft_memcmp(const void *str1, const void *str2, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t n);
void	*ft_memcpy(void *str1, const void *str2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);
int		ft_atoi(const char *str);
void	*ft_memmove(void *str1, const void *str2, size_t n);
size_t	ft_strlen(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *str, int c, size_t n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	*ft_calloc(size_t nitems, size_t size);
void	ft_putchar_fd(char c, int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isalnum(int n);
void	ft_putendl_fd(char *s, int fd);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_isalpha(int n);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strrchr(const char *str, int c);
int		ft_isascii(int n);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strtrim(char const *s1, char const *set);
int		ft_isdigit(int n);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *str, unsigned int start, size_t len);
int		ft_isprint(int n);
char	*ft_strchr(const char *str, int c);
int		ft_tolower(int n);
char	*ft_itoa(int m);
char	*ft_strdup(const char *s);
int		ft_toupper(int n);
void	*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void	*ft_memchr(const void *str, int c, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
void	print_strings(char **strings);
char	*ft_strjoin_char(char const *s1, char const *s2, char c);
char	*ft_free_first(char *first, char *str);
void	ft_error_msg(char *str);
void	ft_error_two_msg(char *str_one, char *str_two);
void	ft_free_split(char **tab);
int		ft_indexof(char *str, char c);
char	*ft_strdup_null(const char *s);
int		ft_strcmp(char *str1, char *str2);
#endif
