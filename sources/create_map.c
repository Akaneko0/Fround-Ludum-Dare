/*
** create_map.c for create_map.c in /home/roig_a/GAME
**
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
**
** Started on  Fri Jan 29 20:26:44 2016 Antoine Roig
** Last update Sun Apr 17 14:06:28 2016 Antoine Roig
*/

#include "game.h"

t_map	fill_emplacement(char buffer, t_map map)
{
  map.obstacle = 0;
  map.player = 0;
  map.player2 = 0;
  map.temple = 0;
  map.item = 0;
  map.enemy = 0;
  map.enemy2 = 0;
  map.ground = 0;
  map.boul = 0;
  map.hp = 0;
  if (buffer == '0')
    map.obstacle = 1;
  else if (buffer == '1')
    map.player = 1;
  else if (buffer == '2')
    map.temple = 1;
  else if (buffer == '3')
    {
      map.item = 1;
      item++;
    }
  else if (buffer == '4')
    map.enemy = 1;
  else if (buffer == 'C')
    map.hp = 1;
  else if (buffer == '5')
    map.enemy2 = 1;
  else if (buffer == ' ')
    map.ground = 1;
  else if (buffer == '9')
    map.player2 = 1;
  return (map);
}

t_map	fill_last_emplacement(t_map map)
{
  map.obstacle = 1;
  map.player = 0;
  map.player2 = 0;
  map.temple = 0;
  map.item = 0;
  map.enemy = 0;
  map.enemy2 = 0;
  map.ground = 0;
  return (map);
}

t_map	**create_map(t_var *var, char *buffer)
{
  t_map	**map;
  int   i;
  int   x;
  int   y;

  y = 0;
  i = 0;
  map = xmalloc(sizeof(t_map *) * (var->y + 1));
  while (buffer[i])
    {
      map[y] = xmalloc(sizeof(t_map) * (var->x) + 1);
      x = 0;
      while (buffer[i] != '\n')
      	{
	  if (buffer[i] == '1')
	    {
	      y_actual = y;
	      x_actual = x;
	      x_beg = x;
	      y_beg = y;
	    }
	  if (buffer[i] == '9')
	    {
	      y_actual2 = y;
	      x_actual2 = x;
	    }
      	  map[y][x] = fill_emplacement(buffer[i], map[y][x]);
      	  i++;
      	  x++;
      	}
      y++;
      i++;
    }
  map[y] = NULL;
  return (map);
}
