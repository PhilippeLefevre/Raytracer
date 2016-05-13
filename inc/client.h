/*
** client.h for raytracer in /Users/leandr_g/Documents/Shared folder/Raytracer/inc/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Tue May 10 22:56:16 2016 Gaëtan Léandre
** Last update Fri May 13 05:56:27 2016 Gaëtan Léandre
*/

#ifndef			_CLIENT_H_
# define		_CLIENT_H_

# define		PORT		777
# define		BUF_SIZE	1024

# include		<sys/types.h>
# include		<sys/socket.h>
# include		<netinet/in.h>
# include		<arpa/inet.h>
# include		<unistd.h>
# include		<stdio.h>
# include		"get_next_line.h"
# include 		"utils.h"

typedef 		int SOCKET;
typedef struct 		sockaddr_in SOCKADDR_IN;
typedef struct 		sockaddr SOCKADDR;
typedef struct 		in_addr IN_ADDR;

typedef struct		s_connected
{
  int			max;
  int			status;
}			t_connected;

typedef union		s_size
{
  int			i;
  unsigned char		csize[4];
}			t_size;

void			write_server(SOCKET sock, char *buffer);
int			read_server(SOCKET sock, char *buffer);
int			client(t_prog *prog);
int			send_file(SOCKET sock, char *file, int siz);
char			*reciv_file(SOCKET sock);
char			**is_command(char *str);
char			*exec_command(SOCKET sock, char **tab, int *status);
void			client_raytrace(char *str, int *status, SOCKET sock);

#endif			/* _CLIENT_H_ */