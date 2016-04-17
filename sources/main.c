/*
** main.c for main.c in /home/roig_a/GAME
**
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
**
** Started on  Fri Jan 29 19:33:01 2016 Antoine Roig
** Last update Sun Apr 17 14:58:26 2016 Antoine Roig
*/

#include "game.h"

void    *xmalloc(int size)
{
  void  *element;

  element = malloc(size);
  if (!element)
    exit(EXIT_FAILURE);
  return (element);
}

char    **make_tab(t_var *var, char *buffer)
{
  char  **tab;
  int   i;
  int   x;
  int   y;

  y = 0;
  i = 0;
  tab = xmalloc(sizeof(char *) * var->y + 8);
  while (buffer[i])
    {
      tab[y] = xmalloc(sizeof(char) * var->x + 1);
      x = 0;
      while (buffer[i] != '\n')
        tab[y][x++] = buffer[i++];
      tab[y][x] = '\0';
      i++;
      y++;
    }
  tab[y] = '\0';
  return (tab);
}

void	check_map(t_map map, SDL_Rect position, SDL_Surface *ecran)
{
  SDL_Surface	*hearth;
  SDL_Surface	*enemy;
  SDL_Surface	*player;
  SDL_Surface	*mountain;
  SDL_Surface	*templeuh;
  SDL_Surface	*grass;
  SDL_Surface	*objet;
  int		val;

  val = item / 3;
  if ((map.player == 1) || (map.player == 1 && map.item == 1))
    {
      if (orientation == 1)
	player = SDL_LoadBMP("./images/PlayerUp.bmp");
      else if (orientation == 2)
	player = SDL_LoadBMP("./images/PlayerDown.bmp");
      else if (orientation == 3)
	player = SDL_LoadBMP("./images/PlayerLeft.bmp");
      else if (orientation == 4)
	player = SDL_LoadBMP("./images/PlayerRight.bmp");
      SDL_BlitSurface(player, NULL, ecran, &position);
      SDL_FreeSurface(player);
      return;
    }
  else if (map.obstacle == 1)
    {
      if (c == 0)
	{
	  if (rand()%4 == 1)
	    mountain = SDL_LoadBMP("./images/Rock1.bmp");
	  else if (rand()%4 == 2)
	    mountain = SDL_LoadBMP("./images/Rock4.bmp");
	  else if (rand()%4 == 3)
	    mountain = SDL_LoadBMP("./images/Rock3.bmp");
	  else
	    mountain = SDL_LoadBMP("./images/Rock1.bmp");
	  SDL_BlitSurface(mountain, NULL, ecran, &position);
	  SDL_FreeSurface(mountain);
	}
      return;
    }
  else if (map.player2 == 1)
    {
      if (h_temple + 1 == item)
	templeuh = SDL_LoadBMP("./images/Temple4.bmp");
      else if (h_temple >= val * 2)
	templeuh = SDL_LoadBMP("./images/Temple3.bmp");
      else if (h_temple >= val)
	templeuh = SDL_LoadBMP("./images/Temple2.bmp");
      else
	templeuh = SDL_LoadBMP("./images/Temple1.bmp");
      SDL_BlitSurface(templeuh, NULL, ecran, &position);
      SDL_FreeSurface(templeuh);
      return;
    }
  else if (map.enemy2 == 1)
    {
      if (map.boul == 1)
	enemy = SDL_LoadBMP("./images/Enemy2Up.bmp");
      else
	enemy = SDL_LoadBMP("./images/Enemy2Down.bmp");
      SDL_BlitSurface(enemy, NULL, ecran, &position);
      SDL_FreeSurface(enemy);
      return;
    }
  else if (map.ground == 1)
    {
      grass = SDL_LoadBMP("./images/Grass2.bmp");
      SDL_BlitSurface(grass, NULL, ecran, &position);
      SDL_FreeSurface(grass);
      return;
    }
  else if (map.enemy == 1)
    {
      if (map.boul == 1)
	enemy = SDL_LoadBMP("./images/Enemy1Right.bmp");
      else
	enemy = SDL_LoadBMP("./images/Enemy1Left.bmp");

      SDL_BlitSurface(enemy, NULL, ecran, &position);
      SDL_FreeSurface(enemy);
      return;
    }
  else if (map.hp == 1)
    {
      hearth = SDL_LoadBMP("./images/HPUP.bmp");
      SDL_BlitSurface(hearth, NULL, ecran, &position);
      SDL_FreeSurface(hearth);
      return;
    }
  else if (map.item == 1)
    {
      objet = SDL_LoadBMP("./images/Item2.bmp");
      SDL_BlitSurface(objet, NULL, ecran, &position);
      SDL_FreeSurface(objet);
      return;
    }
}

