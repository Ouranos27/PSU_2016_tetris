/*
** my_put_nbr.c for my_put_nbr in /home/amaury/CPool_Day07/lib/my
** 
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.eu>
** 
** Started on  Wed Oct 12 09:25:24 2016 Amaury Bernard
** Last update Wed Feb  8 14:32:26 2017 Amaury Bernard
*/

#include <stdlib.h>
#include "my.h"

int	my_nbr_digits(long long nb)
{
  int k;

  k = 1;
  while (nb > 9 || nb < -9)
    {
      nb = nb / 10;
      k++;
    }
  return (k);
}

void	my_put_nbr(long long nb, int *len)
{
  int	k;
  int	neg;
  char	*c;

  neg = 0;
  if (nb < 0)
    {
      neg = 1;
      nb = nb * -1;
    }
  k = my_nbr_digits(nb) + neg;
  if ((c = malloc(k)) == NULL)
    return;
  c[k--] = '\0';
  while ((k >= 0 && neg == 0) || (neg == 1 && k >= 1))
    {
      c[k] = '0' + (nb % 10);
      nb = nb / 10;
      k--;
    }
  if (neg == 1)
    c[0] = '-';
  my_putstr(c, len);
}
