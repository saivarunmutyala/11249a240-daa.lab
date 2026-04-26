AIM: To implement the Fractional Knapsack Problem using a Greedy Algorithm approach, where items can be divided partially to maximize the total value within a given weight capacity.

PROGRAM:
#include <stdio.h>

// Structure to store item details
struct Item {
    int weight;
    int value;
    float ratio; // value/weight ratio
};

// Function to sort items based on ratio (descending order)
void sort(struct Item items[], int n) {
    struct Item temp;

    // Bubble sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Swap if current ratio is smaller than next
            if (items[j].ratio < items[j + 1].ratio) {
                temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    int capacity;

    // Input number of items
    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    // Input weight and value of each item
    for (int i = 0; i < n; i++) {
        printf("Enter weight and value of item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);

        // Calculate value-to-weight ratio
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    // Input knapsack capacity
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    // Sort items based on ratio
    sort(items, n);

    float totalProfit = 0.0;

    // Apply Fractional Knapsack logic
    for (int i = 0; i < n; i++) {
        // If full item can be taken
        if (capacity >= items[i].weight) {
            totalProfit += items[i].value;
            capacity -= items[i].weight;
        } 
        else {
            // Take fraction of the item
            totalProfit += items[i].ratio * capacity;
            break; // Knapsack is full
        }
    }

    // Print maximum profit
    printf("Maximum profit = %.2f\n", totalProfit);

    return 0;
}

OUTPUT:
Enter number of items: 4
Enter weight and value of item 1: 6 1
Enter weight and value of item 2: 4 7
Enter weight and value of item 3: 8 5
Enter weight and value of item 4: 4 7
Enter knapsack capacity: 6
Maximum profit = 10.50
