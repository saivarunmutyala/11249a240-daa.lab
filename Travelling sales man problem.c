AIM:To write and execute a C program to solve the Travelling Salesman Problem (TSP) using Dynamic Programming (bitmasking) and find the minimum travelling cost.

PROGRAM:
#include <stdio.h>
#include <limits.h>

#define MAXN 15
#define INF INT_MAX

int n;                  // Number of cities
int d[MAXN][MAXN];     // Cost matrix
int dp[MAXN][1 << MAXN]; // DP table for memoization

// Function to calculate minimum cost
int g(int i, int s)
{
    // If all cities visited, return cost to go back to start
    if (s == 0)
        return d[i][0];

    // If already computed, return stored value
    if (dp[i][s] != -1)
        return dp[i][s];

    int mincost = INF;

    // Try visiting all remaining cities
    for (int k = 0; k < n; k++)
    {
        // If city k is in set s
        if (s & (1 << k))
        {
            // Cost = current to k + remaining path
            int cost = d[i][k] + g(k, s & ~(1 << k));

            // Update minimum cost
            if (cost < mincost)
            {
                mincost = cost;
            }
        }
    }

    // Store and return result
    return dp[i][s] = mincost;
}

int main()
{
    // Input number of cities
    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");

    // Input cost matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &d[i][j]);

    // Initialize DP table with -1
    for (int i = 0; i < n; i++)
        for (int mask = 0; mask < (1 << n); mask++)
            dp[i][mask] = -1;

    // Create set of cities except starting city (0)
    int S = 0;
    for (int i = 1; i < n; i++)
        S |= (1 << i);

    // Find minimum cost starting from city 0
    int result = g(0, S);

    // Print cost matrix
    printf("\nGiven Cost Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        printf("|");
        for (int j = 0; j < n; j++)
            printf(" %d ", d[i][j]);
        printf("|\n");
    }

    // Print result
    printf("Minimum travelling cost: %d\n", result);

    return 0;
}

OUTTPUT:
Enter number of cities: 4
Enter cost matrix:
0 10 15 20
10 0 35 25
15 35 0 30
20 25 30 0
Given Cost Matrix:
| 0  10  15  20 |
| 10  0  35  25 |
| 15  35  0  30 |
| 20  25  30  0 |
Minimum travelling cost: 80
