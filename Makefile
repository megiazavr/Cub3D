# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncruz-ne <ncruz-ne@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/02 19:37:50 by ncruz-ne          #+#    #+#              #
#    Updated: 2026/09/03 18:32:04 by ncruz-ne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D
NAME_DB		= cub3D_db

SRC_DIR 	= src
OBJ_DIR 	= obj
OBJ_DIR_DB 	= obj_db

PARSING_SRC	= $(addprefix $(SRC_DIR)/parsing/, parsing.c parsing_texture.c \
				parsing_colors.c parsing_helper.c error.c)
SRC			= $(addprefix $(SRC_DIR)/, main.c) \
				$(PARSING_SRC)
OBJ 		= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))
OBJ_DB 		= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR_DB)/%.o,$(SRC))

HEADERS 	= $(addprefix headers/, cub3D.h)

LIBS_DIR	= ./libs
LIBFT		= $(LIBS_DIR)/libft/libft.a

CC			= cc
CPPFLAGS	= -Iheaders
CFLAGS		= -Wall -Wextra -Werror
LDFLAGS		= -L$(LIBS_DIR)/libft
LDLIBS		= -lft
DB_FLAGS	= -g

RM 			= rm -f

ARGS			= maps/f.cub

TEST_DIR		= test_logs
SIM_LOG			= sim_log
STDERR_LOG		= sim_stderr
VALG_LOG		= valg_out
HELG_LOG		= helg_out

ESC             := $(shell printf '\033')
COLOR_RESET     := $(ESC)[0m
VIOLET			:= $(ESC)[38;2;180;140;230m
# DARK_VIOLET     := $(ESC)[38;2;148;0;211m
GREEN           := $(ESC)[32m
# RED             := $(ESC)[31m
# BRIGHT_GREEN    := $(ESC)[92m
# LIGHT_GREEN     := $(ESC)[38;2;144;238;144m
# SPRING_GREEN    := $(ESC)[38;2;0;255;127m
# SOFT_LIME       := $(ESC)[38;2;180;255;180m

SUCCESS         := $(ESC)[38;2;144;238;144m
SUCCESS_BOLD    := $(ESC)[38;2;0;255;127m
INFO            := $(ESC)[38;2;173;216;230m
PATH_COLOR      := $(ESC)[38;2;221;160;221m
# WARNING         := $(ESC)[38;2;255;215;0m
# ERROR_COLOR     := $(ESC)[38;2;255;127;127m
# MUTED           := $(ESC)[38;2;190;190;190m


all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(LDFLAGS) $(LDLIBS) -o $@
	@printf "%b compiled.\n" "$(GREEN)$@$(COLOR_RESET)"

$(LIBFT):
	$(MAKE) -C $(LIBS_DIR)/libft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(dir $@)
	@$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@
	@printf "%b created.\n" "$(SUCCESS)$@$(COLOR_RESET)"

clean:
	@$(RM) $(OBJ)
	@$(RM) -r $(OBJ_DIR)
	@$(MAKE) -C $(LIBS_DIR)/libft clean
	@printf "$(INFO)All object files removed.$(COLOR_RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBS_DIR)/libft fclean
	@printf "$(INFO)Executable removed.$(COLOR_RESET)\n"

re: fclean all

run: re $(NAME)
	@printf "Running $(VIOLET)./$(NAME) $(ARGS)$(COLOR_RESET)\n\n"
	@./$(NAME) $(ARGS)

norm:
	@curl -L -o "en.norm.pdf" \
	"https://raw.githubusercontent.com/42school/norminette/master/pdf/en.norm.pdf"


#################################### RULES FOR TESTING ####################################
$(NAME_DB): $(OBJ_DB) $(LIBFT)
	@$(CC) $(OBJ_DB) $(LDFLAGS) $(LDLIBS) -o $@
	@printf "%b for debugging compiled.\n" "$(GREEN)$@$(COLOR_RESET)"

$(OBJ_DIR_DB)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(dir $@)
	@$(CC) $(CPPFLAGS) $(CFLAGS) $(DB_FLAGS) -c $< -o $@
	@printf "%b created.\n" "$(SUCCESS)$@$(COLOR_RESET)"

$(TEST_DIR):
	@mkdir -p $@
	@printf "%b created.\n" "$(SUCCESS)/$@$(COLOR_RESET)"

print: re $(NAME) $(TEST_DIR)
	@printf "Running $(VIOLET)./$(NAME) $(ARGS)$(COLOR_RESET)\n\n"
	@./$(NAME) $(ARGS) > $(TEST_DIR)/$(SIM_LOG).txt
	@printf "See simulation logs in $(PATH_COLOR)$(TEST_DIR)/$(SIM_LOG).txt$(COLOR_RESET).\n"

stderr: re $(NAME) $(TEST_DIR)
	@printf "Running $(VIOLET)./$(NAME) $(ARGS)$(COLOR_RESET) to check for errors.\n\n"
	@./$(NAME) $(ARGS) 2> $(TEST_DIR)/$(STDERR_LOG).txt
	@printf "\nRun concluded. \
	See output in $(PATH_COLOR)$(TEST_DIR)/$(STDERR_LOG).txt$(COLOR_RESET).\n"

db:
	@gdbtui --args ./$(NAME_DB) $(ARGS)

valg: $(NAME_DB) $(TEST_DIR)
	@valgrind --track-fds=yes --leak-check=full --show-leak-kinds=all -s \
	--log-file=$(TEST_DIR)/$(VALG_LOG).log ./$(NAME_DB) $(ARGS)
	@printf "\nValgrind run concluded. \
	See output in $(PATH_COLOR)$(TEST_DIR)/$(VALG_LOG).log$(COLOR_RESET).\n"

hel: $(NAME_DB) $(TEST_DIR)
	@valgrind --tool=helgrind --track-destroy=all -s --log-file=$(TEST_DIR)/$(HELG_LOG).log \
	./$(NAME_DB) $(ARGS)
	@printf "\nHelgrind run concluded. \
	See output in $(PATH_COLOR)$(TEST_DIR)/$(HELG_LOG).log$(COLOR_RESET).\n"

test: tclean print stderr valg hel db

tclean:
	@$(RM) -r $(TEST_DIR)
	@printf "%b for debugging removed.\n" "$(PATH_COLOR)/$(TEST_DIR)$(COLOR_RESET)"
	@$(RM) -r $(OBJ_DIR_DB)
	@$(RM) $(NAME_DB)
	@printf "$(INFO)Debugging executable and object files removed.$(COLOR_RESET)\n"


.PHONY: all clean fclean re run norm print stderr db valg hel test tclean