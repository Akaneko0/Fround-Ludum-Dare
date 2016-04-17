/*
** get_coords.c for get_coords.c in /home/roig_a/GAME
** 
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
** 
** Started on  Fri Jan 29 20:14:10 2016 Antoine Roig
** Last update Sat Jan 30 20:58:52 2016 Tanguy LELIEVRE
*/

#include "game.h"

int     get_x(char *buffer)
{
  int   i;
  int   x;

  x = 0;
  i = 0;
  while (buffer[i] != '\n')
    {
      i++;
      x++;
    }
  return (x);
}

int     get_y(char *buffer)
{
  int   i;
  int   y;

  y = 0;
  i = 0;
  while (buffer[i] != '\0')
    {
      if (buffer[i] == '\n')
        y++;
      i++;
    }
  return (y);
}

t_var   *get_x_y(char *buffer, t_var *var)
{
  var->x = get_x(buffer);
  var->y = get_y(buffer);
  y_map = var->y;
  x_map = var->x;
  return (var);
}
