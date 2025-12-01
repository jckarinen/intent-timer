CC = gcc
CFLAGS = -Wall -g

intent: intent.c timer
	$(CC) $(CFLAGS) intent.c -o intent

timer: timer.c
	$(CC) $(CFLAGS) timer.c -o timer

clean:
	rm -f intent timer
