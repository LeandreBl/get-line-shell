/*
** EPITECH PROJECT, 2017
** getlineshell
** File description:
** header
*/

#ifndef GETLINESHELL_H_
# define GETLINESHELL_H_

# include <termios.h>

# define DEFAULT_TMP_FOLDER	("/tmp/getlineshellXXXXXX")
# define DEFAULT_TMP_SHFILE	("shfile.tmp")
# define DEFAULT_LINE_SIZE	(256)
# define DEFAULT_READ_SIZE	(3)
# define NB_BUILTINS		(6)
# define DONE			(1)

struct			curset_s
{
  int			calls;
  char			**cmds;
  int			cursor;
  int			hist;
};

struct			gls_s
{
  struct curset_s	curset;
  char			buffer[DEFAULT_READ_SIZE + 1];
  char			**lineptr;
  char			*line;
  int			rd;
  int			n;
};

struct			fction_s
{
  char			code[DEFAULT_READ_SIZE + 1];
  int			(*fction)(struct gls_s *gls);
};

typedef struct gls_s gls_t;
typedef struct fction_s fction_t;

int		real_str_size(const char *str, int to);
int		real_cursor_pos(gls_t *gls);
int		set_getlineshell_term(struct termios *old);
void		display_line(gls_t *gls);
int		builtins(gls_t *gls);
int		ctrl_l(gls_t *gls);
int		ctrl_d(gls_t *gls);
int		kbackspace(gls_t *gls);
int		enter(gls_t *gls);
void		insert_inline(gls_t *gls);
int		left_arrow(gls_t *gls);
int		right_arrow(gls_t *gls);

#endif /* !GETLINESHELL_H_ */
