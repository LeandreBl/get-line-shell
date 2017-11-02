/*
** EPITECH PROJECT, 2017
** getlineshell
** File description:
** real line size
*/

#include "getlineshell.h"

#include "my.h"

int		real_str_size(const char *str, int to)
{
  int           i;
  int           size;

  i = 0;
  size = 0;
  if (to < 0)
    to = my_strlen(str);
  while (i < to && str[i] != 0)
  {
    if (str[i] < 0)
      ++i;
    ++size;
    ++i;
  }
  return (size);
}

int		real_cursor_pos(gls_t *gls)
{
  return (real_str_size(gls->line, gls->curset.cursor + 1));
}
