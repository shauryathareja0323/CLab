#include <stdio.h>

int main() {
    int n, i, j, element;
    int a1[100];

    
    printf("Enter the number of elements (max %d): ", 100);
    scanf("%d", &n);

   
    if (n <= 0 || n > 100) {
        printf("Invalid number of elements. Please enter a value between 1 and %d.\n", 100);
        return 1;
    }

    printf("Enter %d elements for the array:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a1[i]);
    }

    printf("Enter the element to insert: ");
    scanf("%d", &element);

    printf("Enter the position (index) for insertion (0 to %d): ", n - 1);
    scanf("%d", &i);

    if (i < 0 || i > n) {
        printf("Invalid insertion position. Please enter a value between 0 and %d.\n", n - 1);
        return 1;
    }

    if (n < 100) {
        for (int j = n; j > i; j--) {
            a1[j] = a1[j - 1];
        }
        a1[i] = element;
        n++;  
        printf("Element inserted successfully.\n");
    } else {
        printf("Array is full, cannot insert element.\n");
    }


    printf("Enter the position (index) for deletion (0 to %d): ", n - 1);
    scanf("%d", &j);

    
    if (j < 0 || j >= n) {
        printf("Invalid deletion position. Please enter a value between 0 and %d.\n", n - 1);
        return 1;
    }

    for (int k = j; k < n - 1; k++) {
        a1[k] = a1[k + 1];
    }
    n--;  
    printf("Element deleted successfully.\n");

    printf("Modified array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a1[i]);
    }
    printf("\n");

    return 0;
}
