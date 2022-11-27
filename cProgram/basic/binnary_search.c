#include <stdio.h>
int binary_search(int *arr, int len, int tar)
{
    int low = 0, high = len - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == tar)
        {
            return mid;
        }
        else if (arr[mid] > tar)
        {
            high = mid - 1;
        }
        else
        {
            low=mid+1;
        }
    }
    return -1;
}
int main(void)
{
    int a[] = {1, 2, 3, 4, 5, 6};
    int tar = 1;
    binary_search(a, sizeof(a) / sizeof(a[0]), tar);
    return 0;
}