NAME = minitalk
CLIENT = client
SERVER = server

CC = gcc
FLAGS = -Wall -Wextra -Werror

INCLUDES = -I libft -I .

LIBS = -L libft -lft
LIBFT = libft
LIBFT_REPO = https://github.com/adesgran/libft_extended.git

C_CLIENT = client.c
C_SERVER = server.c
C_FILES = $(filter-out ${C_CLIENT} ${C_SERVER},$(wildcard *.c)) 


O_CLIENT = $(C_CLIENT:.c=.o)
O_SERVER = $(C_SERVER:.c=.o)
O_FILES = $(C_FILES:.c=.o)

.c.o:
	${CC} ${FLAGS} ${INCLUDES} -c $< -o ${<:.c=.o}

all: ${LIBFT} ${NAME}

${LIBFT}:
	if [ ! -d "./libft" ]; then git clone ${LIBFT_REPO} ${LIBFT}; fi
	make -C ${LIBFT}

${CLIENT}: ${O_CLIENT}
	${CC} ${O_CLIENT} ${O_FILES} ${LIBS} -o ${CLIENT}

${SERVER}: ${O_SERVER}
	${CC} ${O_SERVER} ${O_FILES} ${LIBS} -o ${SERVER}

${NAME}: ${O_FILES} ${CLIENT} ${SERVER}

clean:
	rm -r ${CLIENT} ${SERVER}
	make clean -C ${LIBFT}

fclean: clean
	make fclean -C ${LIBFT}

re: clean all
