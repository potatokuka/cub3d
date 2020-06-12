# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: greed <greed@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2020/06/08 16:10:11 by greed         #+#    #+#                  #
#    Updated: 2020/06/08 18:34:36 by greed         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			=	liblist.a

SRCS			=	foreach\
					new\
					new_back\
					new_front\
					remove\
					reverse\
					size


CFILES			=	$(SRCS:%=lst_%.c)
OFILES			=	$(SRCS:%=lst_%.o)

FLAGS			=	-Wall -Werror -Wextra

AR_COMMAND		= ar rs

all: $(NAME)

$(NAME): $(OFILES)
	$(AR_COMMAND) $(NAME) $(OFILES)

%.o: %.c
	gcc -o $@ -c $< $(FLAGS)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME) test

re: fclean all

