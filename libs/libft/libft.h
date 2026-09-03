/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:19:10 by ncruz-ne          #+#    #+#             */
/*   Updated: 2026/09/03 18:13:46 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>

/* libft only */
# include <limits.h>
# include <sys/resource.h>
# include <sys/time.h>
# include <stdbool.h>

/* ft_printf() only */
# include <stdarg.h>

/* get_next_line() only */
# include <fcntl.h>
# include <stdint.h>
# include <stdio.h>

/* get_next_line() only */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/* libft */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/* ft_printf() */
typedef struct s_fmt
{
	int				i;
	int				len;
	int				errchck;
}					t_fmt;

/* get_next_line() */
typedef struct s_read_to_nl_vars
{
	int		i;
	int		buf_len_nl;
	ssize_t	bytesread;
}			t_read_to_nl_vars;

/* libft */
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
bool	ft_isspace(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_atoi(const char *nptr);
int		ft_lstsize(t_list *lst);

char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strjoin_free(char *s1, char *s2);

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);

void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_lstadd_front(t_list **lst, t_list *new_node);
void	ft_lstadd_back(t_list **lst, t_list *new_node);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));

t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* ft_printf() */
int		ft_printf(const char *format, ...);
int		ft_printf_ptr(void *ptr);
int		ft_putnbr_fd_len(long long n, int fd);
int		ft_putchar_fd_len(char c, int fd);
int		ft_putstr_fd_len(const char *s, int fd);
int		ft_printf_hex(size_t n, int len, char x);
int		ft_nlen(long long n);

/* get_next_line() */
char	*get_next_line(int fd);
char	*read_until_nl(int fd, char *buf, char *line);

#endif