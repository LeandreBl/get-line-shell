/*
** EPITECH PROJECT, 2017
** getlineshell
** File description:
** insert buffer inside str
*/

#include "getlineshell.h"

#include "my.h"
#include "defines.h"

void		insert_inline(gls_t *gls)
{
  int		rpos;

  rpos = real_cursor_pos(gls);
  my_strncpy(gls->line + rpos + gls->rd, gls->line + rpos, my_strlen(gls->line + rpos));
  my_strncpy(gls->line + rpos, gls->buffer, gls->rd);
  ++gls->curset.cursor;
}