void    aff_map(t_map **map, t_var *var, SDL_Surface *ecran)
{
  int   y;
  int   x;
  SDL_Rect	position;

  y = 0;
  srand(time(NULL));
  while (map[y])
    {
      position.y = y * 30;
      x = 0;
      while (x != var->x)
	{
	  position.x = x * 30;
	  check_map(map[y][x], position, ecran);
	  x++;
	}
      y++;
    }
  c = 1;
}

void	move_horizon_enemy(t_map **map, int y, int x)
{
  if (map[y][x].enemy == 1 && map[y][x].boul == 1)
    {
      if (map[y][x + 1].ground == 1)
  	{
  	  map[y][x].ground = 1;
  	  map[y][x].enemy = 0;
  	  map[y][x].boul = 0;
  	  map[y][x + 1].ground = 0;
  	  map[y][x + 1].enemy = 1;
  	  map[y][x + 1].boul = 1;
  	}
      else if (map[y][x + 1].obstacle == 1 || (map[y][x + 1].item == 1  && map[y][x + 1].player == 0) || map[y][x + 1].temple == 1 || map[y][x + 1].hp == 1)
  	{
  	  map[y][x].ground = 1;
  	  map[y][x].enemy = 0;
  	  map[y][x].boul = 0;
  	  map[y][x - 1].ground = 0;
  	  map[y][x - 1].enemy = 1;
  	  map[y][x - 1].boul = 0;
  	}
      else if (map[y][x + 1].enemy == 1 || map[y][x + 1].enemy2 == 1)
	{
  	  map[y][x].ground = 1;
  	  map[y][x].enemy = 0;
  	  map[y][x].boul = 0;
  	  map[y][x - 1].ground = 0;
  	  map[y][x - 1].enemy = 1;
  	  map[y][x - 1].boul = 0;
	}
      else if (map[y][x + 1].player == 1)
  	{
  	  if (map[y][x + 1].item == 1)
  	    {
  	      map[y][x + 1].item = 0;
  	      map[y_item][x_item].item = 1;
  	      map[y_item][x_item].ground = 0;
  	    }
  	  map[y][x + 1].player = 0;
  	  map[y][x + 1].ground = 1;
  	  y_actual = y_beg;
  	  x_actual = x_beg;
  	  map[y_actual][x_actual].player = 1;
  	  map[y_actual][x_actual].ground = 0;
  	  hp--;
  	}
    }
  else if (map[y][x].enemy == 1 && map[y][x].boul == 0)
    {
      if (map[y][x - 1].ground == 1)
  	{
  	  map[y][x].ground = 1;
  	  map[y][x].enemy = 0;
  	  map[y][x].boul = 0;
  	  map[y][x - 1].ground = 0;
  	  map[y][x - 1].enemy = 1;
  	  map[y][x - 1].boul = 0;
  	}
      else if (map[y][x - 1].obstacle == 1 || (map[y][x - 1].item == 1  && map[y][x - 1].player == 0) || map[y][x - 1].temple == 1 || map[y][x - 1].hp == 1)
	{
  	  map[y][x].ground = 1;
  	  map[y][x].enemy = 0;
  	  map[y][x].boul = 0;
  	  map[y][x + 1].ground = 0;
  	  map[y][x + 1].enemy = 1;
  	  map[y][x + 1].boul = 1;
  	}
      else if (map[y][x - 1].enemy == 1 || map[y][x - 1].enemy2 == 1)
	{
  	  map[y][x].ground = 1;
  	  map[y][x].enemy = 0;
  	  map[y][x].boul = 0;
  	  map[y][x + 1].ground = 0;
  	  map[y][x + 1].enemy = 1;
  	  map[y][x + 1].boul = 1;
	}
      else if (map[y][x - 1].player == 1)
  	{
  	  if (map[y][x - 1].item == 1)
  	    {
  	      map[y][x - 1].item = 0;
  	      map[y_item][x_item].item = 1;
  	      map[y_item][x_item].ground = 0;
  	    }
  	  map[y][x - 1].player = 0;
  	  map[y][x - 1].ground = 1;
  	  y_actual = y_beg;
  	  x_actual = x_beg;
  	  map[y_actual][x_actual].player = 1;
  	  map[y_actual][x_actual].ground = 0;
  	  hp--;
  	}
    }
}

