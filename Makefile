all:
	gcc src/main.c -o game -Iraylib/src -Lraylib/src -lraylib -lm -lpthread -ldl -lrt -lX11
