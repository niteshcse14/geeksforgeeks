#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int arr[maxn];
void heapify(int n, int i){
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if(l < n && arr[l] > arr[largest]){
		largest = l;
	}
	if(r < n && arr[r] > arr[largest]){
		largest = r;
	}
	printf("%d  %d\n", i, largest);
	if(largest != i){
		printf("\t\t\n");
		swap(arr[i], arr[largest]);
		for(int i = 0; i < n; ++i){
		printf("%d  ", arr[i]);
	}
	printf("\n");
		heapify(n, largest);
	}
}
void heap_sort(int n){
	for(int i = n / 2 - 1; i >= 0; --i){
		heapify(n, i);
	}
	for(int i = 0; i < n; ++i){
		printf("%d  ", arr[i]);
	}
	printf("\n");
	for(int i = n - 1; i >= 0; --i){
		swap(arr[0], arr[i]);
		printf("AT %d\t", i);
		heapify(i, 0);
		for(int j = 0; j < n; ++j){
		printf("%d  ", arr[j]);
	}
	printf("\n");
	}
	for(int i = 0; i < n; ++i){
		printf("%d  ", arr[i]);
	}
	printf("\n");
}
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%d", &arr[i]);
	}
	heap_sort(n);
	return 0;
}