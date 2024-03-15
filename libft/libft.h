/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wneel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:13:37 by wneel             #+#    #+#             */
/*   Updated: 2024/03/15 16:31:48 by wneel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

/**
 * Checks for an alphabetic character
 *
 * @param c unsigned char or EOF.
 * @return nonzero if the character c is alphabetic and zero if not.
 */
int		ft_isalpha(int c);

/**
 * Checks for a digit (0 through 9).
 *
 * @param c unsigned char or EOF.
 * @return nonzero if the character c is a digit (0 through 9) and zero if not.
 */
int		ft_isdigit(int c);

/**
 * Checks for an alphanumeric character.
 *
 * @param c unsigned char or EOF.
 * @return nonzero if the character c is alphanumeric and zero if not.
 */
int		ft_isalnum(int c);

/**
 * Checks whether c is a 7-bit unsigned char value that
 * fits into the ASCII character set.
 *
 * @param c unsigned char or EOF.
 * @return nonzero if the character c is ASCII and zero if not.
 */
int		ft_isascii(int c);

/**
 * Checks for any printable character including space.
 *
 * @param c unsigned char or EOF.
 * @return nonzero if the character c is printable and zero if not.
 */
int		ft_isprint(int c);

/**
 * Checks whether c is a whitespace character or not
 * according to `isspace(3)`.
 *
 * @param c unsigned char or EOF.
 * @return nonzero if the character c is whitespace and zero if not.
 */
int		ft_iswhitespace(char c);

/**
 * Calculates the length of the string pointed to by s,
 * excluding the terminating null byte ('\0').
 *
 * @param s String to count length..
 * @return the number of bytes in the string pointed to by `s`.
 */
size_t	ft_strlen(const char *s);

/**
 * Fills the first n bytes of the memory area pointed to
 * by s with the constant byte c.
 *
 * @param s String to be filled with `c`.
 * @param c character used to fill `s`.
 * @param n bytes of data to be filled in `s`.
 * @return a pointer to the memory area s.
 */
void	*ft_memset(void *s, int c, size_t n);

/**
 * Erases the data in the n bytes of the memory starting
 * at the location pointed to by s, by writing zeros
 * (bytes containing '\0') to that area.
 *
 * @param s Location to where the data erasure will start.
 * @param n bytes of data to be erased in `s`.
 * @return `void`
 */
void	ft_bzero(void *s, size_t n);

/**
 * Copies n bytes from memory area src to memory area dest.
 * The memory areas must not overlap.
 *
 * @param dst Destination string which src will be moved to.
 * @param src Source string to be moved in the destination.
 * @param size `n` characters to be moved to `dst`.
 * @return a pointer to dest.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * Copies n bytes from memory area src to memory area dest.
 * The memory areas may overlap.
 *
 * @param dst Destination string which src will be moved to.
 * @param src Source string to be moved in the destination.
 * @param size `n` characters to be moved to `dst`.
 * @return a pointer to dest.
 */
void	*ft_memmove(void *dest, const void *src, size_t n);

/**
 * Copy the given string src to dst.
 *
 * @param dst Destination string which src will be copied to.
 * @param src Source string to be copied in the destination.
 * @param size Full size of the buffer `dst`.
 * @return the total length of the string they tried to create.
 * That means the length of src.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

/**
 * Concatenate the given string src with dst to dst.
 *
 * @param dst Destination string which src will be added to.
 * @param src Source string to be concatenated in the destination.
 * @param size Full size of the buffer `dst`.
 * @return the total length of the string strlcat() tried to create.
 * That means the initial length of dst plus the length of src.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size);

/**
 * Put the given character to upper case if possible.
 *
 * @param c Character to be passed upper case.
 * @return the given character in upper case or `c` if the character
 * couldn't be passed to upper case.
 */
int		ft_toupper(int c);

/**
 * Put the given character to lower case if possible.
 *
 * @param c Character to be passed lower case.
 * @return the given character in lower case or `c` if the character
 * couldn't be passed to lower case.
 */
int		ft_tolower(int c);

