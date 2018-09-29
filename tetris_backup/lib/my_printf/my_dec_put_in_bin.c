/*
** my_dec_put_in_bin.c for my_dec_put_in_bin in /home/amaury.bernard/PSU_2016_my_printf
** 
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.net>
** 
** Started on  Tue Nov 15 20:02:52 2016 Amaury Bernard
** Last update Wed Feb  8 14:34:32 2017 Amaury Bernard
*/

#include "my.h"
#include <stdlib.h>

int     my_nbr_digits_bin(unsigned long long nb)
{
  int k;

  k = 1;
  while (nb > 1)
    {
      nb = nb / 2;
      k++;
    }
  return (k);
}

void	my_dec_put_in_bin(unsigned long long nb, int *len)
{
  int	i;
  char	*str;

  i = my_nbr_digits_bin(nb);
  if ((str = malloc(i)) == NULL)
    return;
  str[i--] = '\0';
  while (i >= 0)
    {
      str[i--] = '0' + (nb % 2);
      nb = nb / 2;
    }
  my_putstr(str, len);
}
