#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<int> a;
int n;


void read()
{
	string s;
	char c;

	a.clear();
	cin>>n>>s>>c;
	
	for(int i = 0;i < n;i++)
	{
		if(s[i] == c)
		{
			a.push_back(i);
			//cout<<i<<" ";
		}
	}
	
	return;
}

long int solve()
{

	if(a.size() == 0)
		return 0;


	int i, curr, next;
	long int ans;
	ans = curr = next = 0;

	for(i = 0;i < a.size()-1;i++)
	{
		curr = a[i];
		next = a[i+1];

		ans += 1ll*(curr + (next - curr - 1) + (1ll*curr * 1ll*(next - curr - 1)) + 1);
	}
	
	curr = a[a.size()-1];
	ans += 1ll*(curr + (n - curr - 1) + (1ll*curr * 1ll*(n - curr - 1)) + 1);


	return ans;
}

int main()
{
	int t;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>t;
	while(t--)
	{
		read();
		cout<<solve()<<'\n';
	}

	return 0;
}
