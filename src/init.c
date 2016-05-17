/*
** main.c for raytracer1 in /home/sousa_v/rendu/lapin/gfx_raytracer1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Tue Feb  9 01:50:10 2016 victor sousa
** Last update Mon May 16 18:45:34 2016 Philippe Lefevre
*/

#include		"main.h"

int			init_opt(char *arg, t_prog *prog)
{
  if (!(my_strcmp("--verbose", arg)))
    {
      prog->opt->verbose = 1;
      return (1);
    }
  else if (!(my_strcmp("--quiet", arg)))
    {
      prog->opt->verbose = 0;
      return (1);
    }
  else if (!(my_strncmp("--thread=", arg, 9)))
    {
      prog->opt->thread_nb = my_getnbr(arg + 9);
      return (1);
    }
  return (0);
}

int			do_cluster(int ac, char **av, t_prog *prog)
{
  if (ac == 2)
    {
      if (!(my_strcmp("--cluster", av[1])))
	{
	  prog->opt->cluster = 1;
	  return (1);
	}
    }
  return (0);
}

t_opt			*init_default_opt(t_prog *prog)
{
  if ((prog->opt = malloc(sizeof(t_opt))) == NULL)
    return (NULL);
  prog->opt->thread_nb = 1;
  prog->opt->cluster = 0;
  prog->opt->rendu_display = 0;
  prog->opt->rendu_vertical = 0;
  prog->opt->verbose = 1;
  return (prog->opt);
}

int			verif_arg(int ac, char **av, t_prog *prog)
{
  int			i;
  int			ret;

  if ((prog->opt = init_default_opt(prog)) == NULL)
    return (-1);
  if (do_cluster(ac, av, prog))
    return (1);
  if (disp_credit(av) || editor(ac, av))
    return (-1);
  i = 0;
  while (av[++i])
    if ((ret = verif_load(prog, av[i])))
      {
	if (ret == -1)
	  return (ret);
      }
    else if (init_rendu(av[i], prog) || init_opt(av[i], prog))
      continue;
    else
      return (disp_help(av[0]));
  if (prog->opt->thread_nb < 1)
    return (my_printf(2, "Number of thread must be positive\n") - 1);
  return (0);
}