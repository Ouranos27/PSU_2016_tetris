/*
** debug_keys.c for tetris in /home/ouranos27/my_desktop/PSU/PSU_2016_tetris
** 
** Made by philippe kam
** Login   <philippe.kam@epitech.eu>
** 
** Started on  Thu Mar  2 16:25:58 2017 philippe kam
** Last update Thu Mar  2 16:25:58 2017 philippe kam
*/

#include <term.h>
#include <ncurses.h>
#include "tetris.h"
t_var	*params_list; //dans un header

void	debug_keys()
{
  /*char	*keys;
  setupterm("xterm", 1, &i);
  keys = tigetstr("smkx");*/
    my_printf("*** DEBUG MODE ***\n");
    //my_printf("Key Left :  %s\n", keys);
    my_printf("Key Right :  %s\n", params_list->one_dash);
    /*printf("Key Turn :  %c\n", params_list[2].value1);
    printf("Key Drop :  %c\n", params_list[3].value1);
    printf("Key Quit :  %c\n", params_list[4].value1);
    printf("Key Pause :  %c\n", params_list[5].value1);
    if (params_list[6].value1 == 0)
      printf("Next :  Yes\n");
    else
      printf("Next :  No\n");
    printf("Level :  %d\n", params_list[7].value1);
    printf("Size :  %d*%d\n", params_list[9].value1, params_list[9].value2);*/
}
