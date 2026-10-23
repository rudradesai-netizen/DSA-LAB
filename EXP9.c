#include <stdio.h>

int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2; 
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int thresholds[] = {38, 40, 42, 45, 48, 50};
    int n = 6 ;
    int currentTemp;

    printf("Enter current recorded temperature (°C): \n");
    scanf("%d", &currentTemp);

    int pos = binarySearch(thresholds, n, currentTemp);

    if (pos != -1) {
        printf("ALERT: Temperature matches threshold tier %d (%d°C). Trigger warning protocol!\n", pos + 1, currentTemp);
    } else {
        printf("Temperature %d°C does not match listed threshold.\n", currentTemp);
    }

    return 0;
}
