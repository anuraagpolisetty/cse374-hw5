#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "dict.h"

struct dict_item {
  // Each word is at most 100 bytes.
  char word[100];
  // The length of each word.
  size_t len;
};

struct dict_t {
  // The path to the underlying file
  char *path;
  // The file descriptor of the opened file. Set by dictionary_open_map.
  int fd;
  // How many items the mmaped file should store (this will determine the size).
  // There are ~500k words in /usr/share/dict/words.
  size_t num_items;
  // A pointer to the first item.
  struct dict_item *base;
};

// Construct a new dict_t struct.
// data_file is where to write the data,
// num_items is how many items this data file should store.
struct dict_t* dictionary_new(char *data_file, size_t num_items) {
}

// Computes the size of the underlying file based on the # of items and the size
// of a dict_item.
size_t dictionary_len(struct dict_t *dict) {
  return dict->num_items * sizeof(struct dict_item);
}

// This is a private helper function. It should:
// Open the underlying path (dict->path), ftruncate it to the appropriate length
// (dictionary_len), then mmap it.
int dictionary_open_map(struct dict_t *dict) {
}


// The rest of the functions should be whatever is left from the header that
// hasn't been defined yet.
// Good luck!
