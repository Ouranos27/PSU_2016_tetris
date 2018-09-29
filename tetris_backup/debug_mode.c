/*
** debug_mode.c for tetris in /home/ouranos27/my_desktop/PSU/PSU_2016_tetris
** 
** Made by philippe kam
** Login   <philippe.kam@epitech.eu>
** 
** Started on  Wed Mar  1 11:22:54 2017 philippe kam
** Last update Wed Mar  1 11:22:54 2017 philippe kam
*/

#include <dirent.h>

char		*name_parser(char *name)
{
  int		i;
  char		*temp;

  i = 0;
  temp = malloc(sizeof(name));
  while (name[i] != '.')
    {
      temp[i] = name[i];
      i++;
    }
  printf("%s\n", temp);
  return (temp);
}

char		*total()
{
  struct dirent	*file;
  DIR		*rep;
  char		*temp;
  int		i;
  int		j;

  i = 0;
  j = 0;
  rep = opendir("./tetriminos/");
  temp = malloc(sizeof(char));
  while ((file = readdir(rep)))
    {
      if (file->d_name[0] != '.')
	{
	  i++;
	  temp = name_parser(file->d_name);
	}
    }
  if (closedir(rep) == -1)
    return (-1);
  printf("Tetriminos :  %d\n", i);
  return (0);
}

int	main()
{
  total();
  return (0);
}
