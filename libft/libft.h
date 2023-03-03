#ifndef LIBFT_H
# define LIBFT_H

# define BUFFER_SIZE 200

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>


size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup(const char *str);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar(char c);

/**** GNL ******/
int		is_eol(char *data);
char	*get_line(char *str);
char	*read_file(int fd, char *buffer);
char	*update_buffer(char *str, char *substr);
char	*get_next_line(int fd);

/**** SPLIT *****/
int		ft_tabsize(char const *s, char c);
void	*ft_freetab(char **tab, int n);
void	*ft_filltab(char **tab, char const *s, char c);
char	**ft_split(char const *s, char c);

/***** FT_PRINTF ******/
int	ft_putchar_printf(char c);
int	ft_putstr(char *str);
int	ft_putnbr(long int nbr, int len);
int	ft_parse(va_list buffer, char tag);
int	ft_printf(const char *str, ...);

#endif