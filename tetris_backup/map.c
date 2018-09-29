/*
** map.c for readdin maps in /home/ouranos27/my_desktop/PSU/PSU_2016_my_sokoban
** 
** Made by philippe kam
** Login   <philippe.kam@epitech.eu>
** 
** Started on  Wed Dec 14 12:14:13 2016 philippe kam
** Last update Thu Feb 23 16:50:44 2017 philippe kam
*/

void	draw_map(char **map)
{
  int	i;

  i = 0;
  while (map[i])
    {
      printw("%s\n", map[i]);
      i++;
    }
  printw("\n");
}

/*void	move_left(t_map map, t_pos pos)
{
  clear();
  left(map, pos);
}

void	move_right(t_map map, t_pos pos)
{
  clear();
  right(map, pos);
}

void	move_up(t_map map, t_pos pos)
{
  clear();
  up(map, pos);
}

void	move_down(t_map map, t_pos pos)
{
  clear();
  down(map, pos);
  }*/
