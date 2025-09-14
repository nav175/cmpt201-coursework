#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *buffer = NULL;
  size_t bufsize = 0;
  ssize_t nread;

  printf("Please enter some text: ");
  nread = getline(&buffer, &bufsize, stdin);

  if (nread == -1) {
    perror("getline");
    free(buffer);
    return 1;
  }

  printf("Tokens:\n");

  char *saveptr; // keep track of position in string
  char *token = strtok_r(buffer, " \n", &saveptr); // split on space and newline

  while (token != NULL) {
    printf("  %s\n", token);
    token = strtok_r(NULL, " \n", &saveptr);
  }

  free(buffer);
  return 0;
}
