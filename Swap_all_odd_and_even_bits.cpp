#include <bits/stdc++.h>
using namespace std;
unsigned int swap_odd_even_bits(unsigned int x)
{
	unsigned int even = x & 0xAAAAAAAA;
	unsigned int odd = x & 0x55555555;
	even >>= 1;                                     
	odd <<= 1;
	return (even | odd);
}
int main()
{
	unsigned int N;
	scanf("%u", &N);
	printf("%u\n", swap_odd_even_bits(N));
	return 0;
}