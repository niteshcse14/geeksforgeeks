#include <bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 256;
struct SuffixTreeNode{
	struct SuffixTreeNode *children[MAX_CHAR];
	int start;
	int *end;
	struct SuffixTreeNode *suffixLink;
	int suffixIndex;
};
typedef SuffixTreeNode node;
char text[1000];
node *root = NULL;
node *ActiveNode = NULL;
node *lastNewNode = NULL;
int ActiveEdge = -1;
int ActiveLength = 0;
int remainingSuffixCount = 0;
int leafEnd = -1;
int *rootEnd = NULL;
int *splitEnd = NULL;
int size = -1;
node *newNode(int start, int *end){
	node *temp = (node *)malloc(sizeof(node));
	for(int i = 0; i < MAX_CHAR; ++i){
		temp->children[i] = NULL;
	}
	temp->suffixLink = root;
	temp->start = start;
	temp->end = end;
	temp->suffixIndex = -1;
	return temp;
}
int edgeLength(node *curr){
	return *(curr->end) - (curr->start) + 1;
}
int walkDown(node *curr){
	if(ActiveLength >= edgeLength(curr)){
		ActiveEdge += edgeLength(curr);
		ActiveLength -= edgeLength(curr);
		ActiveNode = curr;
		return 1;
	}
	return 0;
}
void ExtendSuffixTree(int pos){
	leafEnd = pos;
	remainingSuffixCount++;
	lastNewNode = NULL;
	while(remainingSuffixCount > 0){
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
			splitEnd = (int*)malloc(sizeof(int));
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
		remainingSuffixCount--;
		if(ActiveNode == root && ActiveLength > 0){
			ActiveLength--;
			ActiveEdge = pos - remainingSuffixCount + 1;
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
	if(n->start != -1){
		for(int j = n->start; j <= *(n->end); ++j){
			printf("%c", text[j]);
		}
	}
	int leaf = 1;
	for(int i = 0; i < MAX_CHAR; ++i){
		if(n->children[i] != NULL){
			if(leaf == 1 && n->start != -1){
				printf("  [%d]\n", n->suffixIndex);
			}
			leaf = 0;
			setSuffixIndexByDFS(n->children[i], labelHeight + edgeLength(n->children[i]));
		}
	}
	if(leaf == 1){
		n->suffixIndex = size - labelHeight;
		printf("  [%d]\n", n->suffixIndex);
	}
}
void freeSuffixTreeByPostOrder(node *n){
	if(n == NULL){
		return;
	}
	for(int i = 0; i < MAX_CHAR; ++i){
		if(n->children[i] != NULL){
			freeSuffixTreeByPostOrder(n->children[i]);
		}
	}
	if(n->suffixIndex == -1){
		free(n->end);
	}
	free(n);
}
void buildSuffixTree(){
	size = strlen(text);
	rootEnd = (int*)malloc(sizeof(int));
	*rootEnd = -1;
	root = newNode(-1, rootEnd);
	ActiveNode = root;
	for(int i = 0; i < size; ++i){
		ExtendSuffixTree(i);
	}
	int labelHeight = 0;
	setSuffixIndexByDFS(root, labelHeight);
	freeSuffixTreeByPostOrder(root);
}
int main(){
	strcpy(text, "abcabxabcd$"); buildSuffixTree();
	return 0;
}