#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s = "Hello NIT";
    vector<string> elems;
    stringstream ss(s);
    string item;
    char delim = ' ';
    while (getline(ss, item, delim))
    {
    	cout << item << "\n";
        elems.push_back(item);
    }
    /*
	string sentence = "And I feel fine...";
    istringstream iss(sentence);
    copy(istream_iterator<string>(iss), istream_iterator<string>(), ostream_iterator<string>(cout, "\n"));
	*/
	/*
    string s("Somewhere down the road");
    istringstream iss(s);
    do
    {
        string sub;
        iss >> sub;
        cout << sub << endl;
    } while (iss);
    */
}