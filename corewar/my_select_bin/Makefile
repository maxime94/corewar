SRCS	= main.c \
	  attr.c \
	  cmd.c \
	  calc_display.c \
	  match.c \
	  display.c \
	  match_opt.c \
	  occur_opt.c \
	  str.c \
	  nb.c

OBJS	= $(SRCS:.c=.o)

CC	= cc

RM	= rm -f

NAME	= ../my_select

LIBS	= -ltermcap

CFLAGS	=

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) $(LIBS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all clean
