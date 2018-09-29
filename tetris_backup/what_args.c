/*
** what_args.c for my_ls in /home/amaury/delivery/PSU_2016_my_ls
** 
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.eu>
** 
** Started on  Sun Dec  4 15:41:22 2016 Amaury Bernard
** Last update Sun Dec  4 17:23:02 2016 Amaury Bernard
*/

#include "./include/my_ls.h"

void    set_to_nul(char *str, int len)
{
  int   i;

  i = 0;
  while (i < len)
    {
      str[i] = 0;
      i++;
    }
}

char    *decla_char_args()
{
  char  *char_args;

  if ((char_args = malloc(sizeof(char) * NB_ARGS)) == NULL)
  exit (84);
  char_args[0] = 'l';
  char_args[1] = 'R';
  char_args[2] = 'd';
  char_args[3] = 'r';
  char_args[4] = 't';
  char_args[5] = 'a';
  return (char_args);
}

void    what_flags(char **av, int ac, int i, char *args)
{
  int   j;
  char  *char_args;

  char_args = decla_char_args();
  while (av[ac][i] != 0)
    {
      j = 0;
      while (av[ac][i] != char_args[j] && j < NB_ARGS)
	j++;
      if (av[ac][i++] == char_args[j])
	args[j] = 1;
      else
	exit (84);
    }
  free (char_args);
}

char    **what_args(int ac, char **av, char *args)
{
  char  **ways;
  int   i;
  int   k;

  k = 0;
  if ((ways = malloc(sizeof(char *) * (ac))) == NULL)
    exit (84);
  while (--ac > 0)
    {
      i = 0;
      if (av[ac][i++] == '-')
	what_flags(av, ac, i,  args);
      else
	ways[k++] = av[ac];
    }
  ways[k] = NULL;
  return (ways);
}
