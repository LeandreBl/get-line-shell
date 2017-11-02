/*
** EPITECH PROJECT, 2017
** getlineshell
** File description:
** up down left right arrows
*/

#include "getlineshell.h"

int		right_arrow(gls_t *gls)
{
  int		rpos;

  rpos = real_cursor_pos(gls);
  if (gls->curset.cursor < rpos)
    ++gls->curset.cursor;
  return (DONE);
}

int		left_arrow(gls_t *gls)
{
  if (gls->curset.cursor > 0)
    --gls->curset.cursor;
  return (DONE);
}
