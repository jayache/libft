/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 19:44:10 by jayache           #+#    #+#             */
/*   Updated: 2018/12/01 17:24:13 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef LIBFT_H
#	define LIBFT_H

#	include <string.h>
#	include <stdlib.h>
#	include <unistd.h>
#	include <math.h>
#	include "mlx.h"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_btree
{
	void			*data;
	struct s_btree	*right;
	struct s_btree	*left;
	struct s_btree	*parent;
}					t_btree;

typedef struct		s_vector2
{
	float			x;
	float			y;
}					t_vector2;

typedef struct		s_vector3
{
	float			x;
	float			y;
	float			z;
}					t_vector3;

typedef struct		s_pixel
{
	void			*mlxid;
	void			*winid;
	int				color;
}					t_pixel;

int					ft_toupper(int c);
int					ft_tolower(int c);

void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void	**ap);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_tmalloc(void **target, size_t size);

int					ft_atoi(const char *str);
size_t				ft_strlen(const char *s);
size_t				ft_strnlen(const char *s, size_t maxlen);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strncat(char *s1, const char *s2, size_t len);
char				*ft_strcat(char *s1, const char *s2);
size_t				ft_strlcat(char *s1, const char *s2, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strmapi(const char *s, char(*f)(unsigned int, char));
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				*ft_itoa(int nb);
char				**ft_strsplit(char const *s, char c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
int					ft_strpbrk(const char *s, const char *charset);

size_t				ft_cntspback(char const *s, char const c);
size_t				ft_cntspfront(char const *s, char const c);
int					ft_sign(int n);
unsigned long		ft_abs(int nb);
int					ft_nblen(int nb);

int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_iswhitespace(int c);

void				ft_putchar(unsigned int c);
void				ft_putstr(const char *s);
void				ft_putendl(const char *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putnbr_fd(int nb, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putnbr(int nb);
void				ft_putendl_fd(const char *s, int fd);

void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** VECTOR FUNCTION
*/

t_vector2			ft_vector2(float x, float y);
t_vector2			ft_vector2_normalize(t_vector2 vec);
t_vector2			ft_vector2_multiply(t_vector2 vec, float scalar);
t_vector2			ft_vector2_add(t_vector2 vec, t_vector2 vec2);
float				ft_vector2_magnitude(t_vector2 vec);
float				ft_vector2_angle(t_vector2 vec1, t_vector2 vec2);
float				ft_vector2_rangle(t_vector2 vec1, t_vector2 vec2);
float				ft_vector2_dot(t_vector2 vec1, t_vector2 vec2);

t_vector3			ft_vector3(float x, float y, float z);
t_vector3			ft_vector3_normalize(t_vector3 vec);
float				ft_vector3_magnitude(t_vector3 vec);
float				ft_vector3_dot(t_vector3 vec1, t_vector3 vec2);
t_vector3			ft_vector3_multiply(t_vector3 vec1, float scalar);
t_vector3			ft_vector3_cross(t_vector3 vec1, t_vector3 vec2);
float				ft_vector3_angle(t_vector3 vec1, t_vector3 vec2);
t_vector3			ft_vector3_axis(t_vector3 vec1, t_vector3 vec2);
t_vector3			ft_vector3_add(t_vector3 vec1, t_vector3 vec2);
/*
** DRAWING FUNCTION
*/

void				ft_draw_rect(t_vector2 beg, t_vector2 end, t_pixel *pixel);
void				ft_draw_lign(t_vector2 beg, t_vector2 size, t_pixel *pixel);
#	endif
