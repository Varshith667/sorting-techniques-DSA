#include<stdio.h>
void Merge(int arr[],int left,int mid,int right,int n){
	// i=Left part starting index, j=Right part starting index
	int i=left,j=mid+1;
	int B[n];
	int k=0;
	// Merge sorted arrays
	while(i<=mid && j<=right){
		if(arr[i]<arr[j]){
			B[k]=arr[i];
			i++;
			k++;
		}
		else{
			B[k]=arr[j];
			k++;
			j++;
		}
	}
	//add remaining elements in left part 
	while(i<=mid){
		B[k]=arr[i];
		k++;
		i++;
	}
	// add remaining elements  in right part
	while(j<=right){
		B[k]=arr[j];
		k++;
		j++;
	}
	k=0;
	// k is taken to add elements as order of indexes in orginal array
	for(int i=left;i<=right;i++){
		arr[i]=B[k];
		k++;
	}
}
void Merge_Sort(int arr[],int n,int left,int right){
	// base case to stop recursion
	if(left>=right){
		return;
	}
	int mid = (left+right)/2;
    // Sorting the left array from left to mid
	Merge_Sort(arr,n,left,mid);
	//  sorting the right array from mid+1 to right
	Merge_Sort(arr,n,mid+1,right);
	// Merging of left part sorted part and right sorted part
	Merge(arr,left,mid,right,n);
}
int main()
{
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
	   scanf("%d",&arr[i]);
	}
	// Function Call
	Merge_Sort(arr,n,0,n-1);// Time complexity is O(n)*log2(n)
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
}