#include <bits/stdc++.h>
using namespace std;
struct Trie_Node
{
	struct Trie_Node *children[26];
	bool is_leaf;
};
struct Trie_Node *getNode()
{
	Trie_Node *temp = new Trie_Node;//(struct Trie_Node*)malloc(sizeof(struct Trie_Node));
	temp->is_leaf = false;
	for(int i = 0; i < 26; i++)
	{
		temp->children[i] = NULL;
	}
	return temp;
}
void insert(Trie_Node *root, string str)
{
	int len = str.size();
	Trie_Node *temp = root;
	for(int i = 0; i < len; i++)
	{
		int ind = str[i] - 'a';
		if(temp->children[ind] == NULL)
		{
			temp->children[ind] = getNode();
		}
		temp = temp->children[ind];
	}
	temp->is_leaf = true;
}
bool search(Trie_Node *root, string str)
{
	int len = str.size();
	Trie_Node *temp = root;
	for(int i = 0; i < len; i++)
	{
		int ind = str[i] - 'a';
		if(temp->children[ind] == NULL)
		{
			return false;
		}
		temp = temp->children[ind];
	}
	return (temp != NULL && temp->is_leaf);
}
int main()
{
	string key[8] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
    string output[2] = {"Not present in trie", "Present in trie"};
    Trie_Node *root = getNode();
    int i;
    for (i = 0; i < 8; i++)
    {
        insert(root, key[i]);
    }
    cout << "the  " << output[search(root, "the")] << "\n";
    cout << "these  " << output[search(root, "these")] << "\n";
    cout << "their  " << output[search(root, "their")] << "\n";
    cout << "thaw  " << output[search(root, "thaw")] << "\n"; 
	return 0;
}