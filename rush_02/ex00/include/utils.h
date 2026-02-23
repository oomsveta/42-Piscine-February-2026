/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 14:22:45 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/22 22:39:09 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stddef.h>
# include <stdbool.h>

typedef struct s_buffer
{
	char	*content;
	size_t	length;
	size_t	capacity;
}	t_buffer;

bool			ft_streq(const char *s1, const char *s2);
char			*ft_strchr(const char *str, int chr);
char			*ft_strndup(const char *str, size_t n);
char			*read_line(int fd);
int				ft_atoi(const char *nptr);
int				ft_isdigit(int c);
int				ft_strcmp(const char *s1, const char *s2);
size_t			ft_strcspn(const char *str, const char *spn);
size_t			ft_strlen(const char *str);
size_t			ft_strnlen(const char *str, size_t n);
size_t			ft_strspn(const char *str, const char *spn);
size_t			ft_zmax(size_t a, size_t b);
unsigned int	substr_to_uint(const char *nptr, size_t len);
void			*ft_memchr(const void *buffer, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			ft_putstr(const char *str);
void			puterr(const char *error_msg);

#endif
