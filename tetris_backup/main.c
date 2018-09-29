/*
** my_main.c for my sokoban$ in /home/ouranos27/my_desktop/PSU/PSU_2016_my_tetris
** 
** Made by philippe kam
** Login   <philippe.kam@epitech.eu>
** 
** Started on  Tue Dec 13 19:08:04 2016 philippe kam
** Last update Mon Feb 27 15:11:21 2017 philippe kam
*/

#include <term.h>
#include <ncurses.h>
#include <stdlib.h>
#include "tetris.h"

/*void		moves(t_map map)
{
  t_pos		pos;
  int		key;

  draw_map(map.map);
  key = getch();
  while (key != 27)
    {
      key = getch();
      pos = player(map);
      if (key == KEY_LEFT)
	move_left(map, pos);
      else if (key == KEY_RIGHT)
	move_right(map, pos);
      else if (key == KEY_DOWN)
	move_down(map, pos);
      else if (key == KEY_UP)
	move_up(map, pos);
      else if (key == ' ')
	reset(map);
      draw_map(map.map);
    }
}

int		buffer_len(char *filepath)
{
  char		*buffer;
  ssize_t	line;
  FILE		*fd;
  size_t	len;
  int      	i;

  len = 0;
  i = 0;
  fd = fopen(filepath, "r");
  if (fd == NULL)
    return (84);
  buffer = NULL;
  while ((line = getline(&buffer, &len, fd)) > 0)
    i = i + line;
  fclose(fd);
  return (i);
}

char	*buffer(char *filepath, t_map map)
{
  int	fd;
  int	rep;

  if ((fd = open(filepath, O_RDONLY)) == -1)
    exit(84);
  if ((rep = read(fd, map.buffer, map.size)) == -1)
    exit(84);
  close(fd);
  return (map.buffer);
  }*/

t_var	params_list[] =
  {
    {"-kl", "--key-left", KEY_LEFT, -1},
    {"-kr", "--key-right", KEY_RIGHT, -1},
    {"-kt", "--key-turn", KEY_UP, -1},
    {"-kd", "--key-drop", KEY_DOWN, -1},
    {"-kq", "--key-quit", 'q', -1},
    {"-kp", "--key-pause", ' ', -1},
    {"-w", "--without-next", 0, -1},
    {"-l", "--level", 1, -1},
    {"-d", "--debug", 0, -1},
    {NULL, "--map-size", 20, 10},
    {NULL, "--help", 0, -1},
    {NULL}
  };

/*int	 main_loop(char *av)
{
  char	**map;

  initscr();
  cbreak();
  curs_set(0);
  keypad(stdscr, TRUE);
  refresh();
  
  moves(map);
  endwin();
  return (0);
  }*/

int	my_strcmp2(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] == s2[i] && s1[i] != '\0' && (s2[i] != '\0' || s2[i] != '='))
    i = i + 1;
  if (s1[i] == '\0' && s2[i] == '=')
    return (i + 1);
  return (-1);
}

int	the_getnbr(char **str)
{
  int	i;
  int	var;

  var = 0;
  i = 0;
  while (str[0][i] != '\0' && str[0][i] != ',')
    {
      var = var * 10;
      var = var + str[0][i] - '0';
      i = i + 1;
    }
  *str += i + 1;
  return (var);
}

void	flags_checking(char *arg)
{
  int	i;
  int	idx_eq;

  i = 0;
  while (params_list[i].two_dashes != '\0')
    {
      if ((idx_eq = my_strcmp2(params_list[i].two_dashes, arg)) != -1)
	{
	  arg = &arg[idx_eq];
	  if (*arg != '\0')
	    {
	      params_list[i].value1 = the_getnbr(&arg);
	      params_list[i].value2 = the_getnbr(&arg);
	    }
	  else
	    params_list[i].value1 = 1;
	  my_printf("%d\n", params_list[i].value1);
	  //printf("%d\n", params_list[i].value2);
	}
      ++i;
    }
}

void	handler(char *arg)
{
  my_printf("%s\n", arg);
  /*if (my_strcmp(arg, "-d") == 0 || my_strcmp(arg, "--debug") == 0)
    debug_keys();*/
}

void	flags_checking_2(char *flag, char *arg)
{
  int	i;

  i = 0;
  while (params_list[i].one_dash != '\0')
    {
      if ((my_strcmp(params_list[i].one_dash, flag)) == 0)
	handler(arg);
      ++i;
    }
}

int	gest_args(char **av)
{
  int	i;

  i = 0;
  while (av[i] != NULL)
    {
      if (av[i][0] == '-' && av[i][1] != '-')
	{
	  flags_checking_2(av[i], av[i + 1]);
	}
      else if (av[i][0] == '-' && av[i][1] == '-')
	{
	  flags_checking(av[i]); // verif 84
	}
      /*else
	return (SUICIDE);*/
      ++i;
    }
  return (0);
}

void	debug_keys()
{
  int	i;
  char	*keys;

  setupterm("xterm", 1, &i);
  keys = tigetstr("smkx");
  my_printf("%s\n", keys);
  my_printf("*** DEBUG MODE ***\n");
  my_printf("Key Left :  %c\n", params_list[0].value1);
  my_printf("Key Right :  %c\n", params_list[1].value1);
  my_printf("Key Turn :  %c\n", params_list[2].value1);
  my_printf("Key Drop :  %c\n", params_list[3].value1);
  my_printf("Key Quit :  %c\n", params_list[4].value1);
  my_printf("Key Pause :  %c\n", params_list[5].value1);
  if (params_list[6].value1 == 0)
    my_printf("Next :  Yes\n");
  else
    my_printf("Next :  NO\n");
  my_printf("Level :  %d\n", params_list[7].value1);
  my_printf("Size :  %d*%d\n", params_list[9].value1, params_list[9].value2);
}

int	main(int ac, char **av)
{
  if (ac == 1 || gest_args(av) == SUICIDE)
    return (SUICIDE);
  debug_keys();
  /*if (ac == 2 && (my_strcmp(av[1], "--help") == 0))
    usage();*/
  /*else
    {
      main_loop(av[1]);
      }*/
  return (0);
}
