/*
** EPITECH PROJECT, 2017
** getlineshell
** File description:
** head function
*/

#include <termios.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <term.h>

#include "getlineshell.h"
#include "my.h"

int			set_getlineshell_term(struct termios *old)
{
  struct termios        new;

  if (ioctl(0, TCGETS, &new) == -1)
    return (-1);
  if (old != NULL)
    *old = new;
  new.c_lflag &= ~ICANON;
  new.c_lflag &= ~ECHO;
  new.c_cc[VINTR] = 0;
  new.c_cc[VMIN] = 1;
  new.c_cc[VTIME] = 0;
  if (ioctl(0, TCSETS, &new) == -1)
    return (-1);
  return (0);
}

static int		set_gls(char **lineptr, char **hist, gls_t *gls)
{
  if (lineptr == NULL)
    return (-1);
  gls->lineptr = lineptr;
  gls->line = my_calloc(DEFAULT_LINE_SIZE);
  gls->hist = hist;
  gls->n = 0;
  zeros(gls->buffer, DEFAULT_READ_SIZE + 1);
  return (0);
}

int			getlineshell(char **lineptr, char **hist)
{
  gls_t			gls;

  if (set_gls(lineptr, hist, &gls))
    return (-1);
  while (nb_of(gls.line, '\n') == 0)
  {
    if (gls.line == NULL)
      return (0);
    gls.rd = read(0, gls.buffer, DEFAULT_READ_SIZE);
    gls.n += gls.rd;
    if (gls.rd < 0)
      break;
    my_strcat(gls.line, gls.buffer);
    display_inside(gls.buffer, "%d", DEFAULT_READ_SIZE);
    if (gls.rd + 3 > DEFAULT_LINE_SIZE)
      gls.line = my_frealloc(gls.line, DEFAULT_LINE_SIZE);
    mprintf("%s\n", gls.line);
  }
  *lineptr = gls.line;
  shift_right(gls.line, 1);
  gls.n = my_strlen(gls.line);
  return (gls.n + 1);
}
