#include <bits/stdc++.h>
using namespace std;
class A{
private:
	unsigned short w;
	unsigned char b[2];
public:
	unsigned short &word() {return w;}
	unsigned char &lowByte() {return b[0];}
	unsigned char &highByte() {return b[1];}
};
int main() {
	A wb;
	wb.word() = 256;
	cout << wb.word() << "\n";
	cout << wb.lowByte() << "\n";
	cout << wb.highByte() << "\n";
	return 0;
}