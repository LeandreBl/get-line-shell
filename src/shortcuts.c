/*
** EPITECH PROJECT, 2017
** getlineshell
** File description:
** shortcuts alt+L ctrl+L ...
*/

#include "getlineshell.h"
#include "my.h"
#include "defines.h"
#include "colors.h"

int		ctrl_l(__attribute__ ((unused)) gls_t *gls)
{
  mprintf(CLEARTOP);
  return (DONE);
}

int		ctrl_d(__attribute__ ((unused)) gls_t *gls)
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
  if (gls->curset.cursor > 0)
  {
    --gls->curset.cursor;
    if (gls->line[gls->curset.cursor] < 0)
      shift_right(gls->line, 1);
    shift_right(gls->line , 1);
  }
  return (DONE);
}
