/*
 * Given an integer array nums sorted in non-decresing order, return an array of
 * the squares of each number sorted in non-decresing order.
 */

#include <stdio.h>
#include <stdlib.h>

int *sorted_squares(int *nums, int nums_size, int *return_size) {
  *return_size = nums_size;
  int *result = malloc(sizeof(int) * nums_size);

  int left = 0;
  int right = nums_size - 1;
  int index = nums_size - 1;

  while (left <= right) {
    int left_square = nums[left] * nums[left];
    int right_square = nums[right] * nums[right];

    if (left_square > right_square) {
      result[index] = left_square;
      left++;
    } else {
      result[index] = right_square;
      right--;
    }
    index--;
  }

  return result;
}

int main(void) {
  int nums[] = {-4, -1, 0, 3, 10};
  int nums_size = sizeof(nums) / sizeof(nums[0]);

  int return_size = 0;
  int *return_nums = sorted_squares(nums, nums_size, &return_size);

  for (int i = 0; i < return_size; i++) {
    printf("%d ", return_nums[i]);
  }
  printf("\n");

  free(return_nums);
  return 0;
}
