/*
** get_map.c for get_map.c in /home/roig_a/GAME/Fround-Ludum-Dare
**
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
**
** Started on  Sun Apr 17 15:44:38 2016 Antoine Roig
** Last update Sun Apr 17 15:44:39 2016 Antoine Roig
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
