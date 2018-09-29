/*
** gen_map.c for tetris in /home/ouranos27/my_desktop/PSU/PSU_2016_tetris
** 
** Made by philippe kam
** Login   <philippe.kam@epitech.eu>
** 
** Started on  Sat Mar  4 11:11:37 2017 philippe kam
** Last update Sat Mar  4 11:11:37 2017 philippe kam
*/

#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char	**map_malloc(int width, int height)
{
  int	i;
  char	**map;

  i = 0;
  if ((map = malloc(sizeof(char *) * height + 1)) == NULL)
    return (NULL);
  while (i < height)
    {
      if ((map[i] = malloc(sizeof(char) * width + 1)) == NULL)
	return (NULL);
      ++i;
    }
  return (map);
}

char	**first_filling(char **map, int width)
{
  int	i;

  i = 1;
  map[0][0] = '+';
  while (i < width)
    {
      map[0][i] = '-';
      ++i;
    }
  map[0][width] = '+';
  map[0][width + 1] = '\0';
  return (map);
}

char    **last_filling(char **map, int width, int i)
{
  int   j;

  map[i][0] = '+';
  j = 1;
  while (j < width)
    {
      map[i][j] = '-';
      ++j;
    }
  map[i][width] = '+';
  map[i][width + 1] = '\0';
  map[i + 1] = NULL;
  return (map);
}

char	**second_filling(char **map, int width, int height)
{
  int	i;
  int	j;

  i = 1;
  while (i < height - 1)
    {
      j = 1;
      map[i][0] = '|';
      while (j < width)
	{
	  map[i][j] = ' ';
	  ++j;
	}
      map[i][width] = '|';
      map[i][width + 1] = '\0';
      ++i;
    }
  map = last_filling(map, width, i);
  return (map);
}

char	**map_filling(char **map, int width, int height)
{
  map = first_filling(map, width);
  map = second_filling(map, width, height);
  return (map);
}

void    draw_map(char **map)
{
  int   i;

  i = 0;
  while (map[i])
    {
      printw("%s\n", map[i]);
      ++i;
    }
}

char	**moves(char **map)
{
  int	key;
  int	i;
  int	j;

  i = 1;
  j = 1;
  map[i][j] = '*';
  draw_map(map);
  key = getch();
  while (key != 27)
    {
      key = getch();
      if (sleep(1) == 0)
	clear();
      if (key == KEY_RIGHT)
	{
	  map[i][j] = ' ';
	  ++j;
	  map[i][j] = '*';
	}
      if (key == KEY_LEFT)
	{
	  map[i][j] = ' ';
	  --j;
	  map[i][j] = '*';
	}
      if (map[i + 1][j] == '-' || map[i + 1][j] == '*')
	{
	  i = 1;
	  ++j;
	  map[i][j] = '*';
	}
      if (map[i][j + 1] == '|')
	j = 1;
      map[i + 1][j] = '*';
      map[i][j] = ' ';
      draw_map(map);
      ++i;
    }
  return (map);
}

int      main()
{
  int	key;
  char  **map;

  initscr();
  nodelay(stdscr, TRUE);
  cbreak();
  curs_set(0);
  keypad(stdscr, TRUE);
  refresh();
  map = map_malloc(20, 20);
  map = map_filling(map, 20, 20);
  map = moves(map);
  endwin();
  return (0);
}
