# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/06 02:20:07 by grebrune          #+#    #+#              #
#    Updated: 2024/10/02 16:55:43 by grebrune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

########################################################################################################################
#                                                       VARIABLE                                                       #
########################################################################################################################

SRCS		:=	main.cpp					\
				Bureaucrat.cpp				\
				Intern.cpp					\
				AForm.cpp					\
				PresidentialPardonForm.cpp	\
				RobotomyRequestForm.cpp		\
				ShrubberyCreationForm.cpp	\

SRCS_D		:=	src/

OBJS_D		:=	objs/

OBJS		=	$(SRCS:%.cpp=$(OBJS_D)%.o)

HEAD		:=	Bureaucrat.hpp				\
				Intern.hpp					\
				AForm.hpp					\
				PresidentialPardonForm.hpp	\
				RobotomyRequestForm.hpp		\
				ShrubberyCreationForm.hpp	\

HEAD_D		:=	includes/

CFLAGS		:=	c++ -Wall -Wextra -Werror -std=c++98

BIN			:=	The_Intern

########################################################################################################################
#                                                        RULES                                                         #
########################################################################################################################

all			:	$(BIN)

$(BIN)		:	$(OBJS_D) $(OBJS)
				$(CFLAGS) -o $(BIN) $(OBJS)

$(OBJS)		:	$(OBJS_D)%.o: $(SRCS_D)%.cpp $(HEAD_D)/*.hpp Makefile
				$(CFLAGS) -I$(HEAD_D) -c $< -o $@

$(OBJS_D)	:
				@mkdir -p $(OBJS_D)
########################################################################################################################
#                                                        COMMANDS                                                      #
########################################################################################################################

clean		:
				$(RM) -r $(OBJS) $(OBJS_D)

fclean		:	clean
				$(RM) $(BIN)

re			:	fclean all

.PHONY: all clean fclean re
