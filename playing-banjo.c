#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *are_you_playing_banjo(const char *name) {
  char *output = calloc(BUFSIZ, sizeof(char));

  if (name[0] == 'R' || name[0] == 'r') {
    strcpy(output, name);
    strcat(output, " plays banjo");
  } else {
    strcpy(output, name);
    strcat(output, " does not play banjo");
  }

  return output;
}

int main(void) {
  char name[] = "Jody";
  char *result = are_you_playing_banjo(name);
  printf("%s\n", result);
  return 0;
}
