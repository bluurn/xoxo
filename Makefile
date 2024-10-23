xoxo: xoxo.c game.c render.c
	clang xoxo.c game.c render.c `pkg-config --libs --cflags raylib` -o xoxo
