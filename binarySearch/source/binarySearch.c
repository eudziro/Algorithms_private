# include "binarySearch.h"

int binarySearch(int array[], int high, int target)
{
    int low = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (array[mid] == target)
            return mid;

        if (array[mid] < target)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}
