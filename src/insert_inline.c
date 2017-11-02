/*
** EPITECH PROJECT, 2017
** getlineshell
** File description:
** insert buffer inside str
*/

#include "getlineshell.h"

#include "my.h"
#include "defines.h"
#include <string.h>

static void	shift(char *str, int size)
{
  int		i;
  int		nb;

  nb = 0;
  while (nb < size)
  {
    i = my_strlen(str);
    while (i > 0)
    {
      str[i] = str[i - 1];
      --i;
    }
    ++nb;
  }
}

void		insert_inline(gls_t *gls)
{
  shift(gls->line + gls->curset.cursor, gls->rd);
  my_strncpy(gls->line + gls->curset.cursor, gls->buffer, gls->rd);
  gls->curset.cursor += gls->rd;
}
