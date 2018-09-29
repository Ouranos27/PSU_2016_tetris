/*
** my_putchar.c for my_putchar in /home/amaury/CPool_Day03
** 
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.eu>
** 
** Started on  Wed Oct  5 10:42:23 2016 Amaury Bernard
** Last update Tue Jan 17 15:46:23 2017 Amaury Bernard
*/

#include <unistd.h>

void    my_putchar(char c, int *len)
{
  write(1, &c, 1);
  *len += 1;
}
