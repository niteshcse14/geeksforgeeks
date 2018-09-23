#include <bits/stdc++.h>
using namespace std;
int modInverse(int a, int m)
{
    int x0 = 0 , x1 = 1 , m0 = m, q, t;
    if(m == 1)
    {
        return 0;
    }
    while(a > 1)
    {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if(x1 < 0)
    {
        x1 += m0;
    }
    return x1;
}
int main()
{
    int T , N, M;
    cin >> T;
    while(T--)
    {
        cin >> N >> M;
        cout << modInverse(N, M) << "\n";
    }
    return 0;
}
