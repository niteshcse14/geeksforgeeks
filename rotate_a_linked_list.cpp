#include <bits/stdc++.h>
using namespace std;
struct LinkedList
{
	struct LinkedList *next;
	int data;
};
/*
struct LinkedList *newNode(int data)
{
	struct LinkedList *new_node = (struct LinkedList*)malloc(sizeof(struct LinkedList));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}
*/
void insert(struct LinkedList **head, int data)
{
	struct LinkedList *new_node = (struct LinkedList*)malloc(sizeof(struct LinkedList));
	new_node->data = data;
	new_node->next = *head;
	*head = new_node;
}
void append(struct LinkedList **head, int data)
{
	struct LinkedList *temp = NULL, *new_node = (struct LinkedList*)malloc(sizeof(struct LinkedList));
	new_node->data = data;
	new_node->next = NULL;
	temp = *head;
	if(*head == NULL)
	{
		*head = new_node;
		return;
	}
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new_node;
	return;
}
void display(struct LinkedList *head)
{
	if(head == NULL)
	{
		return;
	}
	printf("%d ", head->data);
	display(head->next);
}
int main()
{
	int N, data;
	cin >> N;
	struct LinkedList *arr = NULL;
	for(int i = 0; i < N; i++)
	{
		cin >> data;
		insert(&arr, data);
	}
	printf("Data\n");
	display(arr);
	printf("\n");
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> data;
		append(&arr, data);
	}
	printf("Data\n");
	display(arr);
	printf("\n");
	return 0;
}