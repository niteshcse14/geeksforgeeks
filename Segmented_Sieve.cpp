#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    vector<int> vect(100000, 1);
    for (int i = 2; i * i < vect.size(); ++i)
    {
        if (vect[i])
        {
            for (int j = i * i; j < vect.size(); j += i) 
            {
                vect[j] = 0;
            }
        }
    }
    int l, r;
    cin >> l >> r;
    vector<int> prime(r - l + 1, 1);
    if (l == 1) 
    {
        prime[0] = 0;
    }
    for (int i = 2; i < vect.size(); ++i) 
    {
        if (vect[i]) 
        {
            for (int j = max(i, (l + i - 1) / i * i); j <= r; j += i) 
            {
                if (j != i) 
                {
                    prime[j - l] = 0;
                }
            }
        }
    }
    int c = 0;
    for (int i = 0; i + 2 < prime.size(); ++i) 
    {
        if (prime[i] && prime[i+2]) 
        {
            ++c;
        }
    }
    cout << c << endl;
    return 0;
}