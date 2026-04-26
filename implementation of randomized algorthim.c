AIM:To write and execute a C program to sort a list of elements using Randomized Quick Sort and analyze its performance.

PROGRAM:
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function (places pivot at correct position)
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // Choose last element as pivot
    int i = (low - 1);

    // Rearrange elements based on pivot
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    // Place pivot in correct position
    swap(&arr[i + 1], &arr[high]);

    return (i + 1); // Return pivot index
}

// Quick Sort function
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        // Select random pivot index
        int randomIndex = low + rand() % (high - low + 1);

        // Swap random pivot with last element
        swap(&arr[randomIndex], &arr[high]);

        // Partition array
        int pi = partition(arr, low, high);

        // Recursively sort left and right subarrays
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int n;

    srand(time(NULL)); // Seed random number generator

    // Input number of elements
    printf("Enter number of elements: ");

    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    int numbersToSort[n];

    // Input array elements
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &numbersToSort[i]);

    // Call Quick Sort
    quickSort(numbersToSort, 0, n - 1);

    // Print sorted array
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", numbersToSort[i]);

    return 0;
}

OUTPUT:
Enter number of elements: 4
Enter 4 integers: 3
7
5
8

Sorted array: 3 5 7 8 
