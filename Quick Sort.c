#include<stdio.h>
int Partition(int A[],int key,int strt,int end){
	int s=strt;
	int e=end;
	while(s<e){// runs upto strt less than end
		while(A[s]<=key){// increment strt index upto element > key
			s++;
		}
		while(A[e]>key){// decrement end upto element < key
			e--;
		}
		if(s<e){
			int temp = A[s];// swaping the element at strt index and end index
			A[s]=A[e];
			A[e]=temp;
		}
	}
	int temp = A[e];
	A[e]=key;// key is swaped to end index
	A[strt]=temp;// swap last element to start index
	return e;// return key index
}
void Quick_Sort(int A[],int n,int strt,int end){
	if(strt < end){
		// key to divide the array to 2 parts
		int p=A[strt];// key be strting index
		p=Partition(A,p,strt,end);
		// from 0 to p(index) 
		Quick_Sort(A,n,strt,p);
		// from p+1(index) to end
		Quick_Sort(A,n,p+1,end);
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
	// Function call 
	Quick_Sort(A,n,0,n-1);// time complexity is O(n)*log2(n)(Avgerage),O(n^2)(Worst Case)
	for(int i=0;i<n;i++){
		printf("%d ",A[i]);// Printing sorted array
	}
}