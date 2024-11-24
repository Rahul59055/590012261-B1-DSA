#include <stdio.h>
#include <stdlib.h>

// Union to store sum and average as float or integer
union Data {
    int sum;
    float avg;
};

int main() {
    int *arr, n;
    union Data data;

    // Step 1: Input the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Step 2: Dynamically allocate memory for 'n' integers
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Step 3: Input values into the dynamically allocated array
    printf("Enter %d integers:\n", n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];  // Calculate sum during input
    }

    // Step 4: Calculate and store the sum and average in the union
    data.sum = sum;  // Store sum in union
    data.avg = (float)sum / n;  // Calculate average and store in union

    // Step 5: Output the sum and average
    printf("Sum = %d\n", data.sum);
    printf("Average = %.2f\n", data.avg);

    // Step 6: Free dynamically allocated memory
    free(arr);

    return 0;
}
