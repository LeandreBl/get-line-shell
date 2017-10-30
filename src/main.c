/*
** EPITECH PROJECT, 2017
** getlineshell
** File description:
** main
*/

#include <termios.h>
#include <sys/ioctl.h>

#include "my.h"
#include "defines.h"

int			getlineshell(char **lineptr, char **hist);
int			set_getlineshell_term(struct termios *old);

int			main(void)
{
  char			*line;
  struct termios	old;

  set_getlineshell_term(&old);
  getlineshell(&line, NULL);
  mprintf("%s\n", line);
  ioctl(0, TCSETS, &old);
  sfree(&line);
  return (0);
}
