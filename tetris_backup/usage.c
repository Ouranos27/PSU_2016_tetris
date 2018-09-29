/*
** usage.c for tetris in /home/ouranos27/my_desktop/PSU/PSU_2016_my_tetris
** 
** Made by philippe kam
** Login   <philippe.kam@epitech.eu>
** 
** Started on  Tue Dec 13 19:25:21 2016 philippe kam
** Last update Mon Feb 27 11:35:01 2017 philippe kam
*/

#include "include/tetris.h"

void	usage()
{
  my_putstr("Usage:\t.tetris [options]\n");
  my_putstr("Option:\n");
  my_putstr("  --help\t\tDisplay this help\n");
  my_putstr("  -l --level={num}\tStart Tetris at level num (def: 1)\n");
  my_putstr("  -kl --key-left={K}\tMove the tetrimino LEFT using the K key");
  my_putstr(" (def: left arrow)\n");
  my_putstr("  -kr --key_right={K}\tMove the tetrimino RIGHT using the K key");
  my_putstr(" (def: right arrow)\n");
  my_putstr("  -kt --key-turn={K}\tTURN the tetrimino clockwise 90d using the K");
  my_putstr(" Key (def: top arrow)\n");
  my_putstr("  -kd --key-drop={K}\tDROP the tetrimino using the K key (def: down)\n");
  my_putstr("  -kq --key-quit={K}\tQUIT the game using the K key (def: 'Q' key)\n");
  my_putstr("  -kp --key-pause={K}\tPAUSE/RESTART the game using the K key (def: ");
  my_putstr("space bar\n");
  my_putstr("  --map-size={row, col}\tSet the numbers of rows and columns of the ");
  my_putstr("map (def: 20,10)\n");
  my_putstr("  -w --without-next\tHide next tetrimino (def: false)\n");
  my_putstr("  -d --debug\tDebug mode (def: false)\n");
}

/*void	reset(t_map map)
{
  clear();
  map.map = my_str_to_wordtab(map);
  }*/
