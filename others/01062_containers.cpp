#include<iostream>
#include<cstdio>
#include<string>
#include<vector>

using namespace std;
///Unsolved !!

int solve(const string &s)
{
	stack_top[0] = s[0];


}

int main()
{
	int i;
	vector<char> stack_top;
	vector<bool> seen;
	stack_top.assign(26, '1');

	while(getline(cin, s))
	{
		if(s == "end")
			break;

		cout<<solve(s, stack_top)<<'\n';

		for(i = 0;i < 26;i++)
		{
			stack_top[i] = '1';
		}
	}

	return 0;
}
