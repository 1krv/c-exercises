/*
 * Take an integer n (n >= 0) and a digit d (0 <= d <= 9) as an integer.
 *
 * Square all numbers k (0 <= k <= n) between 0 and n.
 *
 * Count the numbers of digits d used in the writing of all the k**2.
 *
 * Implement the function taking n and d as parameters and returning this count.
 */

#include <stdio.h>

int nbDig(int n, int d) {
  int count = 0;
  char dc = d + '0';

  for (int i = 0; i <= n; i++) {
    char buffer[64];
    sprintf(buffer, "%d", i * i);
    for (int j = 0; buffer[j] != '\0'; j++) {
      if (buffer[j] == dc)
        count++;
    }
  }

  return count;
}

int main(void) {
  int result = nbDig(10, 1);
  printf("n = 10, d = 1: result %d\n", result);
  return 0;
}
