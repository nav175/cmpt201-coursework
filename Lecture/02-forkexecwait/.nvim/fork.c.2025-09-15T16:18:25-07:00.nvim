#include <stdio.h>
#include <unistd.h>

int main() {
  pid_t pid = getpid();
  fork();
  pid_t ppid = getppid();
  if (pid == ppid) {
    printf("PID of the Child function = %d\n", getpid());
    printf("PPID of the Child function = %d\n", ppid);
    printf("This is Child \n");
  } else {
    printf("PID of the original function = %d\n", getpid());
    printf("PPID of the Original function = %d\n", ppid);
    printf("This is Parent \n");
  }
}
