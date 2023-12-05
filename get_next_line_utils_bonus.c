#include "get_next_line_bonus.h"
#include <stdlib.h> // For free

/*Check if there is a newline character in the list*/
int	found_newline(t_list *list)
{
	int	i;

	while (list)
	{
		i = 0;
		while (list->str_buf[i] && i < BUFFER_SIZE)
		{
			if (list->str_buf[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

/*Find the last node in the list*/
t_list	*find_last_node(t_list *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

/*Copy characters from the list up to the newline character*/
void	copy_str(t_list *list, char *str)
{
	int i, k = 0;
	while (list)
	{
		i = 0;
		while (list->str_buf[i])
		{
			str[k++] = list->str_buf[i];
			if (list->str_buf[i] == '\n')
				break ;
			i++;
		}
		if (list->str_buf[i] == '\n')
		{
			str[k] = '\0';
			return ;
		}
		list = list->next;
	}
	str[k] = '\0';
}

/*Calculate the length of the string in the list up to the newline character*/
int	len_to_newline(t_list *list)
{
	int i, len = 0;
	while (list)
	{
		i = 0;
		while (list->str_buf[i])
		{
			if (list->str_buf[i] == '\n')
				return (len + 1);
			i++;
			len++;
		}
		list = list->next;
	}
	return (len);
}

/* Deallocate all nodes in the list and set head to NULL or to a new node */
void	dealloc(t_list **list, t_list *clean_node, char *buf)
{
	t_list	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->str_buf);
		free(*list);
		*list = tmp;
	}
	if (clean_node->str_buf[0])
	{
		*list = clean_node;
	}
	else
	{
		free(buf);
		free(clean_node);
	}
}
