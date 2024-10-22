PRG_NAME=xoxo
$(PRG_NAME): $(PRG_NAME).c
	clang $(PRG_NAME).c game.c `pkg-config --libs --cflags raylib` -o $(PRG_NAME)
