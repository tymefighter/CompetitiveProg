#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	string s;
	int flag;

	while(cin>>s)
	{
		if(s == "#")
			break;

		flag = next_permutation(s.begin(), s.end());

		if(flag == 0)
			cout<<"No Successor\n";
		else
			cout<<s<<'\n';
	}

	return 0;
}
