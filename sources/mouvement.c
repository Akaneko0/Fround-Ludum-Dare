/*
** mouvement.c for mouvement.c in /home/roig_a/GAME/sources
**
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
**
** Started on  Fri Jan 29 22:55:51 2016 Antoine Roig
** Last update Sun Apr 17 14:57:28 2016 Antoine Roig
*/

#include "game.h"

int	move_right(t_map **map)
{
  if (map[y_actual][x_actual + 1].obstacle == 1 ||
      (map[y_actual][x_actual + 1].item  == 1 &&
       map[y_actual][x_actual].item == 1))
    return (1);
  else if (map[y_actual][x_actual].item == 1 && map[y_actual][x_actual + 1].temple == 1)
    {
      y_item = 0;
      x_item = 0;
      map[y_actual][x_actual].item = 0;
      map[y_actual][x_actual].player = 0;
      map[y_actual][x_actual].ground = 1;
      map[y_actual][x_actual + 1].player = 1;
      map[y_actual][x_actual + 1].temple = 1;
      x_actual = x_actual + 1;
      h_temple = h_temple + 1;
    }
  else if (map[y_actual][x_actual + 1].item == 1)
    {
      /* y_item = y_actual; */
      /* x_item = x_actual + 1; */
      /* map[y_actual][x_actual + 1].player = 1; */
      /* map[y_actual][x_actual].player = 0; */
      /* map[y_actual][x_actual].ground = 1; */
      /* x_actual = x_actual + 1; */
      return (0);
    }
  else if (map[y_actual][x_actual + 1].enemy == 1 || map[y_actual][x_actual + 1].enemy2 == 1)
    return (2);
  else if (map[y_actual][x_actual + 1].hp == 1)
    {
      map[y_actual][x_actual + 1].hp = 0;
      map[y_actual][x_actual + 1].ground = 1;
      map[y_actual][x_actual].player = 0;
      map[y_actual][x_actual].ground = 1;
      map[y_actual][x_actual + 1].player = 1;
      map[y_actual][x_actual + 1].ground = 0;
      x_actual = x_actual + 1;
      hp++;
    }
  else
    {
      map[y_actual][x_actual].player = 0;
      map[y_actual][x_actual].ground = 1;
      if (map[y_actual][x_actual].item == 1)
	{
	  map[y_actual][x_actual + 1].item = 1;
	  map[y_actual][x_actual].item = 0;
	}
      map[y_actual][x_actual + 1].player = 1;
      map[y_actual][x_actual + 1].ground = 0;
      x_actual = x_actual + 1;
    }
  return (0);
}

int	move_left(t_map **map)
{
  if (map[y_actual][x_actual - 1].obstacle == 1 ||
     (map[y_actual][x_actual - 1].item  == 1 &&
       map[y_actual][x_actual].item == 1))
    return (1);
  else if (map[y_actual][x_actual].item == 1 && map[y_actual][x_actual - 1].temple == 1)
    {
      y_item = 0;
      x_item = 0;
      map[y_actual][x_actual].item = 0;
      map[y_actual][x_actual].player = 0;
      map[y_actual][x_actual].ground = 1;
      map[y_actual][x_actual - 1].player = 1;
      map[y_actual][x_actual - 1].temple = 1;
      h_temple = h_temple + 1;
      x_actual = x_actual - 1;
    }
  else if (map[y_actual][x_actual - 1].item == 1)
    {
      /* y_item = y_actual; */
      /* x_item = x_actual - 1; */
      /* map[y_actual][x_actual - 1].player = 1; */
      /* map[y_actual][x_actual].player = 0; */
      /* map[y_actual][x_actual].ground = 1; */
      /* x_actual = x_actual - 1; */
      return (0);
    }
  else if (map[y_actual][x_actual - 1].enemy == 1 || map[y_actual][x_actual - 1].enemy2 == 1)
    return (2);
  else if (map[y_actual][x_actual - 1].hp == 1)
    {
      map[y_actual][x_actual - 1].hp = 0;
      map[y_actual][x_actual - 1].ground = 1;
      map[y_actual][x_actual].player = 0;
      map[y_actual][x_actual].ground = 1;
      map[y_actual][x_actual - 1].player = 1;
      map[y_actual][x_actual - 1].ground = 0;
      x_actual = x_actual - 1;
      hp++;
    }
  else
    {
      map[y_actual][x_actual].player = 0;
      map[y_actual][x_actual].ground = 1;
      if (map[y_actual][x_actual].item == 1)
	{
	  map[y_actual][x_actual - 1].item = 1;
	  map[y_actual][x_actual].item = 0;
	}
      map[y_actual][x_actual - 1].player = 1;
      map[y_actual][x_actual - 1].ground = 0;
      x_actual = x_actual - 1;
    }
  return (0);
}

