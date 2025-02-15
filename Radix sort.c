#include<stdio.h>
// helper function to get the maximum of the array
int get_max(int A[], int n) {
	int mx = A[0];
	for (int i = 1; i < n; i++) {
		if (A[i] > mx) mx = A[i];
	}
	return mx;
}
// helper function to print the array elements
void print_array(int A[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", A[i]);
	}
}
void radix_sort(int A[], int n) {
	int m = get_max(A, n);
	// 2-Dimensional array with 10 rows and n columns
	int buckets[10][n];
	while (m)// runs  upto digits in max element
	{
		int e = 1;
		int count[10] = {0};
		// Segregation of numbers into buckets
		for (int i = 0; i < n; i++)
		{
			int pos = (A[i]/e)%10; // extract digits 
			buckets[pos][count[pos]]= A[i];// adding to buckets by the digit position
			count[pos]++;// increment the position count
		}
		// Reconstruction
		int c = 0;
		for(int i = 0;i<10;i++)// last digits 
		{
			for(int j=0;j<count[i];j++)// for arranging the numbers in order upto their position count
			{
				A[c] = buckets[i][j];// arranging the array elememts from bucket
				c++;
			}
		}
		e *= 10;// to extract digits at tens place,hundreds place etcc...
		m /= 10;// dividing the max element by 10	
	}
}
int main() {
	int n;
	scanf("%d", &n);
	int A[n];
	for (int i = 0; i < n; i++) scanf("%d", &A[i]);
//	printf("Before Sorting: ");
//	print_array(A, n);
	// Function call to radix_sort() function goes here
	radix_sort(A, n);// Time complexity is O(n)*O(no of digits in max element)
	print_array(A, n);
	return 0;	
}