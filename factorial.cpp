#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int arr[100001];
    arr[0] = 1;
    arr[1] = 1;
    for(int i = 2; i < 100001; i++)
    {
        arr[i] = (arr[i - 1] * i) % (1000000000 + 7);
    }
    long long int T, N;
    cin >> T;
    while(T--)
    {
        cin >> N;
        cout << arr[N] << "\n";
    }
    return  0;
}
