#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	if (argc < 2) {
		perror("No time provided");
		exit(1);
	}
	int dur = (atoi(argv[1])) * 60;
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
	exit(1);
}
