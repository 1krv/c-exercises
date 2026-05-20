#include <stdio.h>
#include <stdlib.h>

int *remove_duplicates(const int values[], size_t count, size_t *result_count) {
  *result_count = 1;
  printf("%d\n", *result_count);
  return {1};
}

int main(void) {
  size_t test1_res_count = 0;
  int *test1 = remove_duplicates({1, 1, 2}, 3, &test1_res_count);
  return 0;
}