void	move_vertical_enemy(t_map **map, int y, int x)
{
  if (map[y][x].enemy2 == 1 && map[y][x].boul == 1)
    {
      if (map[y + 1][x].ground == 1)
  	{
  	  map[y][x].ground = 1;
  	  map[y][x].enemy2 = 0;
  	  map[y][x].boul = 0;
  	  map[y + 1][x].ground = 0;
  	  map[y + 1][x].enemy2 = 1;
  	  map[y + 1][x].boul = 1;
  	}
      else if (map[y + 1][x].obstacle == 1 || (map[y + 1][x].item == 1  && map[y + 1][x].player == 0) || map[y + 1][x].temple == 1 || map[y + 1][x].enemy == 1 || map[y + 1][x].enemy2 == 1 || map[y + 1][x].hp == 1)
	{
  	  map[y][x].ground = 1;
  	  map[y][x].enemy2 = 0;
  	  map[y][x].boul = 0;
  	  map[y - 1][x].ground = 0;
  	  map[y - 1][x].enemy2 = 1;
  	  map[y - 1][x].boul = 0;
  	}
      else if (map[y + 1][x].player == 1)
  	{
  	  if (map[y + 1][x].item == 1)
  	    {
  	      map[y + 1][x].item = 0;
  	      map[y_item][x_item].item = 1;
  	      map[y_item][x_item].ground = 0;
  	    }
  	  map[y + 1][x].player = 0;
  	  map[y + 1][x].ground = 1;
  	  y_actual = y_beg;
  	  x_actual = x_beg;
  	  map[y_actual][x_actual].player = 1;
  	  map[y_actual][x_actual].ground = 0;
  	  hp--;
  	}
    }
  else if (map[y][x].enemy2 == 1 && map[y][x].boul == 0)
    {
      if (map[y - 1][x].ground == 1)
  	{
  	  map[y][x].ground = 1;
  	  map[y][x].enemy2 = 0;
  	  map[y][x].boul = 0;
  	  map[y - 1][x].ground = 0;
  	  map[y - 1][x].enemy2 = 1;
  	  map[y - 1][x].boul = 0;
  	}
      else if (map[y - 1][x].obstacle == 1 || (map[y - 1][x].item == 1  && map[y - 1][x].player == 0) || map[y - 1][x].temple == 1 || map[y - 1][x].enemy == 1 || map[y - 1][x].enemy2 == 1 || map[y - 1][x].hp == 1)
	{
  	  map[y][x].ground = 1;
  	  map[y][x].enemy2 = 0;
  	  map[y][x].boul = 0;
  	  map[y + 1][x].ground = 1;
  	  map[y + 1][x].enemy2 = 1;
  	  map[y + 1][x].boul = 1;
  	}
      else if (map[y - 1][x].player == 1)
  	{
  	  if (map[y - 1][x].item == 1)
  	    {
  	      map[y - 1][x].item = 0;
  	      map[y_item][x_item].item = 1;
  	      map[y_item][x_item].ground = 0;
  	    }
  	  map[y - 1][x].player = 0;
  	  map[y - 1][x].ground = 1;
  	  y_actual = y_beg;
  	  x_actual = x_beg;
  	  map[y_actual][x_actual].player = 1;
  	  map[y_actual][x_actual].ground = 0;
  	  hp--;
  	}
    }
}

void	search_enemy_h(t_map **map)
{
  int	y,x;

  y = 0;
  while (y < y_map)
    {
      x = 0;
      while (x < x_map)
	{
	  if (map[y][x].enemy == 1)
	    {
	      move_horizon_enemy(map, y, x);
	      x = x +2;
	    }
	  else
	    x++;
	}
      y++;
    }
}

