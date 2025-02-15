#include<stdio.h>
// Printing of sorted array
void Print(int A[],int n){
	for(int i=0;i<n;i++){
		printf("%d ",A[i]);
	}
}
// Bubble Sort basically moves larger value to last of the array
void Bubble(int A[],int n,int i,int j){
	//Base Case 1 to Return from Outer loop
	if(i>=n){
		return;
	}
	// Base Case 2 to return from inner loop
	if(j>=n){
		return;
	}
	// Swaping of larger numbers to last of the array
    if( j<n-1 && A[j]>A[j+1]){
	 int tmp = A[j];
	 A[j]=A[j+1];
	 A[j+1]=tmp;
}
	// Recursive call for inner loop iteration
	 Bubble(A,n,i,j+1);
	// Recursive call for outer loop iteration
	 Bubble(A,n,i+1,0);
}
int main()
{
	int n;
	scanf("%d",&n);
	int A[n];
	for(int i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	int i=0,j=0;
	// Function for bubble sort
	Bubble(A,n,i,j);// Time complexity is O(n^2)
	//Printing of sorted array
	Print(A,n);
}