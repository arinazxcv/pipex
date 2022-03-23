IRED		= \033[1;35m

NAME		= pipex
HEADER		= ./incl/pipex.h
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
OBJ_PATH	= ./objs
SRC_PATH	= ./src

SRCS = $(addprefix $(SRC_PATH)/,$(SOURCES))
OBJS = $(addprefix $(OBJ_PATH)/,$(SOURCES:.c=.o))
SOURCES	=	utils.c \
			pipex.c \
			utils2.c \
			ft_split.c \
			ft_path.c \
			ft_multipipe.c \
			close.c \

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER) Makefile
			@mkdir -p objs
			@echo "Compiling:$(END) $<"
			@${CC} ${CFLAGS} -c $< -o $@

all:  ${NAME} 

${NAME}:	666 ${OBJS}
			@${CC}  ${OBJS} -o ${NAME}
			@echo "Successful compilation"

clean:
		@rm -rf ${OBJS}
		@echo "Object files cleaned"

fclean:	clean
		@rm -f ${NAME}
		@echo "Executable files cleaned"

re:	fclean
	@${MAKE} all
	@echo "Cleaned and rebuilt everything"

666:
	@echo "$(IRED)⠄⠄⠄⠄⠄⠄⠄⠄⣀⣤⡴⠶⠟⠛⠛⠛⠛⠻⠶⢦⣤⣀⠄⠄⠄⠄⠄⠄⠄"
	@echo "$(IRED)⠄⠄⠄⠄⠄⣠⣴⡟⠋⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠈⠙⢻⣦⣄⠄⠄⠄⠄⠄"
	@echo "$(IRED)⠄⠄⠄⣠⡾⠋⠈⣿⣶⣄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣠⣶⣿⠁⠙⢷⣄⠄⠄⠄"
	@echo "$(IRED)⠄⠄⣴⠏⠄⠄⠄⠸⣇⠉⠻⣦⣀⠄⠄⠄⠄⣀⣴⠟⠉⣸⠇⠄⠄⠄⠹⣦⠄⠄"
	@echo "$(IRED)⠄⣼⠏⠄⠄⠄⠄⠄⢻⡆⠄⠄⠙⠷⣦⣴⠾⠋⠄⠄⢰⡟⠄⠄⠄⠄⠄⠹⣧⠄"
	@echo "$(IRED)⢰⡏⠄⠄⠄⠄⠄⠄⠈⣷⠄⢀⣤⡾⠋⠙⢷⣤⡀⠄⣾⠁⠄⠄⠄⠄⠄⠄⢹⡆"
	@echo "$(IRED)⣿⠁⠄⠄⠄⠄⠄⠄⠄⣸⣷⠛⠁⠄⠄⠄⠄⠈⠛⣾⣇⠄⠄⠄⠄⠄⠄⠄⠄⣿"
	@echo "$(IRED)⣿⠄⠄⠄⠄⠄⣠⣴⠟⠉⢻⡄⠄⠄⠄⠄⠄⠄⣾⡟⠉⠻⣦⣄⠄⠄⠄⠄⠄⣿"
	@echo "$(IRED)⣿⡀⠄⢀⣴⠞⠋⠄⠄⠄⠈⣷⠄⠄⠄⠄⠄⠄⣾⠁⠄⠄⠄⠙⠳⣦⡀⠄⠄⣿"
	@echo "$(IRED)⠸⣧⠾⠿⠷⠶⠶⠶⠶⠶⠶⢾⣷⠶⠶⠶⠶⣾⡷⠶⠶⠶⠶⠶⠶⠾⠿⠷⣼⠇"
	@echo "$(IRED)⠄⢻⣆⠄⠄⠄⠄⠄⠄⠄⠄⠄⢿⡄⠄⠄⢠⡿⠄⠄⠄⠄⠄⠄⠄⠄⠄⣰⡟⠄"
	@echo "$(IRED)⠄⠄⠻⣆⠄⠄⠄⠄⠄⠄⠄⠄⠘⣷⠄⠄⣾⠃⠄⠄⠄⠄⠄⠄⠄⠄⣰⠟⠄⠄"
	@echo "$(IRED)⠄⠄⠄⠙⢷⣄⠄⠄⠄⠄⠄⠄⠄⢹⣇⣸⡏⠄⠄⠄⠄⠄⠄⠄⣠⡾⠋⠄⠄⠄"
	@echo "$(IRED)⠄⠄⠄⠄⠄⠙⠳⣦⣄⡀⠄⠄⠄⠄⢿⡿⠄⠄⠄⠄⢀⣠⣴⠞⠋⠄⠄⠄⠄⠄"
	@echo "$(IRED)⠄⠄⠄⠄⠄⠄⠄⠄⠉⠛⠳⠶⣦⣤⣼⣧⣤⣴⠶⠞⠛⠉⠄⠄⠄⠄⠄⠄⠄⠄"

.PHONY:	all clean fclean re 666