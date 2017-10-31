/*
** EPITECH PROJECT, 2017
** getlineshell
** File description:
** key combo handlers
*/

#include "getlineshell.h"
#include "my.h"

static void		__add_ptr(char code[], fction_t *index,
				  int (*fction)(gls_t *gls))
{
  memcopy(index->code, code, DEFAULT_READ_SIZE + 1);
  index->fction = fction;
}

static void		init_ptr_tab(fction_t ptr_tab[])
{
  __add_ptr("\f\0\0\0", &ptr_tab[0], ctrl_l);
  __add_ptr("\04\0\0\0", &ptr_tab[1], ctrl_d);
  __add_ptr("\x7f\0\0\0", &ptr_tab[2], kbackspace);
}

int			builtins(gls_t *gls)
{
  static fction_t	ptr_tab[NB_BUILTINS];
  int			i;

  i = 0;
  if (gls->curset.calls == 1)
    init_ptr_tab(ptr_tab);
  while (i < NB_BUILTINS)
  {
    if (my_strcmp(gls->buffer, ptr_tab[i].code) == 0)
      return (ptr_tab[i].fction(gls));
    ++i;
  }
  return (0);
}
