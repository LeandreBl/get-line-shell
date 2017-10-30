/*
** EPITECH PROJECT, 2017
** getlineshell
** File description:
** header
*/

#ifndef GETLINESHELL_H_
# define GETLINESHELL_H_

# define DEFAULT_TMP_FOLDER	("/tmp/getlineshellXXXXXX")
# define DEFAULT_TMP_SHFILE	("shfile.tmp")
# define DEFAULT_LINE_SIZE	(256)
# define DEFAULT_READ_SIZE	(3)

struct	gls_s
{
  char	buffer[DEFAULT_READ_SIZE + 1];
  char	**hist;
  char	**lineptr;
  char	*line;
  int	rd;
  int	n;
};

typedef struct gls_s gls_t;

#endif /* !GETLINESHELL_H_ */
