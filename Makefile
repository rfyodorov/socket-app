# env
# CC=gcc
CFLAGS="-Wformat-security"
CXXFLAGS="${CFLAGS}"

all: client server clear.client clear.server

client: clear.client
	gcc -o client client.c

server: clear.server
	gcc -o server server.c

clear.client:
	rm -rf *.o client

clear.server:
	rm -rf *.o server

clear:
	rm -rf client server

