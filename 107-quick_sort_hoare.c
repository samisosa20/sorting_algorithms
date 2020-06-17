#include "sort.h"


/**
 * swap - that sorts a doubly linked list of integers
 * @array: pointers array
 * @size: size value the lengeth
 * @a: integer data
 * @b: integer data
 */
void swap(int *array, size_t size, int *a, int *b)
{
    int temp;

        temp = *a;
        *a = *b;
        *b = temp;
        print_array(array, size);
}

/**
 * partition_hoare - function that helps partitioning the array
 * so we will have a two arrays that aren't sorted yet and
 * the pivot
 * array = left_array + pivot + right_array
 * @A: array of integers
 * @size: lenght of array
 * @low_index: low index
 * @high_index: high index
 * Return: none
 */
int partition_hoare(int *array, ssize_t left, ssize_t right, ssize_t size)
{
    int pivot;
    ssize_t asc, des;

    pivot = array[right];
    for (asc = left - 1, des = right + 1; asc < des; )
    {
        do {
            asc++;
        } while (array[asc] < pivot);

        do {
            des--;
        } while (array[des] > pivot);

        if (asc < des)
            swap(array, size, array + asc, array + des);
    }
    return (asc);
}

/**
 * hoare_quicksort - function that sorts an array of integers
 * in iending order using the Quick sort algorithm
 * @A: array of integers
 * @size: lenght of array
 * @low_index: low index
 * @high_index: high index
 * Return: none
 */
void hoare_quicksort(int *A, ssize_t low_index, ssize_t high_index,
size_t size)
{
	ssize_t pivot;


	if (high_index > low_index)
	{
		/*Divide y trae el punto pivote*/
		pivot = partition_hoare(A, low_index, high_index, size);
		/*hace recursion de la primera particion*/
		hoare_quicksort(A, low_index, pivot - 1, size);
		/*hace recursion de la segunda particion*/
		hoare_quicksort(A, pivot, high_index, size);
	}
}

/**
 * quick_sort_hoare - function that sorts an array of integers
 * in iending order using the Quick sort algorithm
 * @array: array of integers
 * @size: lenght of array
 * Return: none
 */
void quick_sort_hoare(int *array, size_t size)
{
	ssize_t low_index, high_index;

	if (!array || size < 2)
		return;

	low_index = 0;
	high_index = size - 1;

	hoare_quicksort(array, low_index, high_index, size);
}




