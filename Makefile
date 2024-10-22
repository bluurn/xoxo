xoxo: xoxo.c game.c
	clang xoxo.c game.c `pkg-config --libs --cflags raylib` -o xoxo
