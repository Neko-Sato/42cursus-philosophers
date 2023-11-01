# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/28 21:24:52 by hshimizu          #+#    #+#              #
#    Updated: 2023/10/31 21:56:06 by hshimizu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= philo

ROOT_DIR		= .
INCS_DIR		= $(ROOT_DIR)/incs
OBJS_DIR		= $(ROOT_DIR)/objs

MAIN			= $(ROOT_DIR)/main.c

SRCS			= \
	$(addprefix $(ROOT_DIR)/srcs/, \
		philo_0.c \
		philo_1.c \
		philo_2.c \
		philo_3.c \
		philo_4.c \
		table_0.c \
		table_1.c \
		table_2.c \
	) \
	$(addprefix $(ROOT_DIR)/utils/, \
		thread.c \
		time.c \
	)

OBJS			= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

CC				= gcc-10
CFLAGS			= -Wall -Wextra -Werror
CFLAGS			+= -g
IDFLAGS			+= -I$(INCS_DIR)
LIBS			= -pthread

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(MAIN) $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(IDFLAGS) $^ -o $@ $(LIBS)

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) -c $(CFLAGS) $(IDFLAGS) $< -o $@

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	@make -C $(FT) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: test
test: test.c $(OBJS)
	$(CC) $(LDFLAGS) -g -fsanitize=thread $(IDFLAGS) $^ -o $@ $(LIBS)

.PHONY: norm
norm: $(MAIN) $(SRCS) $(INCS_DIR)
	@norminette $^
