#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dict.h"

int main(int argc, char *argv[argc+1]) {
  struct dict_t *dict = dictionary_new(argv[2], 5e5);
  if (!strcmp(argv[1], "gen")) {
    if (dictionary_generate(dict, argv[3]) < 0) {
      printf("Error generating dictionary\n");
      return EXIT_FAILURE;
    }
  } else if (!strcmp(argv[1], "load")) {
    if(!dictionary_load(dict)) {
      printf("Error loading dictionary\n");
      return EXIT_FAILURE;
    }
  }
  char *addr = dictionary_exists(dict, "cat");
  if (addr) {
    printf("i haz cat, it is at: %p\n", (void*)addr);
  }
  dictionary_close(dict);
  return EXIT_SUCCESS;
}
