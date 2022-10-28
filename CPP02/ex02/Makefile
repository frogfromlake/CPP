# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fquist <fquist@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/25 14:04:06 by fquist            #+#    #+#              #
#    Updated: 2022/08/06 18:38:46 by fquist           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= a.out

CXX			:= c++
CXXFLAGS	:= -Wall -Wextra -Werror -std=c++98

DEPFLAGS	= -MT $@ -MMD -MP -MF $(DDIR)/$*.d
LDFLAGS		:=

VPATH		:= ./ src/
SRCS		:= $(shell find ./* -iname "*.cpp")

ODIR		:= obj
OBJS		:= $(SRCS:%.cpp=$(ODIR)/%.o)

DDIR		:= $(ODIR)/.dep
DEPS		:= $(SRCS:%.cpp=$(DDIR)/%.d)

# COLORS
BLACK = \033[0;30m
RED = \033[0;31m
GREEN = \033[1;32m
LGREEN = \033[0;32m
YELLOW = \033[0;33m
LBLUE = \033[0;34m
BLUE = \033[1;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m
RESET = \e[0m
UP = "\033[A"
DOWN = "\033[B"
CUT = "\033[K"

# **************************************************************************** #
#	RULES																	   #
# **************************************************************************** #

.PHONY: all clean fclean re

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $@ $(LDFLAGS)
	@echo $(UP)$(CUT)"$(GREEN)$(NAME)$(LGREEN) compiled successfully!" "[✓]"

$(ODIR)/%.o: %.cpp | $(ODIR) $(DDIR)
	@$(CXX) $(CXXFLAGS) $(DEPFLAGS) -c $< -o $@
	@echo $(UP)$(CUT)"$(BLUE)compiling: $(LBLUE)$@" "$(LGREEN)[✓]$(WHITE)"


$(ODIR):
	@echo
	@mkdir -p $@

$(DDIR):
	@mkdir -p $@

all: $(NAME)

clean:
	@$(RM) -r $(DDIR) $(ODIR)
	@echo "$(RED)$(NAME) cleaned!" "$(LGREEN)[✓]$(WHITE)"

fclean: clean
	@$(RM) $(NAME)

re: fclean all

-include $(DEPS)