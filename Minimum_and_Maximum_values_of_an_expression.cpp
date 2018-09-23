#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int t;
string str;
void solve(){
    vector<int>num;
    vector<char>exp;
    string temp;
    for(int i=0;i<str.size();++i){
        if(str[i]=='+'||str[i]=='*'){
            exp.pb(str[i]);
            num.pb(atoi(temp.c_str()));
            temp="";
        }
        else temp+=str[i];
    }
    num.pb(atoi(temp.c_str()));
    int len=num.size();
    int mn_dp[len][len],mx_dp[len][len];
    for(int i=0;i<len;++i){
        for(int j=0;j<len;++j){
            mx_dp[i][j]=0;
            mn_dp[i][j]=INT_MAX;
            if(i==j)
                mn_dp[i][j]=mx_dp[i][j]=num[i];
        }
    }
    for(int l=2;l<=len;++l){
        for(int i=0;i<len-l+1;++i){
            int j=i+l-1;
            for(int k=i;k<j;++k){
                int mx=0,mn=0;
                if(exp[k]=='+'){
                    mn=mn_dp[i][k]+mn_dp[k+1][j];
                    mx=mx_dp[i][k]+mx_dp[k+1][j];
                }
                else if(exp[k]=='*'){
                    mn=mn_dp[i][k]*mn_dp[k+1][j];
                    mx=mx_dp[i][k]*mx_dp[k+1][j];
                }
                if(mn<mn_dp[i][j])mn_dp[i][j]=mn;
                if(mx>mx_dp[i][j])mx_dp[i][j]=mx;
            }
        }
    }
    printf("%d %d\n",mn_dp[0][len-1],mx_dp[0][len-1]);
}
int main(){
    scanf("%d",&t);
    while(t--){
        cin>>str;
        solve();
    }
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
bool isOperator(char op){
    return (op == '+' || op == '*');
}
void printMinAndMaxValueOfExp(string exp){
    vector<int> num;
    vector<char> opr;
    string tmp = "";
 
    //  store operator and numbers in different vectors
    for (int i = 0; i < exp.length(); i++)
    {
        if (isOperator(exp[i]))
        {
            opr.push_back(exp[i]);
            num.push_back(atoi(tmp.c_str()));
            tmp = "";
        }
        else
        {
            tmp += exp[i];
        }
    }
    //  storing last number in vector
    num.push_back(atoi(tmp.c_str()));
 
    int len = num.size();
    int minVal[len][len];
    int maxVal[len][len];
 
    //  initializing minval and maxval 2D array
    for (int i = 0; i < len; i++){
        for (int j = 0; j < len; j++){
            minVal[i][j] = INT_MAX;
            maxVal[i][j] = 0;
            if (i == j)
                minVal[i][j] = maxVal[i][j] = num[i];
        }
    }
    for (int L = 2; L <= len; L++){
        for (int i=0;i<len-L+1;i++){
            int j = i + L - 1;
            for (int k=i;k<j;k++){
                int minTmp = 0, maxTmp = 0;
                if(opr[k] == '+'){
                    minTmp = minVal[i][k] + minVal[k + 1][j];
                    maxTmp = maxVal[i][k] + maxVal[k + 1][j];
                }
                else if(opr[k] == '*'){
                    minTmp = minVal[i][k] * minVal[k + 1][j];
                    maxTmp = maxVal[i][k] * maxVal[k + 1][j];
                }
                if (minTmp < minVal[i][j])
                    minVal[i][j] = minTmp;
                if (maxTmp > maxVal[i][j])
                    maxVal[i][j] = maxTmp;
            }
        }
    }
    cout << "Minimum value : " << minVal[0][len - 1]
         << ", Maximum value : " << maxVal[0][len - 1];
}
int main(){
    string expression = "1+2*3+4*5";
    printMinAndMaxValueOfExp(expression);
    return 0;
}
*/