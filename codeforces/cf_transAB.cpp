#include<iostream>
#include<cstdio>
#include<stack>

using namespace std;

stack<long long int> st;

bool solve(long long int a, const long long int &b)
{

	if(a == b)
	{
		st.push(b);
		return true;
	}
	else if(a > b)
		return false;

	if(solve(10*a + 1, b))
	{
		st.push(a);
		return true;
	}
	else if(solve(2*a, b))
	{
		st.push(a);
		return true;
	}

	return false;
}

int main()
{
	long long int a, b;
	cin>>a>>b;

	if(solve(a, b) == false)
		cout<<"NO\n";
	else
	{
		cout<<"YES\n"<<st.size()<<'\n';
		while(st.empty() == false)
		{
			cout<<st.top()<<" ";
			st.pop();
		}
	}
	return 0;
}
