#include <bits/stdc++.h>
using namespace std;
struct Persistent
{
	struct Persistent *next;
	int data;
};
void insert(struct Persistent **head, int data)
{
	struct Persistent *temp, *new_node = (struct Persistent*)malloc(sizeof(struct Persistent));
	new_node->data = data;
	temp = *head;
	if(temp == NULL)
	{
		*head = new_node;
		return;
	}
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new_node;
}
void connect(struct Persistent **head1, struct Persistent **head2)
{
	struct Persistent *temp1, *temp2;
	temp1 = *head1;
	temp2 = *head2;
	while(temp2->next != NULL) 
	{
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	temp2->next = temp1->next;
}
void display(struct Persistent *head)
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
	int T, N, data;
	cin >> T;
	struct Persistent *arr[100];
	arr[0] = NULL;
	cin >> N;
	for(int j = 0; j < N; j++)
	{
		cin >> data;
		insert(&arr[0], data);
	}
	display(arr[0]);
	printf("\n");
	for(int i = 1; i < T; i++)
	{
		arr[i] = NULL;
		cin >> N;
		for(int j = 0; j < N; j++)
		{
			cin >> data;
			insert(&arr[i], data);
		}
		connect(&arr[i - 1], &arr[i]);
		display(arr[i]);
		printf("\n");
	}
	return 0;
}