/*
** my_strcmp.c for my_strcmp.c in /home/pipolm.pk/CPool_Day06
** 
** Made by Philippe KAM
** Login   <pipolm.pk@epitech.net>
** 
** Started on  Tue Oct 11 13:44:20 2016 Philippe KAM
** Last update Mon Feb 27 11:30:46 2017 philippe kam
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
      i = i + 1;
  return (s1[i] - s2[i]);
}
