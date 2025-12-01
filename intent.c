#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>

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
		execl("./timer", "timer", argv[1], NULL);

		perror("Exec failed");
		exit(1);
	}

	return 0;
}


