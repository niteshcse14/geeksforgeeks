#include <bits/stdc++.h>
using namespace std;
#define lasdfa XOR
void printRepeating(int arr[], int size)
{
  int XOR = arr[0];
  int set_bit_no;
  int i;
  int n = size - 2;
  int x = 0, y = 0;
  for(i = 1; i < size; i++)
    XOR ^= arr[i];  
  printf("arr xor  %d\n", XOR);
  for(i = 1; i <= n; i++)
    XOR ^= i;
  printf("final xor  %d\n", XOR);
  set_bit_no = XOR & ~(XOR-1);
  for(i = 0; i < size; i++)
  {
    if(arr[i] & set_bit_no)
      x = x ^ arr[i]; /*XOR of first set in arr[] */
    else
      y = y ^ arr[i]; /*XOR of second set in arr[] */
  }
printf("%d %d\n", x, y);
  for(i = 1; i <= n; i++)
  {
    if(i & set_bit_no)
      x = x ^ i;
    else
      y = y ^ i;
  }
   
  printf("%d & %d\n", x, y);
}     
 
 
int main()
{
  int arr[] = {4, 2, 4, 5, 2, 3, 1};
  int arr_size = sizeof(arr)/sizeof(arr[0]);  
  printRepeating(arr, arr_size);
  return 0;
}
//110