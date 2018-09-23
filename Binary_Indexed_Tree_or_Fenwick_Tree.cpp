#include <bits/stdc++.h>
using namespace std;
int getSum(int BITree[], int index)
{
	int sum = 0;
	index++;
	while(index > 0)
	{
		sum += BITree[index];
		index -= index & (-index);
	}
	return sum;
}
void updateBIT(int BITree[], int N, int index, int val)
{
	index = index + 1;
	while(index <= N)
	{
		BITree[index] += val;
		index += index & (-index);
	}
}
int *constructBITree(int arr[], int N)
{
	int *BITree = new int[N + 1];
	for(int i = 1; i <= N; i++)
	{
		BITree[i] = 0;
	}
	for(int i = 0; i < N; i++)
	{
		updateBIT(BITree, N, i, arr[i]);
	}
	return BITree;
}
int main()
{
	//int N = 12;
	//cin >> N;
	int arr[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
	int N = sizeof(arr) / sizeof(arr[0]);
	/*
	for(int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	*/
	int *BITree = constructBITree(arr, N);
	for(int i = 1; i <= N; i++)
	{
		cout << BITree[i] << "  ";
	}
	printf("\n");
	cout << getSum(BITree, 5) << "\n";
	arr[3] += 6;
	updateBIT(arr, N, 3, 6);
	for(int i = 1; i <= N; i++)
	{
		cout << BITree[i] << "  ";
	}
	printf("\n");
	cout << getSum(BITree, 5) << "\n";
	return 0;
}
//Binary_Indexed_Tree_or_Fenwick_Tree.cpp