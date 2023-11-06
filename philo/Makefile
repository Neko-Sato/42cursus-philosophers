# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/28 21:24:52 by hshimizu          #+#    #+#              #
#    Updated: 2023/11/06 22:21:55 by hshimizu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= philo

ROOT_DIR		= .
INCS_DIR		= $(ROOT_DIR)/incs
OBJS_DIR		= $(ROOT_DIR)/objs

MAIN			= $(ROOT_DIR)/main.c

SRCS			= \
	$(addprefix $(ROOT_DIR)/srcs/, \
		dining_philo.c \
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
		utils.c \
		thread.c \
		time.c \
		ft_strlen.c \
		ft_atol.c \
		ft_isdigit.c \
		ft_isnumber.c \
		ft_isspace.c \
		ft_strchr.c \
	) 

OBJS			= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

CC				= gcc-10
CFLAGS			= -Wall -Wextra -Werror
# CFLAGS			+= -fsanitize=thread
# CFLAGS			+= -fsanitize=address
# CFLAGS			+= -g
IDFLAGS			+= -I$(INCS_DIR)
IDFLAGS			+= -I./../philo_visualizer 
LIBS			= -pthread ./../philo_visualizer/libphilovisual.so

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
	$(RM) $(NAME)

re: fclean all

.PHONY: test
test: test.c $(OBJS)	
	$(CC) $(LDFLAGS) -g $(IDFLAGS) $^ -o $@ $(LIBS)

.PHONY: norm
norm: $(MAIN) $(SRCS) $(INCS_DIR)
	@norminette $^
