all: compile

compile:
	gcc main.c -o runserver
	gcc client.c -o runclient
	gcc window.c -o window -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