/**
 * Locate character in string from the beginning.
 *
 * @param s String to search `c` into.
 * @param c Character to be searched in `s`.
 * @return a pointer to the matched character or `NULL` if the character
 * is not found.
 */
char	*ft_strchr(const char *s, int c);

/**
 * Locate character in string from the end.
 *
 * @param s String to search `c` into.
 * @param c Character to be searched in `s`.
 * @return a pointer to the matched character or `NULL` if the character
 * is not found.
 */
char	*ft_strrchr(const char *s, int c);

/**
 * Compares the two strings `s1` and `s2` (at most) `n` bytes.
 *
 * @param s1 String 1.
 * @param s2 String 2.
 * @param n The maximum amount of bytes to be compared.
 * @return an integer indicating the result of the comparison, as follows
 * 0, if the s1 and s2 are equal, a negative value if s1 is less than s2
 * a positive value if s1 is greater than s2.
 */
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * Scans the initial n bytes of the memory area pointed to by s for the
 * first instance of c.
 *
 * @param s Memory area to scan.
 * @param c Character to search for.
 * @param n The maximum amount of bytes to search for `c`.
 * @return a pointer to the matching byte or `NULL` if the character
 * does not occur in the given memory area.
 */
void	*ft_memchr(const void *s, int c, size_t n);

/**
 * Compares the first n bytes (each interpreted as unsigned char)
 * of the memoryareas s1 and s2
 *
 * @param s1 String 1.
 * @param s2 String 2.
 * @param n The maximum amount of bytes to be compared.
 * @return a pointer to the matching byte or `NULL` if the character
 * does not occur in the given memory area.
 */
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * Locate a substring in a string.
 *
 * @param big The string to search into.
 * @param little The substring to locate in `big`.
 * @param len how far should strnstr search.
 * @return If little is an empty string, big is returned; if little
 * occurs nowhere in big, `NULL` is returned otherwise a pointer to
 * the first character of the first occurrence of little is returned.
 */
char	*ft_strnstr(const char *big, const char *little, size_t len);

/**
 * Convert a string to an integer.
 *
 * @param nptr The string to be converted to an integer.
 * @return the converted value or 0 on error.
 */
int		ft_atoi(const char *nptr);

/**
 * Convert a string in the given base to an integer.
 *
 * @param str The string to be converted to an integer.
 * @param base The base the string must be in.
 * @return the converted value or 0 on error.
 */
int		ft_atoi_base(char *str, char *base);

/**
 * Allocates memory for an array of nmemb elements of size bytes.
 *
 * @param nmemb The number of elements.
 * @param size The size of each elements.
 * @return a pointer to the allocated memory.
 */
void	*ft_calloc(size_t nmemb, size_t size);

/**
 * Duplicate the string `s`.
 *
 * @param s The string to be duplicated.
 * @return a pointer to a new string which is a duplicate of the string s.
 */
char	*ft_strdup(const char *s);

/**
 * Allocates and returns a substring from the string `s`. The substring
 * begins at index `start` and is of maximum size `len`.
 *
 * @param s The string from which to create the substring.
 * @param start The start index of the substring in the string `s`.
 * @param len  The maximum length of the substring.
 * @return The substring. `NULL` if the allocation fails.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * Allocates and returns a new string, which is the result of
 * the concatenation of `s1` and `s2`.
 *
 * @param s1 The prefix string.
 * @param s2 The suffix string.
 * @return The new string. `NULL` if the allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * Allocates and returns a copy of `s1` with the characters
 * specified in `set` removed from the beginning and the
 * end of the string.
 *
 * @param s1 The string to be trimmed.
 * @param set The reference set of characters to trim.
 * @return The trimmed string. `NULL` if the allocation fails.
 */
char	*ft_strtrim(char const *s1, char const *set);

/**
 * Allocates and returns an array of strings obtained
 * by splitting `s` using the character `c` as a delimiter.
 * The array must end with a NULL pointer.
 *
 * @param s The string to be split.
 * @param c The delimiter character.
 * @return The array of new strings resulting from the split.
 * NULL if the allocation fails.
 */
char	**ft_split(char const *s, char c);

