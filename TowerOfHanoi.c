AIM:To write and execute a C program to solve the Tower of Hanoi problem using recursion and display the sequence of steps required to move all disks from the source rod to the destination rod using an auxiliary rod.

PROGRAM:
#include <stdio.h>

// Recursive function for Tower of Hanoi
void toh(int diskcount, char s, char d, char t){
    
    // Base case: only one disk
    if (diskcount == 1)
    {
        printf("\nMove disk %d from %c to %c", diskcount, s, d);
        return;
    }

    // Step 1: Move n-1 disks from source to temporary
    toh(diskcount - 1, s, t, d);

    // Step 2: Move nth disk from source to destination
    printf("\nMove disk %d from %c to %c", diskcount, s, d);

    // Step 3: Move n-1 disks from temporary to destination
    toh(diskcount - 1, t, d, s);
}

int main() {
    int n;

    // Input number of disks
    printf("Enter number of disks: ");
    scanf("%d", &n);

    // Call Tower of Hanoi function
    // S = Source, D = Destination, T = Temporary
    toh(n, 'S', 'D', 'T');

    return 0;
}#include <stdio.h>

// Recursive function for Tower of Hanoi
void toh(int diskcount, char s, char d, char t){
    
    // Base case: only one disk
    if (diskcount == 1)
    {
        printf("\nMove disk %d from %c to %c", diskcount, s, d);
        return;
    }

    // Step 1: Move n-1 disks from source to temporary
    toh(diskcount - 1, s, t, d);

    // Step 2: Move nth disk from source to destination
    printf("\nMove disk %d from %c to %c", diskcount, s, d);

    // Step 3: Move n-1 disks from temporary to destination
    toh(diskcount - 1, t, d, s);
}

int main() {
    int n;

    // Input number of disks
    printf("Enter number of disks: ");
    scanf("%d", &n);

    // Call Tower of Hanoi function
    // S = Source, D = Destination, T = Temporary
    toh(n, 'S', 'D', 'T');

    return 0;
}

OUTPUT:
Enter number of disks: 5

Move disk 1 from S to D
Move disk 2 from S to T
Move disk 1 from D to T
Move disk 3 from S to D
Move disk 1 from T to S
Move disk 2 from T to D
Move disk 1 from S to D
Move disk 4 from S to T
Move disk 1 from D to T
Move disk 2 from D to S
Move disk 1 from T to S
Move disk 3 from D to T
Move disk 1 from S to D
Move disk 2 from S to T
Move disk 1 from D to T
Move disk 5 from S to D
Move disk 1 from T to S
Move disk 2 from T to D
Move disk 1 from S to D
Move disk 3 from T to S
Move disk 1 from D to T
Move disk 2 from D to S
Move disk 1 from T to S
Move disk 4 from T to D
Move disk 1 from S to D
Move disk 2 from S to T
Move disk 1 from D to T
Move disk 3 from S to D
Move disk 1 from T to S
Move disk 2 from T to D
Move disk 1 from S to D
