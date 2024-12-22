/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmheidat <mmheidat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 01:13:49 by mmheidat          #+#    #+#             */
/*   Updated: 2024/12/22 19:21:13 by mmheidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdint.h>
# include "ft_printf.h"
# include "get_next_line.h"

int			ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strslen(char **strs);
void		ft_error(char *message);
char		**ft_strsjoin(char **strs, char *str);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_free_to_trim(char *s1, const char *set);
int			ft_is_set(char c, const char *set);
char		*ft_strtrim(char const *s1, const char *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strdup(const char *s1);
int			words(const char *str, char c);
char		**ft_split(char const *s, char c);
int			ft_isdigit(int c);
int			ft_atoi(const char *str);
char		*ft_strdup_fork(char *src, int from, int to);
int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_word_count(char const *str, char sep);
#endif