/**
 * Allocates and returns a string representing the
 * integer received as an argument. Negative numbers
 * must be handled.
 *
 * @param n the integer to convert.
 * @return The string representing the integer.
 * NULL if the allocation fails.
 */
char	*ft_itoa(int n);

/**
 * Applies the function `f` to each character of the
 * string `s`.
 *
 * @param s The string on which to iterate.
 * @param f The function to apply to each character.
 * @return The string created from the successive
 * applications of `f`. NULL if the allocation fails.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * Applies the function `f` to each character of the
 * string `s`.
 *
 * @param s The string on which to iterate.
 * @param f The function to apply to each character.
 * @return `void`
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/**
 * Outputs the character `c` to the given file descriptor.
 *
 * @param c The character to output.
 * @param fd The file descriptor on which to write.
 * @return `void`
 */
void	ft_putchar_fd(char c, int fd);

/**
 * Outputs the string `s` to the given file descriptor.
 *
 * @param s The string to output.
 * @param fd The file descriptor on which to write.
 * @return `void`
 */
void	ft_putstr_fd(char *s, int fd);

/**
 * Outputs the string `s` to the given file descriptor
 * followed by a newline.
 *
 * @param s The string to output.
 * @param fd The file descriptor on which to write.
 * @return `void`
 */
void	ft_putendl_fd(char *s, int fd);

/**
 * Outputs the integer `n` to the given file descriptor.
 *
 * @param n The integer to output.
 * @param fd The file descriptor on which to write.
 * @return `void`
 */
void	ft_putnbr_fd(int n, int fd);

/**
 * Linked list.
 *
 * @param content Any kind of *content.
 * @param next The next node of the list !
 */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}						t_list;

/**
 * Allocates and returns a new node. The member variable
 * `content` is initialized with the value of the parameter
 * `content`. The variable `next` is initialized to NULL.
 *
 * @param content The content to create the node with.
 * @return The new node.
 */
t_list	*ft_lstnew(void	*content);

/**
 * Adds the node `new` at the beginning of the list.
 *
 * @param lst  The address of a pointer to the first
 * link of a list.
 * @param new  The address of a pointer to the node
 * to be added to the list.
 * @return `void`
 */
void	ft_lstadd_front(t_list **lst, t_list *new);

/**
 * Counts the number of nodes in a list.
 *
 * @param lst The beginning of the list.
 * @return The length of the list
 */
int		ft_lstsize(t_list *lst);

/**
 * Returns the last node of the list.
 *
 * @param lst The beginning of the list.
 * @return the last node of the list.
 */
t_list	*ft_lstlast(t_list *lst);

/**
 * Adds the node `new` at the end of the list.
 *
 * @param lst The address of a pointer to the first link
 * of a list.
 * @param new The address of a pointer to the node to be
 * added to the list.
 * @return the last node of the list.
 */
void	ft_lstadd_back(t_list **lst, t_list *new);

/**
 * Frees the memory of the node.
 *
 * @param lst The node to free.
 * @param del The address of the function used to delete
 * the content.
 * @return `void`
 */
void	ft_lstdelone(t_list *lst, void (*del)(void*));

/**
 * Deletes and frees the given node and every successor
 * of that node.
 *
 * @param lst The address of a pointer to a node.
 * @param del  The address of the function used to delete
 * the content of the node.
 * @return `void`
 */
void	ft_lstclear(t_list **lst, void (*del)(void*));

/**
 * Iterates the list `lst` and applies the function
 * `f` on the content of each node.
 *
 * @param lst The address of a pointer to a node.
 * @param del   The address of the function used to iterate
 * on the list.
 * @return `void`
 */
void	ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * Applies the function `f` on the content of each node.
 * Creates a new list resulting of the successive applications
 * of the function `f`.
 *
 * @param lst The address of a pointer to a node.
 * @param f The address of the function used to iterate
 * on the list.
 * @param del The address of the function used to delete
 * the content of a node if needed.
 * @return The new list. NULL if the allocation fails.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/**
 * Free each element of the given tab and the tab itself.
 *
 * @param tab The char** to free.
 * @return `void`
 */
void	free_tab(char **tab);

#endif
