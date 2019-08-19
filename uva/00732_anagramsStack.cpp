#include<iostream>
#include<cstdio>
#include<stack>
#include<string>
#include<vector>
#include<algorithm>


using namespace std;

vector<string> arr;

void solve(const string &a, const string &b, int i, int j, stack<char> &st, stack<char> &curr)
{

	if(st.empty() == true && i == a.size()) //Stack is empty and word has been completely seen
	{
		string s;

		while(curr.empty() == false)
		{
			st.push(curr.top());
			curr.pop();
		}

		while(st.empty() == false)
		{
			s.push_back(st.top());
			curr.push(st.top());
			st.pop();
		}

		arr.push_back(s);
	}
	else if(st.empty()) //Input step
	{
		curr.push('i');
		st.push(a[i]);
		solve(a, b, i+1, j, st, curr);

		st.pop();
		curr.pop();
	}
	else if(i == a.size()) //Output step
	{
		char x = st.top();

		if(x == b[j])
		{
			curr.push('o');
			st.pop();
			solve(a, b, i, j+1, st, curr);

			st.push(x);
			curr.pop();
		}
	}
	else	//Try both
	{
		char x = st.top();

		if(x == b[j])
		{
			curr.push('o');
			st.pop();
			solve(a, b, i, j+1, st, curr);

			st.push(x);
			curr.pop();
		}

		curr.push('i');
		st.push(a[i]);
		solve(a, b, i+1, j, st, curr);
		
		st.pop();
		curr.pop();
	}

	return;
}

int main()
{
	int count = 0;
	string a, b;
	stack<char> st, curr;


	while(getline(cin, a))
	{
		getline(cin, b);

		if(a.size() != b.size())
		{
			cout<<"[\n";
			cout<<"]\n";
			continue;
		}


		arr.clear();
		solve(a, b, 0, 0, st, curr);

		sort(arr.begin(), arr.end());
		
		cout<<"[\n";
		for(auto x : arr)
		{
			count = 0;
			for(char y : x)
			{
				if(count != 0)
					cout<<' ';
				cout<<y;
				count++;
			}
			cout<<'\n';
		}
		cout<<"]\n";
	}

	return 0;
}
