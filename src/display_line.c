/*
** EPITECH PROJECT, 2017
** getlineshell
** File description:
** display the line
*/

#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>

#include "getlineshell.h"
#include "my.h"
#include "defines.h"
#include "colors.h"

static void		wipedout_line(gls_t *gls)
{
  int			i;
  struct winsize	win;

  if (ioctl(1, TIOCGWINSZ, &win) < 0)
    return;
  i = real_str_size(gls->line, -1) + 15;
  while (i < win.ws_col)
  {
    write(1, " ", 1);
    ++i;
  }
  while (i > gls->curset.cursor + 15)
  {
    write(1, "\b", 1);
    --i;
  }
}

static void		set_beginning(gls_t *gls)
{
  int			i;

  i = 0;
  while (i < gls->curset.cursor + 15)
  {
    write(1, "\b", 1);
    ++i;
  }
}

void			display_line(gls_t *gls)
{
  set_beginning(gls);
  mprintf("%s", gls->line);
  wipedout_line(gls);
}