void	search_enemy_v(t_map **map)
{
  int	y,x;

  x = 0;
  while (x < x_map)
    {
      y = 0;
      while (y < y_map)
	{
	  if (map[y][x].enemy2 == 1)
	    {
	      move_vertical_enemy(map, y, x);
	      y = y + 2;
	    }
	  else
	    y++;
	}
      x++;
    }
}

Uint32	enemy_h(Uint32 intervalle, void *arg)
{
  t_map	**map;

  map = (t_map **)arg;
  search_enemy_h(map);
  return (intervalle);
}

Uint32	enemy_v(Uint32 intervalle, void *arg)
{
  t_map	**map;

  map = (t_map **)arg;
  search_enemy_v(map);
  return (intervalle);
}

void	my_freemap(t_map **map)
{
  int	y;

  y = 0;
  while (y != y_map)
    {
      free(map[y]);
      y++;
    }
  free(map);
}
int     main(int ac, char **av)
{
  int   fd;
  struct stat buf;
  char  *buffer;
  int   size_read;
  t_var *var;
  t_map	**map;
  int	key;
  int	moov;
  SDL_Surface	*ecran = NULL;
  SDL_Event event;
  SDL_TimerID timer;
  SDL_TimerID timer2;
  SDL_Surface	*HPLeft = NULL;
  SDL_Rect	position;

  shield = 0;
  position.y = 0;
  position.x = 0;
  if (ac != 3)
    {
      puts("Usage : ./fround map speed. Exemple : ./fround mapx 75");
      return (0);
    }
  orientation = 3;
  SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
  ecran = SDL_SetVideoMode(1920, 1080, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  SDL_WM_SetCaption("Fround", NULL);
  hp = 3;
  h_temple = 0;
  ac = ac;
  var = xmalloc(sizeof(*var));
  if (stat(av[1], &buf) == -1)
    return (0);
  size_read = buf.st_size;
  if (size_read == 0)
    return (0);
  fd = open(av[1], O_RDONLY);
  buffer = xmalloc(sizeof(char) * (size_read + 1));
  read(fd, buffer, size_read);
  buffer[size_read] = '\0';
  var = get_x_y(buffer, var);
  map = create_map(var, buffer);
  key = 1;
  timer = SDL_AddTimer(atoi(av[2]), enemy_h, map);
  timer2 = SDL_AddTimer(atoi(av[2]), enemy_v, map);
  while (key != 27 && h_temple != item && hp > 0)
    {
      SDL_PollEvent(&event);
      if (hp >= 3)
	{
	  HPLeft = SDL_LoadBMP("./images/HPLeft.bmp");
	  SDL_BlitSurface(HPLeft, NULL, ecran, &position);
	}
      else if (hp == 2)
	{
	  HPLeft = SDL_LoadBMP("./images/HPLeft2.bmp");
	  SDL_BlitSurface(HPLeft, NULL, ecran, &position);
	}
      else if (hp == 1)
	{
	  HPLeft = SDL_LoadBMP("./images/HPLeft1.bmp");
	  SDL_BlitSurface(HPLeft, NULL, ecran, &position);
	}
      if (event.type == SDL_KEYDOWN)
      	{
	  if (event.key.keysym.sym == SDLK_m)
	    {
	      key = 32;
	      put_rock(map, shield);
	    }
	  if (event.key.keysym.sym == SDLK_l)
	    {
	      if (orientation == 1 && map[y_actual - 1][x_actual].enemy == 1)
		{
		  map[y_actual - 1][x_actual].enemy = 0;
		  map[y_actual - 1][x_actual].ground = 0;
		  map[y_actual - 1][x_actual].hp = 1;
		}
	      else if (orientation == 1 && map[y_actual - 1][x_actual].enemy2 == 1)
		{
		  map[y_actual - 1][x_actual].enemy2 = 0;
		  map[y_actual - 1][x_actual].ground = 0;
		  map[y_actual - 1][x_actual].hp = 1;
		}
	      else if (orientation == 2 &&  map[y_actual + 1][x_actual].enemy == 1)
		{
		  map[y_actual + 1][x_actual].enemy = 0;
		  map[y_actual + 1][x_actual].ground = 0;
		  map[y_actual + 1][x_actual].hp = 1;
		}
	      else if (orientation == 2 && map[y_actual + 1][x_actual].enemy2 == 1)
		{
		  map[y_actual + 1][x_actual].enemy2 = 0;
		  map[y_actual + 1][x_actual].ground = 0;
		  map[y_actual + 1][x_actual].hp = 1;
		}
	      else if (orientation == 3 && map[y_actual][x_actual - 1].enemy == 1)
		{
		  map[y_actual][x_actual - 1].enemy = 0;
		  map[y_actual][x_actual - 1].ground = 0;
		  map[y_actual][x_actual - 1].hp = 1;
		}
	      else if (orientation == 3 && map[y_actual][x_actual - 1].enemy2 == 1)
		{
		  map[y_actual][x_actual - 1].enemy2 = 0;
		  map[y_actual][x_actual - 1].ground = 0;
		  map[y_actual][x_actual - 1].hp = 1;
		}
	      else if (orientation == 4 && map[y_actual][x_actual + 1].enemy == 1)
		{
		  map[y_actual][x_actual + 1].enemy = 0;
		  map[y_actual][x_actual + 1].ground = 0;
		  map[y_actual][x_actual + 1].hp = 1;
		}
	      else if (orientation == 4 && map[y_actual][x_actual + 1].enemy2 == 1)
		{
		  map[y_actual][x_actual + 1].enemy2 = 0;
		  map[y_actual][x_actual + 1].ground = 0;
		  map[y_actual][x_actual + 1].hp = 1;
		}
	    }
	  if(event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_DOWN ||event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_RIGHT || event.key.keysym.sym == SDLK_ESCAPE ||
	     event.key.keysym.sym == SDLK_z || event.key.keysym.sym == SDLK_s || event.key.keysym.sym == SDLK_q || event.key.keysym.sym == SDLK_d || event.key.keysym.sym == SDLK_a || event.key.keysym.sym == SDLK_e)
	    {
	      if (event.key.keysym.sym == SDLK_ESCAPE)
		{
		  key = 27;
		}
	      else if (event.key.keysym.sym == SDLK_UP)
		{
		  key = 259;
		  orientation = 1;
		}
	      else if (event.key.keysym.sym == SDLK_DOWN)
		{
		  key = 258;
		  orientation = 2;
		}
	      else if (event.key.keysym.sym == SDLK_LEFT)
		{
		  key = 260;
		  orientation = 3;
		}
	      else if (event.key.keysym.sym == SDLK_RIGHT)
		{
		  key = 261;
		  orientation = 4;
		}
	      else if (event.key.keysym.sym == SDLK_z)
		{
		  key = 1;
		}
	      else if (event.key.keysym.sym == SDLK_s)
		{
		  key = 2;
		}
	      else if (event.key.keysym.sym == SDLK_q)
		{
		  key = 3;
		}
	      else if (event.key.keysym.sym == SDLK_d)
		{
		  key = 4;
		}
	      else if (event.key.keysym.sym == SDLK_a)
		{
		  key = 8;
		}
	      else if (event.key.keysym.sym == SDLK_e)
		{
		  key = 9;
		}
	      moov = check_mouvement(key, map);
	      if (moov == 2)
		{
		  if (map[y_actual][x_actual].item == 1)
		    {
		      map[y_actual][x_actual].item = 0;
		      map[y_item][x_item].item = 1;
		      map[y_item][x_item].ground = 0;
		    }
		  map[y_actual][x_actual].player = 0;
		  map[y_actual][x_actual].ground = 1;
		  y_actual = y_beg;
		  x_actual = x_beg;
		  map[y_actual][x_actual].player = 1;
		  map[y_actual][x_actual].ground = 0;
		  hp--;
		}
	    }
	}
      moov = 0;
      aff_map(map, var, ecran);
      SDL_UpdateRect(ecran, 0, 0, 0, 0);
      event.type = 0;
      SDL_FreeSurface(HPLeft);
    }
  SDL_FreeSurface(ecran);
  SDL_RemoveTimer(timer);
  SDL_RemoveTimer(timer2);
  SDL_VideoQuit();
  SDL_Quit();
  my_freemap(map);
  free(var);
  free(buffer);
  if (hp == 0)
    printf("YOU LOOSE ! TRY AGAIN !\n");
  if (h_temple == item)
    printf("YOU WIN !\n");
  return (0);
}
