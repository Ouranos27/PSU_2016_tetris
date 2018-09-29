/*
** player.c for player's moves in /home/ouranos27/my_desktop/PSU/PSU_2016_my_sokoban
** 
** Made by philippe kam
** Login   <philippe.kam@epitech.eu>
** 
** Started on  Mon Dec 19 14:31:25 2016 philippe kam
** Last update Tue Dec 20 20:42:09 2016 philippe kam
*/

#include "include/my_sokoban.h"

t_pos		player(t_map map)
{
  int		i;
  int		j;
  t_pos		pos;

  i = 0;
  pos.x = 0;
  pos.y = 0;
  while (map.map[i] != '\0')
    {
      j = 0;
      while (map.map[i][j] != '\0')
	{
	  if (map.map[i][j] == 'P')
	    {
	      pos.x = j;
	      pos.y = i;
	    }
	  j = j + 1;
	}
      i = i + 1;
    }
  return (pos);
}

void	left(t_map map, t_pos pos)
{
  if (map.map[pos.y][pos.x] == 'P' && map.map[pos.y][pos.x - 1] == 'X')
    {
      if (map.map[pos.y][pos.x - 2] != '#' && map.map[pos.y][pos.x - 2] != 'X')
	{
	  map.map[pos.y][pos.x] = ' ';
	  map.map[pos.y][pos.x - 1] = 'P';
	  map.map[pos.y][pos.x - 2] = 'X';
	}
    }
  else if (map.map[pos.y][pos.x] == 'P' && map.map[pos.y][pos.x - 1] != 'X')
    {
      if (map.map[pos.y][pos.x - 1] != '#')
	{
	  map.map[pos.y][pos.x] = ' ';
	  map.map[pos.y][pos.x - 1] = 'P';
	}
    }
}

void	right(t_map map, t_pos pos)
{
  if (map.map[pos.y][pos.x] == 'P' && map.map[pos.y][pos.x + 1] == 'X')
    {
      if (map.map[pos.y][pos.x + 2] != '#' && map.map[pos.y][pos.x + 2] != 'X')
	{
	  map.map[pos.y][pos.x] = ' ';
	  map.map[pos.y][pos.x + 1] = 'P';
	  map.map[pos.y][pos.x + 2] = 'X';
	}
    }
  else if (map.map[pos.y][pos.x] == 'P' && map.map[pos.y][pos.x + 1] != 'X')
    {
      if (map.map[pos.y][pos.x + 1] != '#')
	{
	  map.map[pos.y][pos.x] = ' ';
	  map.map[pos.y][pos.x + 1] = 'P';
	}
    }
}

void	down(t_map map, t_pos pos)
{
  if (map.map[pos.y][pos.x] == 'P' && map.map[pos.y + 1][pos.x] == 'X')
    {
      if (map.map[pos.y + 2][pos.x] != '#' && map.map[pos.y + 2][pos.x] != 'X')
	{
	  map.map[pos.y][pos.x] = ' ';
	  map.map[pos.y + 1][pos.x] = 'P';
	  map.map[pos.y + 2][pos.x] = 'X';
	}
    }
  else if (map.map[pos.y][pos.x] == 'P' && map.map[pos.y + 1][pos.x] != 'X')
    {
      if (map.map[pos.y + 1][pos.x] != '#')
	{
	  map.map[pos.y][pos.x] = ' ';
	  map.map[pos.y + 1][pos.x] = 'P';
	}
    }
}

void	up(t_map map, t_pos pos)
{
  if (map.map[pos.y][pos.x] == 'P' && map.map[pos.y - 1][pos.x] == 'X')
    {
      if (map.map[pos.y - 2][pos.x] != '#' && map.map[pos.y - 2][pos.x] != 'X')
	{
	  map.map[pos.y][pos.x] = ' ';
	  map.map[pos.y - 1][pos.x] = 'P';
	  map.map[pos.y - 2][pos.x] = 'X';
	}
    }
  else if (map.map[pos.y][pos.x] == 'P' && map.map[pos.y - 1][pos.x] != 'X')
    {
      if (map.map[pos.y - 1][pos.x] != '#')
	{
	  map.map[pos.y][pos.x] = ' ';
	  map.map[pos.y - 1][pos.x] = 'P';
	}
    }
}
