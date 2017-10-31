/*
** EPITECH PROJECT, 2017
** getlineshell
** File description:
** set ioctl configs
*/

#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>

int                     set_getlineshell_term(struct termios *old)
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
