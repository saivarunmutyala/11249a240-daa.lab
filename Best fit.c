AIM:To implement the Best Fit algorithm in C for solving the Bin Packing problem, where items are placed into bins such that each item is assigned to the bin with the least remaining space that can still accommodate it. 

  PROGRAM:
#include <stdio.h>
// Function to implement Best Fit Algorithm
void bestFit(int items[], int n, int capacity)
{
    printf("\nBest Fit Algorithm\n");

    int bin[n];        // Array to store remaining capacity of bins
    int binCount = 0;  // Number of bins used
    // Initialize all bins with full capacity
    for (int i = 0; i < n; i++)
        bin[i] = capacity;

    // Loop through each item
    for (int i = 0; i < n; i++)
    {
        int bestIndex = -1;       // Stores best bin index
        int minSpace = capacity + 1; // Minimum leftover space

        // Check all existing bins to find best fit
        for (int j = 0; j < binCount; j++)
        {
            // If item fits and leaves minimum unused space
            if (bin[j] >= items[i] && (bin[j] - items[i]) < minSpace)
            {
                bestIndex = j;
                minSpace = bin[j] - items[i];
            }
        }

        // If a suitable bin is found
        if (bestIndex != -1)
        {
            bin[bestIndex] -= items[i]; // Reduce remaining space
            printf("Item %d (weight: %d) placed in Bin %d\n", i + 1, items[i], bestIndex + 1);
        }
        else
        {
            // Create a new bin if no suitable bin found
            bin[binCount] -= items[i];
            printf("Item %d (weight: %d) placed in Bin %d\n", i + 1, items[i], binCount + 1);
            binCount++; // Increase bin count
        }
    }

    // Print total bins used
    printf("Total bins used = %d\n", binCount);
}

int main()
{
    int n, capacity, itemSize;

    // Input number of items
    printf("Enter number of items: ");
    scanf("%d", &n);

    // Input bin capacity
    printf("Enter bin capacity: ");
    scanf("%d", &capacity);

    int items[n]; // Array to store item sizes

    printf("Enter item sizes:\n");

    // Input each item size
    for (int i = 0; i < n; i++)
    {
        printf("Item %d: ", i + 1);
        scanf("%d", &itemSize);

        // Check if item fits in bin
        if (itemSize <= capacity)
        {
            items[i] = itemSize;
        }
        else
        {
            // If item is too large, ask again
            printf("Item size exceeds bin capacity. Please enter again.\n");
            i--; // Repeat same index
        }
    }

    // Call Best Fit function
    bestFit(items, n, capacity);

    return 0;
}

OUTPUT:
Enter number of items: 3
Enter bin capacity: 5
Enter item sizes:
Item 1: 1
Item 2: 2
Item 3: 3

Best Fit Algorithm
Item 1 (weight: 1) placed in Bin 1
Item 2 (weight: 2) placed in Bin 1
Item 3 (weight: 3) placed in Bin 2
Total bins used = 2
