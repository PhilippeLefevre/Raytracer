/*
** main.h for raytracer1 in /home/sousa_v/rendu/lapin/gfx_raytracer1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Tue Feb  9 01:45:54 2016 victor sousa
** Last update Mon May 16 09:37:19 2016 Philippe Lefevre
*/

#ifndef			MAIN_H_
# define		MAIN_H_

# include		<unistd.h>
# include               <math.h>
# include               <sys/types.h>
# include               <sys/stat.h>
# include               <fcntl.h>
# include		<pthread.h>

# include		"lapin.h"
# include		"image.h"
# include		"struct.h"
# include		"output.h"
# include		"raytrace.h"
# include		"hit.h"
# include		"loading.h"
# include		"utils.h"
# include		"editor.h"
# include		"get_next_line.h"
# include		"my_printf.h"
# include		"my_sprintf.h"
# include		"xml.h"
# include		"client.h"

# define		RT_MAX_RAM	(512)
# define		Deg_To_Rad(ang)	((ang) / 180.0 * M_PI)
# define		ABS(x)		((x)<0 ? -(x) : (x))
# define		NEG(x)		((x)<0 ? (x) : -(x))
# define		NTHREADS	4

t_bunny_response	mainloop(void *p);
int			disp_help(char *bin);
int			disp_credit(char **av);
int			verif_env(char **env);
int			verif_arg(int ac, char **av, t_prog *prog);
void			free_stuff(t_prog *prog);

#endif		      /*MAIN_H*/
