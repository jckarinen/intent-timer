#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>

void setTimer(int min) {
	int dur = min * 60;
	int dur1 = dur > 60 ? dur - 60 : 0;
	int dur2 = dur > 60 ? 60 : dur;
	sleep(dur1);
	pid_t pid = fork();
	if (pid < 0) {
		perror("Fork failed (aux)");
		exit(1);
	}
	else if (pid == 0) {
		execl("/usr/bin/osascript", "osascript", "-e", "display notification \"60 seconds remaining before screen lock\" with title \"Time's almost up\"", NULL);
		perror("exec failed");
		exit(1);
	}
	else {
		sleep(dur2);
		execl("/usr/bin/osascript", "osascript", "-e", "tell application \"System Events\" to keystroke \"q\" using {control down, command down}", NULL);
	}
	return;
}

int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("Too few arguments\n");
		return 1;
	}
	if (argc > 2) {
		printf("Too many arguments\n");
		return 1;
	}

	char *endptr;
	errno = 0;
	int n = strtol(argv[1], &endptr, 10);

	if (errno == ERANGE) {
		printf("Integer out of range: %s\n", argv[1]);
		return 1;
	}

	if (*endptr != '\0') {
		printf("Invalid integer provided: %s\n", argv[1]);
		return 1;
	}

	pid_t pid = fork();
	
	if (pid < 0) {
		perror("Fork failed");
		exit(1);
	}
	else if (pid == 0) {
		setsid();
		setTimer(n);
	}

	return 0;
}


