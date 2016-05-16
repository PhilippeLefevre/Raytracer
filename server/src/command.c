/*
** command.c for server in /Users/leandr_g/Documents/Shared folder/testServer/server_src/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sat May  7 05:54:51 2016 Gaëtan Léandre
** Last update Mon May 16 10:35:23 2016 Philippe Lefevre
*/

#include		"server.h"

int			is_valid_file(char *args, t_connected *co)
{
  int			size;

  size = my_strlen(args);
  if (args[size - 1] == 'l' &&
      args[size - 2] == 'm' &&
      args[size - 3] == 'x' &&
      args[size - 4] == '.')
    co->form = 1;
  else if (args[size - 1] == 'j' &&
	   args[size - 2] == 'b' &&
	   args[size - 3] == 'o' &&
      	   args[size - 4] == '.')
    co->form = 2;
  else
    {
      co->form = 0;
      return (0);
    }
  return (1);
}

int			cmd_launch(SOCKET sock, char **tab, t_connected *co)
{
  char			*str;

  if (tab == NULL)
    return (0);
  if (co->master && sock == co->master->sock && my_strcmp(tab[0], "launch")
      && tab[1] && tab[2] == NULL)
    {
      if (co->size <= 0)
	{
	  write_client(sock, "Pas de clients connectés pour effectuer launch");
	  return (1);
	}
      else if (is_valid_file(tab[1], co) == 0)
	return (0);
      str = my_sprintf("/launch s %s", tab[1]);
      write_client(sock, str);
      if (co->end != NULL)
	free(co->end);
      co->end = NULL;
      free(str);
      co->status = 1;
      return (1);
    }
  return (0);
}

int			cmd_sudo(SOCKET sock, char **tab, t_connected *co)
{
  t_client		*tmp;

  if (tab == NULL)
    return (0);
  if (my_strcmp(tab[0], "sudo") && tab[1] && my_strcmp(tab[1], PASSWD)
      && tab[2] == NULL
      && ((co->master && co->master->sock != sock) || !co->master))
    {
      if (co->master)
	{
	  co->master->prev = NULL;
	  if (co->clients)
	    co->clients->prev = co->master;
	  co->master->next = co->clients;
	  co->clients = co->master;
	}
      else
	co->size--;
      tmp = co->clients;
      while (tmp != NULL)
	{
	  if (tmp->sock == sock)
	    {
	      if (tmp->prev != NULL)
		tmp->prev->next = tmp->next;
	      else
		co->clients = tmp->next;
	      if (tmp->next != NULL)
		tmp->next->prev = tmp->prev;
	      co->master = tmp;
	      my_printf(1, "Le pouvoir est renversé, un nouveau joueur \
s'installe à la tête du serveur!\n");
	      write_all_client(co, "Le pouvoir est renversé, un nouveau \
joueur s'installe à la tête du serveur!", -1);
	      return (1);
	    }
	  tmp = tmp->next;
	}
      return (0);
    }
  return (0);
}

int			cmd_download(SOCKET sock, char **tab, t_connected *co)
{
  char			*str;
  char			buffer[BUF_SIZE];

  if (tab == NULL)
    return (0);
  if (co->master && sock == co->master->sock && my_strcmp(tab[0], "download")
      && tab[1] == NULL && co->end != NULL)
    {
      str = my_sprintf("/download %d %d", co->width, co->height);
      write_client(sock, str);
      if (read_client(sock, buffer) > 0 && my_strcmp(buffer, "k") == 1)
	send(sock, co->end, sizeof(unsigned int) * co->height * co->width, 0);
      free(str);
      return (1);
    }
  return (0);
}

int			cmd_exit(char **tab, t_connected *co)
{
  if (tab == NULL)
    return (0);
  if (my_strcmp(tab[0], "exit") && tab[1] == NULL)
    {
      write_all_client(co, "/halt", -1);
      co->status = -1;
      return (1);
    }
  return (0);
}

void			launch_command_server(char **tab, t_connected *co)
{

  if (!tab || !cmd_exit(tab, co))
    my_printf(1, "Commande inconnue\n");
  free_tab(tab);
}

void			launch_command_client(SOCKET sock, char **tab,
					      t_connected *co)
{
  if ((co->master == NULL || co->master->sock != sock
       || cmd_exit(tab, co) == 0) && cmd_sudo(sock, tab, co) == 0
      && cmd_launch(sock, tab, co) == 0 && cmd_download(sock, tab, co) == 0)
    write_client(sock, "Commande inconnue");
  free_tab(tab);
}

void			exec_command(t_connected *co)
{
  char			*str;
  char			**tab;

  if ((str = get_next_line(0)) != NULL)
    {
      tab = str_to_wordtab(str, " ");
      launch_command_server(tab, co);
      free(str);
    }
}
