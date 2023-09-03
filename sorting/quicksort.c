#include <stdio.h>

// void swap(int *i , int *j)
// {
//     int temp = *i;
//     *i = *j;
//     *j = temp;
// }

int partition(int arr[], int l, int h)
{
    int pivot = arr[l];
    int i = l;
    int j = h;

    while (i < j)
    {
        do
        {
            i++;
        } while (arr[i] <= pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);
        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[l];
    arr[l] = arr[j];
    arr[j] = temp;
    return j;
}

void quicksort(int arr[], int l, int h)
{
    if (l < h)
    {
        int j = partition(arr, l, h);
        quicksort(arr, l, j);
        quicksort(arr, j + 1, h);
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {43, 13, 76, 23, 1, 12, 7, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Before sorting : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    quicksort(arr, 0, n-1);
    printf("\nAfter sorting : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
