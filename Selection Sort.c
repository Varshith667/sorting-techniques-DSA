
#include<stdio.h>
// Selection sort basically moves minumum value to the starting of the index
void SelectionSort(int A[],int n)
{
    for(int i=0;i<n-1;i++)// outer loop starts from o to n-2
    {
    	// Assuming i(idx) is min
        int min_ind=i;
        for(int j=i+1;j<n;j++)
        {
            if(A[j]<A[min_ind])// finding min value than the assumed one
            {
                min_ind=j;
            }
        }
        // Swapping of minumum value to front 
        int temp=A[i];
        A[i]=A[min_ind];
        A[min_ind]=temp;
    }
}
int main()
{
    int n; 
    scanf("%d",&n);
    int A[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    // Function Call for selection sort
    SelectionSort(A,n);// Time complexity is O(n^2)
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);// printing sorted array
    }
    return 0;
}
