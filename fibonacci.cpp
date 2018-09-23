#include <bits/stdc++.h>
using namespace std;
void multiply(int F[2][2], int M[2][2])
{
     int x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
     int y = F[0][0] * M[1][0] + F[0][1] * M[1][1];
     int z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
     int w = F[1][0] * M[1][0] + F[1][1] * M[1][1];
     F[0][0] = x;
     F[0][1] = y;
     F[1][0] = z;
     F[1][1] = w;
}
void power(int F[2][2] , int N)
{
    int M[2][2] = {{1, 1}, {1, 0}};
    if(N == 0 || N == 1)
    {
        return;
    }
    power(F, N / 2);
    multiply(F, F);
    if(N % 2 != 0)
    {
        multiply(F, M);
    }
}
int fib(int N)
{
    int F[2][2] = {{1, 1}, {1, 0}};
    if(N == 0)
    {
        return 0;
    }
    power(F, N + 1);
    return F[0][0];
}
int main()
{
    int T, N;
    cin >> T;
    while(T--)
    {
        cin >> N;
        cout << fib(N) << "\n";
    }
}
