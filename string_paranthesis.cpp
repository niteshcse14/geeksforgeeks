#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> en;
    int go(int lo, int hi) {
        if(lo+1 == hi) return 1;
        int mid = en[lo];
        if(mid == hi) return 2*go(lo+1, hi-1);
        return go(lo, mid) + go(mid+1, hi);
    }
    int scoreOfParentheses(string &S) {
        int i, n = (int)S.size();
        n = max(n, 1);
        en.resize(n, 0);
        stack<int> s;
        for(i=0; i<n; i++){
            if(S[i] == ')'){
                int t = s.top();
                en[t] = i;
                s.pop();
            }
            else s.push(i);
        }
        return go(0, n-1);
    }
};
int main() {
    return 0;
}
/*
(()(()))
en (1, 2) (4, 5) (3, 6) (0, 7)
*/
echo "# geeksforgeeks" >> README.md
git init
git add README.md
git add *.cpp
git add *.py
git add *.java
git commit -m "geeksforgeeks"
git remote add origin https://github.com/wigglebuggy/geeksforgeeks.git
git push -u origin master