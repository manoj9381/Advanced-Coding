#include<stdio.h>
#define row1 3  
#define col1 3  
void printMatrixDiagonallyDown(int matrix[row1][col1],int n) 
{ 
    int k,j;
	// printing elements above and on  
    // second diagonal 
    for ( k = 0; k < n; k++) { 
//  		printf("k iteration-> %d\n",k);
        // traversing downwards starting 
        // from first row 
        int row = 0, col = k; 
        while (col >= 0) { 
            printf("\tm[%d][%d]=%d\t",row,col,matrix[row][col]); 
            row++, col--; 
        } 
        printf("\n");
    } 
  
    // printing elements below second 
    // diagonal 
    for (j = 1; j < n; j++) { 
//  		printf("j iteration-> %d\n",j);
        // traversing downwards starting  
        // from last column 
        int col = n - 1, row = j; 
        while (row < n) { 
            printf("\tm[%d][%d]=%d\t",row,col,matrix[row][col]); 
            row++, col--; 
        } 
         printf("\n");
    } 
} 
  
int main() 
{ 
    int matrix[row1][col1] ={ { 1, 2, 3 }, 
                                 { 4, 5, 6 }, 
                                 { 7, 8, 9 } }; 
    int n = 3; 
    printMatrixDiagonallyDown(matrix, n); 
    return 0; 
} 
