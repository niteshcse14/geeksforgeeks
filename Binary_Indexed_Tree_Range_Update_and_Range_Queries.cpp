#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
void update(int BITree[], int N, int index, int val)
{
    index++;
    while(index < N)
    {
        BITree[index] += val;
        index += index & (-index);
    }
}
int getSum(int BITree[], int index)
{
    int sum = 0;
    index++;
    while(index > 0)
    {
        sum += BITree[index];// += val;
        index -= index & (-index);
    }
    return sum;
}
void rangeUpdate(int BITree1[], int BITree2[], int N, int l, int r, int val)
{
    update(BITree1, N, l, val);
    update(BITree1, N, r + 1, -val);
    update(BITree2, N, l, (l - 1) * val);
    update(BITree2, N, r + 1, r * val);
}
int sum(int x, int BITree1[], int BITree2[])
{
    return (getSum(BITree1, x) * x - getSum(BITree2, x));
}
int rangeSum(int BITree1[], int BITree2[], int l, int r)
{
    return (sum(r, BITree1, BITree2) - sum(l - 1, BITree1, BITree2));
}
int main()
{
    int Q, N, l, r, val;
    //scanf("%d %d", &N, &Q);
    N = 5;
    int BITree1[MAXN];
    int BITree2[MAXN];
    memset(BITree1, 0, sizeof(BITree1));
    memset(BITree2, 0, sizeof(BITree2));
    l = 0, r = 4, val = 5;
    rangeUpdate(BITree1, BITree2, N, l, r, val);
    l = 2, r = 4, val = 10;
    rangeUpdate(BITree1, BITree2, N, l, r, val);
    l = 1, r = 4;
    printf("%d\n", rangeSum(BITree1, BITree2, l, r));
    return 0;
}