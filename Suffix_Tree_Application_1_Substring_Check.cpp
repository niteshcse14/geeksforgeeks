#include <bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 256;
struct suffixTreeNode{
	suffixTreeNode *children[MAX_CHAR];
	int start;
	int *end;
	suffixTreeNode *suffixLink;
	int suffixIndex;
};
typedef suffixTreeNode node;
node *root = NULL;
node *ActiveNode = NULL;
int ActiveLength = 0;
int ActiveEdge = -1;
int size = -1;
int leafEnd = -1;
int remainingSuffix = 0;
node *lastNewNode = NULL;
int *rootEnd = NULL;
int *splitEnd = NULL;
char text[1000];
node *newNode(int start, int *end){
	node *temp = (node *)malloc(sizeof(node));
	for(int i = 0; i < MAX_CHAR; ++i){
		temp->children[i] = NULL;
	}
	temp->start = start;
	temp->end = end;
	temp->suffixIndex = -1;
	temp->suffixLink = root;
	return temp;
}
int edgeLength(node *n){
	if(n == root){
		return 0;
	}
	return *(n->end) - (n->start) + 1;
}
int walkDown(node *n){
	if(ActiveLength >= edgeLength(n)){
		ActiveLength -= edgeLength(n);
		ActiveEdge += edgeLength(n);
		ActiveNode = n;
		return 1;
	}
	return 0;
}
void extend_suffix_tree(int pos){
	leafEnd = pos;
	remainingSuffix++;
	lastNewNode = NULL;
	while(remainingSuffix > 0){
		if(ActiveLength == 0){
			ActiveEdge = pos;
		}
		if(ActiveNode->children[text[ActiveEdge]] == NULL){
			ActiveNode->children[text[ActiveEdge]] = newNode(pos, &leafEnd);
			if(lastNewNode != NULL){
				lastNewNode->suffixLink = ActiveNode;
				lastNewNode = NULL;
			}
		}
		else{
			node *next = ActiveNode->children[text[ActiveEdge]];
			if(walkDown(next)){
				continue;
			}
			if(text[next->start + ActiveLength] == text[pos]){
				if(lastNewNode != NULL && ActiveNode != root){
					lastNewNode->suffixLink = ActiveNode;
					lastNewNode = NULL;					
				}
				ActiveLength++;
				break;
			}
			splitEnd = (int *)malloc(sizeof(int));
			*splitEnd = next->start + ActiveLength - 1;
			node *split = newNode(next->start, splitEnd);
			ActiveNode->children[text[ActiveEdge]] = split;
			split->children[text[pos]] = newNode(pos, &leafEnd);
			next->start += ActiveLength;
			split->children[text[next->start]] = next;
			if(lastNewNode != NULL){
				lastNewNode->suffixLink = split;
			}
			lastNewNode = split;
		}
		remainingSuffix--;
		if(ActiveNode == root && ActiveLength > 0){
			ActiveLength--;
			ActiveEdge = pos - remainingSuffix + 1;
		}
		else if(ActiveNode != root){
			ActiveNode = ActiveNode->suffixLink;
		}
	}
}
void setSuffixIndexByDFS(node *n, int labelHeight){
	if(n == NULL){
		return;
	}
	int leaf = 1;
	for(int i = 0; i < MAX_CHAR; ++i){
		if(n->children[i] != NULL){
			leaf = 0;
			setSuffixIndexByDFS(n->children[i], labelHeight + edgeLength(n->children[i]));
		}
	}
	if(leaf == 1){
		n->suffixIndex = size - labelHeight;
		//printf(" [%d]\n", n->suffixIndex);
	}
}
void freeSuffixByPostOrder(node *n){
	if(n == NULL){
		return;
	}
	for(int i = 0; i < MAX_CHAR; ++i){
		if(n->children[i] != NULL){
			freeSuffixByPostOrder(n->children[i]);
		}
	}
	if(n->suffixIndex == -1){
		free(n->end);
	}
	free(n);
}
void buildSuffixTree(){
	size = strlen(text);
	rootEnd = (int *)malloc(sizeof(int));
	*rootEnd = - 1;
	root = newNode(-1, rootEnd);
	ActiveNode = root;
	for(int i = 0; i < size; ++i){
		extend_suffix_tree(i);
	}
	int labelHeight = 0;
	setSuffixIndexByDFS(root, labelHeight);
}
int traverseEdge(char *str, int idx, int start, int end){
	for(int i = start; str[idx] != '\0' && i <= end; i++, idx++)
	{
		if(text[i] != str[idx]){
			return -1;
		}
	}
	if(str[idx] == '\0'){
		return 1;
	}
	return 0;
}
int doTraversal(node *n, char *str, int idx){
	if(n == NULL){
		return -1;
	}
	int res = -1;
	if(n->start != -1){
		res = traverseEdge(str, idx, n->start, *(n->end));
		if(res != 0){
			return res;
		}
	}
	idx = idx + edgeLength(n);
	if(n->children[str[idx]] != NULL){
		return doTraversal(n->children[str[idx]], str, idx);
	}
	else{
		return -1;
	}
}
void checkForSubString(char *str){
	int res = doTraversal(root, str, 0);
	if(res == 1)
        printf("Pattern <%s> is a Substring\n", str);
    else
        printf("Pattern <%s> is NOT a Substring\n", str);
}
int main(){
	strcpy(text, "THIS IS A TEST TEXT$"); 
    buildSuffixTree();  
 	char str[1000];
 	int i = 10;
 	while(i--){
 		scanf("%s", str);
    	checkForSubString(str);
    }
    //checkForSubString("A");
    //checkForSubString(" ");
   // checkForSubString("IS A");
  //  checkForSubString(" IS A ");
 //   checkForSubString("TEST1");
   // checkForSubString("THIS IS GOOD");
   // checkForSubString("TES");
   // checkForSubString("TESA");
   // freeSuffixByPostOrder(root);
	return 0;
}