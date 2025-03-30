#include <stdio.h>

int main() {
  FILE *file = fopen("./docs/exercise-basic.md", "r");

  if(!file) {
    perror("no file");
    return 1;
  }

  char buffer[100];
  while(fgets(buffer, sizeof(buffer), file)) {
    printf("%s", buffer);
  }

  fclose(file);
}