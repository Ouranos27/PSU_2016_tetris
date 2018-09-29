/*
** debug_mode.c for tetris in /home/ouranos27/my_desktop/PSU/PSU_2016_tetris
** 
** Made by philippe kam
** Login   <philippe.kam@epitech.eu>
** 
** Started on  Wed Mar  1 11:22:54 2017 philippe kam
** Last update Wed Mar  1 11:22:54 2017 philippe kam
*/

#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "tetris.h"

char	*str_add(char *fst, char *end)
{
  char	*str;
  int	i;
  int	j;

  if ((str = malloc(sizeof(char) * (my_strlen(fst) + my_strlen(end)))) == NULL)
    return (NULL);
  i = 0;
  while (fst[i] != '\0')
    {
      str[i] = fst[i];
      ++i;
    }
  j = 0;
  while (end[j] != '\0')
    {
      str[i] = end[j];
      ++i;
      ++j;
    }
  str[i] = '\0';
  return (str);
}

int	check_file(int fd)
{
  my_printf("\n");
  return (0);
}

int	check_filename(char *name)
{
  int	i;

  if (name[0] == '.')
    return (ERROR);
  i = my_strlen(name) - EXT_LEN;
  if (my_strcmp(&name[i], EXT) != 0)
    return (ERROR);
  return (0);
}

void	show_name(char *name)
{
  int	i;
  int	j;

  j = my_strlen(name) - EXT_LEN;
  i = 0;
  while (i < j)
    {
      my_printf("%c", name[i]);
      ++i;
    }
  my_printf(" :");
}
int		debug_files()
{
  struct dirent	*file;
  DIR		*rep;
  int		fd;

  if ((rep = opendir("./tetriminos/")) == NULL)
     return (SUICIDE);
  while ((file = readdir(rep)) != NULL)
    {
      if (check_filename(file->d_name) == 0)
	{
	  my_printf("Tetriminos : Name ");
	  show_name(file->d_name);
	  if ((fd = open(str_add("./tetriminos/", file->d_name),O_RDONLY)) < 0)
	    my_printf("Error\n"); // Ou return Suicide
	  if (check_file(fd) == SUICIDE)
	    return (SUICIDE); //La plus part du temps il faudra print error.
	}
    }
  if (closedir(rep) == -1)
    return (SUICIDE);
  return (0);
}

int	main()
{
  return (debug_files());
}
