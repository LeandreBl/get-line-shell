/*
** EPITECH PROJECT, 2017
** getlineshell
** File description:
** head function
*/

#include <unistd.h>

#include "getlineshell.h"
#include "my.h"

static int		set_gls(char **lineptr, char **hist, gls_t *gls)
{
  if (lineptr == NULL)
    return (-1);
  zeros(gls->buffer, DEFAULT_READ_SIZE + 1);
  gls->lineptr = lineptr;
  gls->line = my_calloc(DEFAULT_LINE_SIZE);
  gls->curset.cmds = hist;
  gls->n = 0;
  gls->curset.cursor = 0;
  gls->curset.hist = 0;
  gls->curset.calls = 0;
  return (0);
}

static int		adjust_alloc_size(gls_t *gls)
{
  ++gls->curset.calls;
  if ((gls->n % DEFAULT_LINE_SIZE) + my_strlen(gls->buffer) > DEFAULT_LINE_SIZE)
    gls->line = my_frealloc(gls->line, DEFAULT_LINE_SIZE + 1);
  if (gls->line == NULL)
    return (-1);
  return (0);
}

static int		read_next_(gls_t *gls)
{
  zeros(gls->buffer, DEFAULT_READ_SIZE + 1);
  gls->rd = read(0, gls->buffer, DEFAULT_READ_SIZE);
  gls->n += gls->rd;
  if (gls->rd < 0)
    return (1);
  return (0);
}

int			getlineshell(char **lineptr, char **hist)
{
  gls_t			gls;

  if (set_gls(lineptr, hist, &gls))
    return (-1);
  while (nb_of(gls.buffer, '\n') == 0)
  {
    if (read_next_(&gls) == 1)
      break;
    if (adjust_alloc_size(&gls) == -1)
      return (-1);
    if (!builtins(&gls))
      insert_inline(&gls);
    if (gls.line == NULL)
      return (0);
    display_line(&gls);
  }
  *lineptr = gls.line;
  gls.n = my_strlen(gls.line);
  return (gls.n + 1);
}
