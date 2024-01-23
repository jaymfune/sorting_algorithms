#include "sort.h"

/**
 * lomuto_partition - Lomuto partition scheme for Quick Sort
 *
 * @array: The array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Number of elements in the array
 *
 * Return: The index of the pivot after partitioning
 */
size_t lomuto_partition(int *array, size_t low, size_t high, size_t size)
{
    int pivot, temp;
    size_t i, j;

    pivot = array[high];
    i = low - 1;

    for (j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            /* Swap array[i] and array[j] */
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;

            /* Print the array after each swap */
            print_array(array, size);
        }
    }

    /* Swap array[i + 1] and array[high] (pivot) */
    temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;

    /* Print the array after each swap */
    print_array(array, size);

    return (i + 1);
}

/**
 * quick_sort_recursive - Recursive function to perform Quick Sort
 *
 * @array: The array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Number of elements in the array
 */
void quick_sort_recursive(int *array, size_t low, size_t high, size_t size)
{
    size_t partition_index;

    if (low < high)
    {
        /* Get the partition index */
        partition_index = lomuto_partition(array, low, high, size);

        /* Recursively sort elements before and after the partition */
        if (partition_index > 0)
            quick_sort_recursive(array, low, partition_index - 1, size);
        quick_sort_recursive(array, partition_index + 1, high, size);
    }
}

/**
 * quick_sort - Sorts an array of integers in ascending order using
 *              the Quick sort algorithm (Lomuto partition scheme).
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_recursive(array, 0, size - 1, size);
}

