/*
** EPITECH PROJECT, 2017
** getlineshell
** File description:
** shortcuts ctrl+l ctrl+d ...
*/

#include "getlineshell.h"
#include "my.h"
#include "defines.h"
#include "colors.h"

int		enter(__attribute__ ((unused)) gls_t *gls)
{
  return (DONE);
}

int		ctrl_l(__attribute__ ((unused)) gls_t *gls)
{
  mprintf(CLEARTOP);
  return (DONE);
}

int		ctrl_d(gls_t *gls)
{
  int		len;

  len = my_strlen(gls->line);
  if (gls->curset.cursor == 0 && len)
    zeros(gls->line, len);
  else if (!len)
  {
    sfree(&gls->line);
    *gls->lineptr = NULL;
  }
  return (DONE);
}

int		kbackspace(gls_t *gls)
{
  int		rpos;

  rpos = real_cursor_pos(gls);
  if (gls->curset.cursor > 0)
  {
    shift_left(gls->line + rpos - 1, 1);
    if (gls->line[rpos - 1] < 0)
    {
      shift_left(gls->line + rpos - 1, 1);
      --gls->curset.cursor;
    }
    --gls->curset.cursor;
  }
  return (DONE);
}
