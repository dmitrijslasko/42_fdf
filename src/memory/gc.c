#include "fdf.h"

// typedef struct s_pointer
// {
//     void    *ptr;
//     char    *description;
//     struct s_pointer *next;
// }   t_pointer;

void	gc_add(t_list **pointers, void *ptr, char *desc);

void gc_free_all(t_list **pointers);

void *gc_malloc(t_list **pointers, int size, char *desc)
{
	void	*ptr;

    ft_putstr_fd("gc_malloc: Request to create pointer for: ", 1);
    ft_putstr_fd(desc, 1);
	ft_putchar_fd('\n', 1);
	if (size < 0)
		return (NULL);
	ptr = ft_calloc(size, 1);
	if (ptr == NULL)
    {
        gc_free_all(pointers);
        exit (1);
    }
	gc_add(pointers, ptr, desc);
	ft_putstr_fd("gc_malloc: Added pointer >>> ", 1);
	ft_putstr_fd(desc, 1);
	ft_putchar_fd('\n', 1);
	return (ptr);
}

void	gc_add(t_list **pointers, void *ptr, char *desc)
{
    t_list  *pointer;

    ft_putstr_fd("gc_malloc: Adding pointer to the end of the struct: ", 1);
    ft_putstr_fd(desc, 1);
	ft_putchar_fd('\n', 1);
    pointer = ft_lstnew(ptr);
	ft_lstadd_front(pointers, pointer);
}

void gc_free_all(t_list **pointers)
{
    t_list *current;
    t_list *next;

    puts("gc_free_all: Cleaning started...");
    current = *pointers;
    while (current)
    {
        next = current->next;
        if (current->content)
        {
            free(current->content);
            current->content = NULL;
            puts("Freed content...");
        }
        free(current);
        puts("Freed pointer...");
        current = next;
    }
    // *pointers = NULL;
    puts("gc_free_all: Freed all pointers");
}