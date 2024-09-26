all: compile

compile:
	gcc src/mainServer.c -o runserver
	gcc src/mainClient.c -o runclient -I include -L lib -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

