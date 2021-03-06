#ifndef _LISTE_H_
# define LISTE_H_

# include <stdlib.h>

typedef struct		s_list
{
  void			*data;
  struct s_list	*next;
}			t_list;

void	my_add_to_list(t_list **begin, void *data);
void	my_rm_list(t_list *begin, int (*f)(void*));
void	my_apply_on_list(t_list *begin, int (*f)(void*, void*), void *arg);
void	my_rm_from_list(t_list **begin, int (*remove)(void*, void*),
                      int (*f)(void*), void *arg);
int	my_list_size(t_list *begin);

#endif
