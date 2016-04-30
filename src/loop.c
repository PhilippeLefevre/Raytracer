/*
** loop.c for raytracer1 in /home/sousa_v/rendu/lapin/gfx_raytracer1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Tue Feb  9 01:49:53 2016 victor sousa
** Last update Sat Apr 30 15:29:04 2016 Victor Sousa
*/

#include "main.h"

t_bunny_response        mainloop(void *p)
{
  t_bunny_position      pos;
  t_prog                *prog;

  prog = p;
  pos.x = 0;
  pos.y = 0;
  bunny_blit(&prog->win->buffer, &prog->pix->clipable, &pos);
  bunny_display(prog->win);
  return (GO_ON);
}
