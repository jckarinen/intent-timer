CC = gcc
CFLAGS = -Wall -g

intent: intent.c
	$(CC) $(CFLAGS) intent.c -o intent

clean:
	rm -f intent
