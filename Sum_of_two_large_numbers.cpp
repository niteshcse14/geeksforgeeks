#include <bits/stdc++.h>
using namespace std;
void sum(string str1, string str2){
	if(str1.length() > str2.length()){
		swap(str1, str2);
	}
	string str = " ";
	int n1 = str1.length();
	int n2 = str2.length();
	int carry = 0, diff = n2 - n1;
	for(int i = n1 - 1; i >= 0; --i){
		int sum = ((str1[i] - '0') + (str2[i + diff] - '0') + carry);
		str.push_back(sum % 10 + '0');
		carry = sum / 10;
	}
	for(int i = n2 - n1 - 1; i >= 0; --i){
		int sum = ((str2[i] - '0') + carry);
		str.push_back(sum % 10 + '0');
		carry = sum / 10;
	}
	if(carry){
		str.push_back(carry + '0');
	}
	reverse(str.begin(), str.end());
	//cout << str << "\n";
	for(int i = 0; i < str.length(); ++i){
		cout << str[i] << " ";
	}
	printf("\n");
}
int main(){
	int t, data, n, m;
	scanf("%d", &t);
	while(t--){
		string str1 = "", str2 = "";
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; ++i){
			scanf("%d", &data);
			str1 += (data + '0');
		}
		for(int i = 0; i < m; ++i){
			scanf("%d", &data);
			str2 += (data + '0');
		}
		sum(str1, str2);
	}
	return 0;
}