S = src/
O = obj/
L = libft/

SOURCES = $Sso_long.c $Smove.c $Sread_map.c $Screate_map.c $Smonster_move.c $Schecker.c $Schecker_1.c

OBJS = $(SOURCES:$S%=$O%.o)

LIB = libft/libft.a
CC = gcc
RM = rm -f
RMDIR = rmdir
CFLAGS = -Wall -Wextra -Werror

NAME = so_long

all: $(NAME)


$O:
	@mkdir $@

$(OBJS): | $O


$(OBJS): $O%.o: $S%
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@make -C $(L) --silent
	@$(CC) $(CFLAGS) $(LIB) -lmlx -framework OpenGL -framework AppKit $^ -o $@
	@echo "\033[0;32m Compilation complétée"

clean: 
	@$(RM) $(OBJS)
	@$(RMDIR) $O
	@echo "\033[0;31m Fichiers .o supprimés"

fclean:	clean

	@$(RM) $(NAME)
	@echo "\033[0;31m Executable supprimé"


re:	fclean $(NAME)
