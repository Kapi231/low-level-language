all: compile

compile:
	gcc src/main.c -o runserver
	gcc src/client.c -o runclient
	gcc src/window.c -o window -I include -L lib -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

