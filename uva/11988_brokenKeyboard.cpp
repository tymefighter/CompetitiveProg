#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<utility>

using namespace std;

typedef struct Node
{
	char data;
	struct Node *next;
}Node;

Node *createNode(char data)
{
	Node *newNode = (Node *)malloc(sizeof(Node));

	newNode->data = data;
	newNode->next = NULL;

	return newNode;
}

void printListDel(Node *temp)
{
	Node *temp2 = NULL;
	while(temp != NULL)
	{
		cout<<temp->data;
		temp2 = temp;
		temp = temp->next;

		free(temp2);
	}

	cout<<'\n';
	return;
}

void printList(Node *temp)
{
	while(temp != NULL)
	{
		cout<<temp->data;
		temp = temp->next;
	}

	cout<<'\n';
	return;
}


pair<Node *, Node *> solve(const string &s)
{
	int i = 0;
	pair<Node *, Node *> p;
	
	Node *head = NULL;
	Node *tail = NULL;
	
	Node *temp_head = NULL;
	Node *temp_tail = NULL;
	while(i < s.size())
	{
		if(s[i] == '[')
		{
			i++;
			temp_head = NULL;
			temp_tail = NULL;

			while(i < s.size() && s[i] != ']')
			{
				if(s[i] == '[')
				{
					if(temp_head != NULL)
					{
					
						if(tail == NULL)
							tail = temp_tail;
					
						temp_tail->next = head;
						head = temp_head;
					}
				
					temp_head = NULL;
					temp_tail = NULL;
				}
				else
				{
					if(temp_head == NULL)
					{
						temp_head = createNode(s[i]);
						temp_tail = temp_head;
					}
					else
					{
						temp_tail->next = createNode(s[i]);
						temp_tail = temp_tail->next;
					}
				}
				
				i++;
			}
			
			if(i == s.size() || s[i] == ']')
			{
				if(temp_head != NULL)
				{
					
					if(tail == NULL)
						tail = temp_tail;
					
					temp_tail->next = head;
					head = temp_head;
				}
			}
		}
		else
		{
			if(s[i] == ']')
			{
				i++;
				continue;
			}
			if(head == NULL)
			{
				head = createNode(s[i]);
				tail = head;
			}
			else
			{
				tail->next = createNode(s[i]);
				tail = tail->next;
			}
			i++;
		}
	}
	
	p.first = head;
	p.second = tail;
	
	return p;
}

int main()
{
	string s;
	pair<Node *, Node *> ans;

	while(cin>>s)
	{
		ans = solve(s);
		printListDel(ans.first);
	}

	return 0;
}
