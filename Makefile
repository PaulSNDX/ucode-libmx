NAME = libmx.a

SRC_FILES = $(wildcard src/*.c)
OBJ_FILES = $(addprefix obj/, $(notdir $(SRC_FILES:%.c=%.o)))

all: $(NAME) clean

$(NAME): $(OBJ_FILES)
	@ar rcs $@ $^

$(OBJ_FILES): | obj

obj/%.o: src/%.c $(inc/libmx.h)
	@clang -std=c11 -Wall -Wextra -Werror -Wpedantic -c $< -o $@ -I inc

obj:
	@mkdir -p $@

clean:
	@rm -rf obj

uninstall:
	@rm -rf obj
	@rm -rf $(NAME)

reinstall: uninstall all

.PHONY: all uninstall clean reinstall