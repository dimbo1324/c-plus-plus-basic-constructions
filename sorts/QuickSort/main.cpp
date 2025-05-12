#include <iostream>
#include <utility>
#include <cstdlib>
#include <ctime>
void quicksort(int array[], int length);
void quicksort_rec(int array[], int low, int high);
int partition(int array[], int low, int high);
int main()
{
    int array[] = {10, 7, 2, 9, 4, 1, 8, 3, 6, 5};
    int arrayLength = sizeof(array) / sizeof(array[0]);
    quicksort(array, arrayLength);
    for (int i = 0; i < arrayLength; i++)
    {
        std::cout << array[i] << " ";
    }
    return 0;
}
void quicksort(int array[], int length)
{
    srand(time(NULL));
    quicksort_rec(array, 0, length - 1);
}
void quicksort_rec(int array[], int low, int high)
{
    if (low < high)
    {
        int pivot_index = partition(array, low, high);
        quicksort_rec(array, low, pivot_index - 1);
        quicksort_rec(array, pivot_index + 1, high);
    }
}
int partition(int array[], int low, int high)
{
    int pivot_index = low + (rand() % (high - low + 1));
    if (pivot_index != high)
    {
        std::swap(array[pivot_index], array[high]);
    }
    int pivot_value = array[high];
    int i = low;
    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot_value)
        {
            std::swap(array[i], array[j]);
            i++;
        }
    }
    std::swap(array[i], array[high]);
    return i;
}
