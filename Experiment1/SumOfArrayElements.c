#include <stdio.h>

int sum_of_array(int arr[], int size) {
  
  if (size == 0) {
    return 0;
  }

  
  return arr[0] + sum_of_array(arr + 1, size - 1);
}

int main() {
  int my_array[] = {1, 2, 3, 4, 5};
  int n = sizeof(my_array) / sizeof(my_array[0]);

  int result = sum_of_array(my_array, n);
  printf("Sum of array elements: %d\n", result);

  return 0;
}
