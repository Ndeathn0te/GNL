#include "get_next_line_bonus.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // Include for read function

/*
 * Polish linked list for next call
 */
void	polish_list(t_list **list)
{
	t_list	*last_node;
	t_list	*clean_node;
	char	*buf;

	int i, k;
	buf = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
	if (!buf || !clean_node)
	{
		free(buf);        // Free buf if clean_node allocation fails
		free(clean_node); // Free clean_node if buf allocation fails
		return ;
	}
	last_node = find_last_node(*list);
	for (i = 0; last_node->str_buf[i] && last_node->str_buf[i] != '\n'; i++)
		;
	for (k = 0; last_node->str_buf[i]; buf[k++] = last_node->str_buf[++i])
		;
	buf[k] = '\0';
	clean_node->str_buf = buf;
	clean_node->next = NULL;
	dealloc(list, clean_node, buf);
}

/*
 * Get my line (line\n)
 */
char	*get_theline(t_list *list)
{
	int		str_len;
	char	*next_str;

	if (!list)
		return (NULL);
	str_len = len_to_newline(list);
	next_str = malloc(str_len + 1);
	if (!next_str)
		return (NULL);
	copy_str(list, next_str);
	return (next_str);
}

/*
 * Append one node to the end of the list
 */
void	append(t_list **list, char *buf)
{
	t_list	*new_node;
	t_list	*last_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
	{
		free(buf); // Free buf if new_node allocation fails
		return ;
	}
	last_node = find_last_node(*list);
	if (!last_node)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->str_buf = buf;
	new_node->next = NULL;
}

void	create_list(t_list **list, int fd)
{
	int		char_read;
	char	*buf;

	while (!found_newline(*list))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return ;
		char_read = read(fd, buf, BUFFER_SIZE);
		if (char_read <= 0)
		{
			free(buf); // Free buf if read fails or EOF
			return ;
		}
		buf[char_read] = '\0';
		append(list, buf);
	}
}

/*
 * Main function to get the next line from a file descriptor
 */
char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	create_list(&list, fd);
	if (!list)
		return (NULL);
	next_line = get_theline(list);
	polish_list(&list);
	return (next_line);
}
