#include <stdio.h>
#include <limits.h>     /*The macros defined in this header 
                          limits the values of various variable
                          types like char, int and long.*/


int main()
{

    int arr[20];
    int a, i;

    printf("enter the number of matrices u want to multiply : ");
    scanf("%d",&a);
    for(i=0; i<= a; i++ ){
        printf("enter the order of P%d : ", i);
        scanf("%d", &arr[i]);
        printf("\n");
    }
    // int size = sizeof(arr)/sizeof(arr[0]);
    int size = a+1;
    printf("%s%d\n", "the size of SIZE is : ",size);
 
    printf("Minimum number of multiplications for m[1,%d] is %d \n",a,MatrixChainOrder(arr, size));
 
    return 0;
}

// Matrix Ai has dimension p[i-1] x p[i] for i = 1..n
int MatrixChainOrder(int p[], int n)
{
 
    int m[n][n];
 
    int i, j, k, L, q;
 
    // cost is zero when multiplying one matrix.
    for (i = 1; i < n; i++)
        m[i][i] = 0;
 
    // L is chain length.  
    for (L=2; L<n; L++)   
    {
        for (i=1; i<=n-L+1; i++)
        {
            j = i+L-1;
            m[i][j] = INT_MAX;          //INT_MAX is the maximum value for an object of type int.
            for (k=i; k<=j-1; k++)
            {
                // q = cost/scalar multiplications
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }
 
    return m[1][n-1];
}