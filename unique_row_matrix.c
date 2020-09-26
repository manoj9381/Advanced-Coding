#include<stdio.h>
#define ROW 4  
#define COL 5  
  
// The main function that prints  
// all unique rows in a given matrix. 
void findUniqueRows(int M[ROW][COL]) 
{ 
    int i,j,k;
    //Traverse through the matrix 
    for( i=0; i<ROW; i++) 
    { 
        int flag=0; 
//		printf("row i->%d\n",i);  
        //check if there is similar column is already printed, i.e if i and jth column match.
		for(j=0; j<i; j++) 
        { 
            flag=1; 
//            printf("j iteration->%d\n",j); 
            for(k=0; k<COL; k++) 
            {
//				printf("k iteration->%d\n",k);
            	if(M[i][k]!=M[j][k]) 
            	{
//            		printf("\tif(m[%d][%d]!=m[%d][%d]) i.e if(%d!=%d) then flag=0 loop break\n",i,k,j,k,M[i][k],M[j][k]);
                	flag=0; break;
           		}
           		else{
//           		printf("\t\t if(m[%d][%d]==m[%d][%d]) i.e if(%d==%d) \n",i,k,j,k,M[i][k],M[j][k]);
				}
		   	}
            if(flag==1)
			{
//			printf("flag=1 break j loop\n");
			break;
        	}
//        	printf("j<i => %d<%d is %d\n",j,i,j<i);
        } 
          
        //if no row is similar 
        if(flag==0) 
        { 
            //print the row 
            for(j=0; j<COL; j++) 
                printf("%d",M[i][j]); 
            printf("\n");
        } 
    } 
} 
  
// Driver Code 
int main()  
{  
    int M[ROW][COL] = {{0, 1, 0, 0, 1},  
                       {1, 0, 1, 1, 0},  
                       {0, 1, 0, 0, 1},  
                       {1, 0, 1, 0, 0}};  
  
    findUniqueRows(M);  
  
    return 0;  
}  
