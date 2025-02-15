#include<stdio.h>
// Printing of sorted Array
void Print_Arry(int A[],int n){
	for(int i=0;i<n;i++){
		printf("%d ",A[i]);
	}
	printf("\n");
}
void Insertion_Sort(int A[],int n){
	int Key;
	for(int i=1;i<n;i++){
		Key = A[i];// Store element in unsorted array
		int j=i-1;// access the left part
		while(j>=0 && Key<A[j]){// check if j does not goes <0 and key is less than its left one 
				A[j+1]=A[j];// move element to right
			j--;// decrement of j
		}
	   A[j+1]=Key;// placing it at correct position
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	int A[n];
	for(int i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	// Function call for insertion sort
    Insertion_Sort(A,n);// Time complexity is O(n^2)
    Print_Arry(A,n);// Printing array
}