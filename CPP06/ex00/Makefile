# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nelix <nelix@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/14 09:17:51 by nelix             #+#    #+#              #
#    Updated: 2022/08/23 17:11:47 by nelix            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= convert

CXX			:=  c++
CXXFLAGS	:= -Wall -Wextra -Werror -Wshadow -std=c++98
DEPFLAGS	 = -MT $@ -MMD -MP -MF $(DDIR)/$*.d
LDFLAGS		:=

VPATH		:= ./ src/
SRCS		:= $(shell find ./* -iname "*.cpp")

ODIR		:= obj
OBJS		:= $(SRCS:%.cpp=$(ODIR)/%.o)

DDIR		:= $(ODIR)/.dep
DEPS		:= $(SRCS:%.cpp0$(DDIR)/%.d)

# COLORS
BLACK = \033[0;30m
RED = \033[0;31m
GREEN = \033[1;32m
LGREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[1;34m
LBLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m
RESET = \e[0m
UP = "\033[A"
CUT = "\033[K"

# RULES
.PHONY: all clean fclean RED

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $@ $(LDFLAGS)
	@printf $(UP) $(CUT)
	@printf "%-54b %b" "$(GREEN)$(NAME) compiled succesfully!" "$(GREEN)[ok]$(RESET)\n"

$(ODIR)/%.o: %.cpp | $(ODIR) $(DDIR)
	@$(CXX) $(CXXFLAGS) $(DEPFLAGS) -c $< -o $@
	@printf $(UP)$(CUT)
	@printf "%-61b %b" "$(BLUE)compiling: $(LBLUE)$@" "$(GREEN)[ok]$(RESET)\n"

$(ODIR):
	@mkdir -p $@

$(DDIR):
	@mkdir -p $@
	
all: $(NAME)

clean:
	@$(RM) -r $(DDIR) $(ODIR)
	@printf "%-54b %b" "$(RED) $(NAME) cleaned!" "$(GREEN)[ok]$(RESET)\n"
	
fclean: clean
	@$(RM) $(NAME)

re: fclean all

-include $(DEPS)