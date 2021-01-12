#include <stdio.h> 
  
// C recursive function to solve tower of hanoi puzzle 
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) 
{ 
    if (n == 1) 
    { 
        printf("\n 1- Move disk 1 from rod %c to rod %c", from_rod, to_rod); 
        return; 
    } 
    printf("\n I-towerOfHanoi(%d,%c,%c,%c)",n-1, from_rod, aux_rod, to_rod);
    towerOfHanoi(n-1, from_rod, aux_rod, to_rod); 
    printf("\nI-returned");
    printf("\n 2- Move disk %d from rod %c to rod %c", n, from_rod, to_rod);
	printf("\n II-towerOfHanoi(%d,%c,%c,%c)",n-1, aux_rod, to_rod, from_rod); 
    towerOfHanoi(n-1, aux_rod, to_rod, from_rod); 
    printf("\nII-returned");
} 
  
int main() 
{ 
    int n = 3; // Number of disks 
    printf("\n from main-towerOfHanoi(%d,%c,%c,%c)",n, 'A', 'C', 'B');
    towerOfHanoi(n, 'A', 'C', 'B');  // A, B and C are names of rods
    printf("\nto main-returned");
    return 0; 
}