int	move_up_e(t_map **map)
{
  if (map[y_actual2 - 1][x_actual2].obstacle == 1 ||
      (map[y_actual2 - 1][x_actual2].item  == 1 &&
       map[y_actual2][x_actual2].item == 1))
    return (1);
  else
    {
      map[y_actual2][x_actual2].player2 = 0;
      map[y_actual2][x_actual2].ground = 1;
      map[y_actual2 - 1][x_actual2].player2 = 1;
      map[y_actual2 - 1][x_actual2].ground = 0;
      y_actual2 = y_actual2 - 1;
    }
  return (0);
}

int	move_down_e(t_map **map)
{
  if (map[y_actual2 + 1][x_actual2].obstacle == 1 ||
      (map[y_actual2 + 1][x_actual2].item  == 1 &&
       map[y_actual2][x_actual2].item == 1))
    return (1);
  else
    {
      map[y_actual2][x_actual2].player2 = 0;
      map[y_actual2][x_actual2].ground = 1;
      map[y_actual2 + 1][x_actual2].player2 = 1;
      map[y_actual2 + 1][x_actual2].ground = 0;
      y_actual2 = y_actual2 + 1;
    }
  return (0);
}

 int	move_left_e(t_map **map)
{
  if (map[y_actual2][x_actual2 - 1].obstacle == 1 ||
      (map[y_actual2][x_actual2 - 1].item  == 1 &&
       map[y_actual2][x_actual2].item == 1))
    return (1);
  else
    {
      map[y_actual2][x_actual2].player2 = 0;
      map[y_actual2][x_actual2].ground = 1;
      map[y_actual2][x_actual2 - 1].player2 = 1;
      map[y_actual2][x_actual2 - 1].ground = 0;
      x_actual2 = x_actual2 - 1;
    }
  return (0);
}

int	move_right_e(t_map **map)
{
  if (map[y_actual2][x_actual2 + 1].obstacle == 1 ||
      (map[y_actual2][x_actual2 + 1].item  == 1 &&
       map[y_actual2][x_actual2].item == 1))
    return (1);
  else
    {
      map[y_actual2][x_actual2].player2 = 0;
      map[y_actual2][x_actual2].ground = 1;
      map[y_actual2][x_actual2 + 1].player2 = 1;
      map[y_actual2][x_actual2 + 1].ground = 0;
      x_actual2 = x_actual2 + 1;
    }
  return (0);
}

int	move_up(t_map **map)
{
  if (map[y_actual + 1][x_actual].obstacle == 1 ||
      (map[y_actual + 1][x_actual].item  == 1 &&
       map[y_actual][x_actual].item == 1))
    return (1);
  else if (map[y_actual][x_actual].item == 1 && map[y_actual + 1][x_actual].temple == 1)
    {
      y_item = 0;
      x_item = 0;
      map[y_actual][x_actual].item = 0;
      map[y_actual][x_actual].player = 0;
      map[y_actual][x_actual].ground = 1;
      map[y_actual + 1][x_actual].player = 1;
      map[y_actual + 1][x_actual].temple = 1;
      y_actual = y_actual + 1;
      h_temple = h_temple + 1;
    }
  else if (map[y_actual + 1][x_actual].item == 1)
    {
      /* y_item = y_actual + 1; */
      /* x_item = x_actual; */
      /* map[y_actual + 1][x_actual].player = 1; */
      /* map[y_actual][x_actual].player = 0; */
      /* map[y_actual][x_actual].ground = 1; */
      /* y_actual = y_actual + 1; */
      return (0);
    }
  else if (map[y_actual + 1][x_actual].enemy == 1 || map[y_actual + 1][x_actual].enemy2 == 1)
    return (2);
  else if (map[y_actual + 1][x_actual].hp == 1)
    {
      map[y_actual + 1][x_actual].hp = 0;
      map[y_actual + 1][x_actual].ground = 1;
      map[y_actual][x_actual].player = 0;
      map[y_actual][x_actual].ground = 1;
      map[y_actual + 1][x_actual].player = 1;
      map[y_actual + 1][x_actual].ground = 0;
      y_actual = y_actual + 1;
      hp++;
    }
  else
    {
      map[y_actual][x_actual].player = 0;
      map[y_actual][x_actual].ground = 1;
      if (map[y_actual][x_actual].item == 1)
	{
	  map[y_actual + 1][x_actual].item = 1;
	  map[y_actual][x_actual].item = 0;
	}
      map[y_actual + 1][x_actual].player = 1;
      map[y_actual + 1][x_actual].ground = 0;
      y_actual = y_actual + 1;
    }
  return (0);
}

