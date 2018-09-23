#include<stdio.h>

int num_of_bit_required(int n)

{

int i=1,count=0;

while(i<=n)

{

i=i<<1;

count++;

}

return count;

}

int Pow(int TWO,int M)

{

int Product=1,i;

for(i=0;i<M;i++)

{

Product=Product * TWO;

}

return Product;

}

int main()

{

int i,N, ARR[10],No_of_subarray,nobr,FLAG=1,j=0,KEY;

printf("Enter array size");

scanf("%d", &N);

printf("Enter Elements of array");

for(i=0;i<N;i++)

{

scanf("%d", &ARR[i]);

}

No_of_subarray=(Pow(2,N)-1);

nobr = num_of_bit_required(No_of_subarray);

for(KEY=0;KEY<=No_of_subarray;KEY++)

{

j=0;

FLAG=1;

while(j<nobr)

{

if((FLAG & KEY) != 0)

{

printf(" %d", ARR[(nobr-1)-j]);

}

FLAG = FLAG << 1;

j++;

}

printf("\n");

}

return 0;

}