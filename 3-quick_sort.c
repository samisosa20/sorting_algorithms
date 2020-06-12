#include "sort.h"

/**
 * partition - function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * @A: array of integers
 * @size: lenght of array
 * @lo: low index
 * @hi: high index
 * Return: none
 */
ssize_t partition(int *A, ssize_t lo, ssize_t hi, size_t size)
{
	int pivot = A[hi]; /*pivote = al ultimo valor del array o la particion*/
	ssize_t i = lo, j; /*i = al indice minimo*/
	int aux;

	/* 10, 2, 8, 4, 5*/
	/*recorre el array o la particion*/
	for (j = lo; j < hi; j++)
	{
		/*si el valor del array en la posicion j es menor que el pivote*/
		if (A[j] < pivot)
		{
			if (A[i] != A[j])
			{
				aux = A[j];
				A[j] = A[i];
				A[i] = aux;
				print_array(A, size);
			}
			i++;
		}
	}
	/*Cambia el ultimo o pivote con array en la posicion i*/
	if (A[i] != A[hi])
	{
		aux = A[hi];
		A[hi] = A[i];
		A[i] = aux;
		print_array(A, size);
	}
	return (i);
}

/**
 * quicksort2 - function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * @A: array of integers
 * @size: lenght of array
 * @lo: low index
 * @hi: high index
 * Return: none
 */
void quicksort2(int *A, ssize_t lo, ssize_t hi, size_t size)
{
	ssize_t p = 0;


	if (lo < hi)
	{
		/*Divide y trae el punto pivote*/
		p = partition(A, lo, hi, size);
		/*hace recursion de la primera particion*/
		quicksort2(A, lo, p - 1, size);
		/*hace recursion de la segunda particion*/
		quicksort2(A, p + 1, hi, size);
	}
}

/**
 * quick_sort - function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * @array: array of integers
 * @size: lenght of array
 * Return: none
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quicksort2(array, 0, size - 1, size);
}