int	move_down(t_map **map)
{
  if (map[y_actual - 1][x_actual].obstacle == 1 ||
      (map[y_actual - 1][x_actual].item  == 1 &&
       map[y_actual][x_actual].item == 1))
    return (1);
  else if (map[y_actual][x_actual].item == 1 && map[y_actual - 1][x_actual].temple == 1)
    {
      y_item = 0;
      x_item = 0;
      map[y_actual][x_actual].item = 0;
      map[y_actual][x_actual].player = 0;
      map[y_actual][x_actual].ground = 1;
      map[y_actual - 1][x_actual].player = 1;
      map[y_actual - 1][x_actual].player = 1;
      y_actual = y_actual - 1;
      h_temple = h_temple + 1;
    }
  else if (map[y_actual - 1][x_actual].item == 1)
    {
      /* y_item = y_actual - 1; */
      /* x_item = x_actual; */
      /* map[y_actual - 1][x_actual].player = 1; */
      /* map[y_actual][x_actual].player = 0; */
      /* map[y_actual][x_actual].ground = 1; */
      /* y_actual = y_actual -1; */
      return (0);
    }
  else if (map[y_actual - 1][x_actual].enemy == 1 || map[y_actual - 1][x_actual].enemy2 == 1)
    return (2);
    else if (map[y_actual - 1][x_actual].hp == 1)
    {
      map[y_actual - 1][x_actual].hp = 0;
      map[y_actual - 1][x_actual].ground = 1;
      map[y_actual][x_actual].player = 0;
      map[y_actual][x_actual].ground = 1;
      map[y_actual - 1][x_actual].player = 1;
      map[y_actual - 1][x_actual].ground = 0;
      y_actual = y_actual - 1;
      hp++;
    }
  else
    {
      map[y_actual][x_actual].player = 0;
      map[y_actual][x_actual].ground = 1;
      if (map[y_actual][x_actual].item == 1)
	{
	  map[y_actual - 1][x_actual].item = 1;
	  map[y_actual][x_actual].item = 0;
	}
      map[y_actual - 1][x_actual].player = 1;
      map[y_actual - 1][x_actual].ground = 0;
      y_actual = y_actual - 1;
    }
  return (0);
}

int	put_rock(t_map **map, int key)
{
  if (orientation == 1)
    {
      if (shield == 0 && map[y_actual - 1][x_actual].ground == 1)
	{
	  map[y_actual - 1][x_actual].item = 1;
	  map[y_actual - 1][x_actual].ground = 0;
	  shield = 1;
	}
      else if (shield == 1 && map[y_actual - 1][x_actual].ground == 0)
	{
	  map[y_actual - 1][x_actual].item = 0;
	  map[y_actual - 1][x_actual].ground = 1;
	  shield = 0;
	}
    }
  else if (orientation == 2)
    {
      if (shield == 0 && map[y_actual + 1][x_actual].ground == 1)
	{
	  map[y_actual + 1][x_actual].item = 1;
	  map[y_actual + 1][x_actual].ground = 0;
	  shield = 1;
	}
      else if (shield == 1 && map[y_actual + 1][x_actual].ground == 0)
	{
	  map[y_actual + 1][x_actual].item = 0;
	  map[y_actual + 1][x_actual].ground = 1;
	  shield = 0;
	}
    }
  else if (orientation == 3)
    {
      if (shield == 0 && map[y_actual][x_actual - 1].ground == 1)
	{
	  map[y_actual][x_actual - 1].item = 1;
	  map[y_actual][x_actual - 1].ground = 0;
	  shield = 1;
	}
      else if (shield == 1 && map[y_actual][x_actual - 1].ground == 0)
	{
	  map[y_actual][x_actual - 1].item = 0;
	  map[y_actual][x_actual - 1].ground = 1;
	  shield = 0;
	}
    }
  else if (orientation == 4)
    {
      if (shield == 0 && map[y_actual][x_actual + 1].ground == 1)
	{
	  map[y_actual][x_actual + 1].item = 1;
	  map[y_actual][x_actual + 1].ground = 0;
	  shield = 1;
	}
      else if (shield == 1 && map[y_actual][x_actual + 1].ground == 0)
	{
	  map[y_actual][x_actual + 1].item = 0;
	  map[y_actual][x_actual + 1].ground = 1;
	  shield = 0;
	}
    }

  return (0);
}

int	pop_enemy1(t_map **map)
{
  map[y_actual2][x_actual2].enemy2 = 1;
  return (0);
}

int	pop_enemy2(t_map **map)
{
  map[y_actual2][x_actual2].enemy = 1;
  return (0);
}

int	check_mouvement(int key, t_map **map)
{
  if (key == 261)
    return (move_right(map));
  else if (key == 8)
    return (pop_enemy1(map));
  else if (key == 9)
    return (pop_enemy2(map));
  else if (key == 260)
    return (move_left(map));
  else if (key == 258)
    return (move_up(map));
  else if (key == 259)
    return (move_down(map));
  else if (key == 1)
      return (move_up_e(map));
  else if (key == 2)
      return (move_down_e(map));
  else if (key == 3)
      return (move_left_e(map));
  else if (key == 4)
      return (move_right_e(map));
  return (0);
}
