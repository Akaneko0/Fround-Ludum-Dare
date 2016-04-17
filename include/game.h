/*
** game.h for game.h in /home/roig_a/GAME/include
**
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
**
** Started on  Fri Jan 29 19:32:51 2016 Antoine Roig
** Last update Sun Apr 17 13:44:15 2016 Antoine Roig
*/

#ifndef GAME_H_

# define GAME_H_

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <ncurses.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <time.h>

int x_actual;
int y_actual;
int x_actual2;
int y_actual2;
int hp;
int h_temple;
int x_item;
int y_item;
int x_beg;
int y_beg;
int y_map;
int x_map;
int orientation;
int item;
int	c;
int shield;

typedef struct s_var
{
  int   x;
  int   y;
}       t_var;

typedef struct s_map
{
  int	obstacle;
  int	player;
  int	player2;
  int	temple;
  int	item;
  int	enemy;
  int	enemy2;
  int	ground;
  int	boul;
  int	hp;
}	t_map;

t_var           *get_x_y(char *buffer, t_var *var);
void            *xmalloc(int size);
t_map		**create_map(t_var *, char *);
int		check_mouvement(int key, t_map **map);
int	put_rock(t_map **map, int key);
int	slash(t_map **map);
#endif
