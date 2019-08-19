#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>

using namespace std;

typedef struct Node
{
	int data;
	struct Node *prev, *next;
}Node;

typedef struct List
{
	Node *head;
}List;

Node *createNode(int x)
{
	Node *newNode = new Node;
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;

	return newNode;
}

void createList(int S, List *l, vector<Node *> &a)
{
	int i;
	l->head = createNode(1);
	Node *temp1 = l->head, *temp2 = NULL;

	for(i = 2;i <= S;i++)
	{
		temp2 = createNode(i);
		temp1->next = temp2;
		temp2->prev = temp1;

		temp1 = temp2;
	}

	a.resize(S);

	i = 0;
	temp1 = l->head;

	while(temp1 != NULL)
	{
		a[i] = temp1;
		temp1 = temp1->next;
		i++;
	}

	return;
}

void deallocate(List *l, vector<Node *> a)
{
	l->head = NULL;

	for(int i = 0;i < a.size();i++)
		delete a[i];
	
	return;
}

int main()
{
	int S, B, i, L, R;
	vector<Node *> a;
	List *l = new List;

	while(cin>>S>>B)
	{
		if((S|B) == 0)
			break;

		createList(S, l, a);

		//for(i = 0;i < a.size();i++)
		//	cout<<a[i]->data<<'\n';


		for(i = 0;i < B;i++)
		{
			cin>>L>>R;

			if(a[L-1]->prev == NULL && a[R-1]->next == NULL)
			{
				cout<<"* *\n";
			}
			else if(a[L-1]->prev == NULL)
			{
				(a[R-1]->next)->prev = NULL;

				cout<<"* "<<(a[R-1]->next)->data<<'\n';
			}
			else if(a[R-1]->next == NULL)
			{
				(a[L-1]->prev)->next = NULL;

				cout<<(a[L-1]->prev)->data<<" *\n";
			}
			else
			{
				(a[L-1]->prev)->next = a[R-1]->next;
				(a[R-1]->next)->prev = a[L-1]->prev;

				cout<<(a[L-1]->prev)->data<<" "<<(a[R-1]->next)->data<<'\n';

			}
		}


		cout<<"-\n";

		deallocate(l, a);
	}

	return 0;
}
