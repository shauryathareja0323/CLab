#include <stdio.h>

int main() {
  int n, target;

  
  printf("Enter the number of elements (n): ");
  scanf("%d", &n);


  int arr[n];

  
  printf("Enter %d numbers:\n", n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  
  printf("Enter the number to search for: ");
  scanf("%d", &target);

  
  int found = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] == target) {
      found = 1;
      break;
    }
  }


  if (found) {
    printf("Number %d found in the array.\n", target);
  } else {
    printf("Number %d not found in the array.\n", target);
  }

  return 0;
}
