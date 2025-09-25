#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main() {
  printf("starting main...");

  pid_t pid = fork();
  if (pid) {
    int wstatus = 0;
    if (waitpid(pid, &wstatus, 0) == -1) {
      perror("waitpid");
      exit(EXIT_FAILURE);
    }
    if (WIFEXITED(wstatus)) {
      printf("Child exited; Reason for exit: %d\n", WEXITSTATUS(wstatus));
    } else {
      printf("Child did not exit normally.\n");
    }
  } else {
    if (execl("/bin/ls", "/bin/ls", "-a", "-l", NULL) == -1) {
      perror("execl");
      exit(EXIT_FAILURE);
    }
  }
}
