#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T, N, flag  = 0;
    cin >> T;
    while(T--)
    {
        flag = 0;
        cin >> N;
        for(int i = 31 ; i >= 0; i--)
        {
            if(((1 << i) & N) > 0)
            {
                cout << "1";
                flag = 1;
            }
            else if(flag == 1)
            {
                cout << "0";
            }
        }
        cout << "\n";
        /*
        if((N & (N - 1)) == 0)
        {
            cout << "Square of 2\n";
        }
        else
        {
            cout << "Not Square\n";
        }
        */
    }
    return 0;
}
