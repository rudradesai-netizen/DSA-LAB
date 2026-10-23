#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[10];
    int n, i;
    printf("Enter the number of days tracked (max 10): ");
    scanf("%d", &n);
    printf("\nEnter the temperature records (°C) for %d days:\n", n);
    for (i = 0; i < n; i++) {
        printf("Day %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    bubbleSort(arr, n);
    printf("\nSorted Temperature Records (Low to High Temp):");
    for (i = 0; i < n; i++) {
        printf("\t%d°C", arr[i]);
    }

    return 0; 
}