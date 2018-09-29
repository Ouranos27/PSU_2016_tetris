/*
** tetris.h for tetris in /home/ouranos27/my_desktop/PSU/PSU_2016_tetris/include
** 
** Made by philippe kam
** Login   <philippe.kam@epitech.eu>
** 
** Started on  Mon Feb 27 10:30:20 2017 philippe kam
** Last update Mon Feb 27 14:54:28 2017 philippe kam
*/

#ifndef TETRIS_H_
# define TETRIS_H_
# define SUICIDE	84

#include <ncurses.h>

typedef struct	s_var
{
  char	*one_dash;
  char	*two_dashes;
  int	value1;
  int	value2;
}		t_var;

int	my_strcmp(char *s1, char *s2);
int	my_putstr(char *str);
int	my_printf(char *str, ...);
void	usage();
void	debug_keys();

#endif /* !TETRIS_H_ */
