/*
** parce.c for corewar in /home/lavand_m//projet/actu/corewar/asm
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Wed Jan 16 13:02:05 2013 maxime lavandier
** Last update Wed Jan 16 13:52:28 2013 maxime lavandier
*/

#include "../misc/op.h"

int	recup_name(char *line, header_t *header)
{
  int	i_line;
  int	i_name;

  if (line == NULL || header == NULL)
    return (-1);
  i_name = 0;
  i_line = my_strlen(NAME_CMD_STRING);
  while (line[i_line] == ' ' || line[i_line] == '"')
    i_line++;
  while (line[i_line] != 0 && line[i_line] != '"' && i_name < PROG_NAME_LENGTH)
    {
      header->prog_name[i_name];
      i_line++;
      i_name++;
    }
  if (i_name == PROG_NAME_LENGTH || line[i_line] == 0)
    {
      my_putstr("Name parse error\n");
      exit(0);
    }
  header->prog_name[i_name] = 0;
}

void	recup_comment(char *line, header_t *header)
{
  int	i_line;
  int	i_comment;

  if (line == NULL || header == NULL)
    return (-1);
  i_comment = 0;
  i_line = my_strlen(COMMENT_CMD_STRING);
  while (line[i_line] == ' ' || line[i_line] == '"')
    i_line++;
  while (line[i_line] != 0 && line[i_line] != '"' && i_comment < COMMENT_LENGTH)
    {
      header->comment[i_comment];
      i_line++;
      i_comment++;
    }
  if (i_comment == COMMENT_CHAR || line[i_line] == 0)
    {
      my_putstr("Comment parse error\n");
      exit(0);
    }
  header->comment[i_comment] = 0;
}

int	next_the_header(char **file)
{
  int	i;

  i = 0;
  while (file[i] != 0 && file[i] != 0 &&
	 file[i][0] == COMMENT_CHAR || file[i + 1][0] == COMMENT_CHAR)
    {
      i++;
    }
}

int		parse(char **file)
{
  int		i;
  header_t	header;

  i = next_the_header(file);
  if (i = 0)
    return (-1);
  while (file[i])
    {
      if (my_strcmp(file[i], NAME_CMD_STRING))
	recup_name(file[i], &header);
      else if (my_strcmp(file[i], COMMENT_CMD_STRING))
	recup_comment(file[i], &header);
      else
	parse_cmd(file[i], &header);
    }
}
