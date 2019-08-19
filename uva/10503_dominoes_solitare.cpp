#include<iostream>
#include<utility>
#include<vector>

using namespace std;

int n, m;
pair<int, int> leftv, rightv;
vector<pair<int, int> > piece;

void read()
{
	cin>>leftv.first>>leftv.second;
	cin>>rightv.first>>rightv.second;

	piece.clear();
	piece.resize(m);

	for(int i = 0;i < m;i++)
		cin>>piece[i].first>>piece[i].second;
}


bool solve(int pos, int choice, int prev_right)
{
	int i;
	bool flag = false;
	
	if(pos == n+1)
	{
		return true;
	}
	
	for(i = 0;i < m;i++)
	{
		if((piece[i].first == prev_right) && ((choice & (1 << i)) == 0) && (pos != n || (piece[i].second == rightv.first)))
		{
			flag = solve(pos+1, choice | (1 << i), piece[i].second);
		}

		if(flag)
			return true;

		if((piece[i].second == prev_right) && ((choice & (1 << i)) == 0) && (pos != n || (piece[i].first == rightv.first)))
		{
			flag = flag | solve(pos+1, choice | (1 << i), piece[i].first);
		}

		if(flag)
			return true;
	}

	return flag;
}

int main()
{
	while(cin>>n)
	{
		if(n == 0)
			break;
		
		cin>>m;
		read();
		if(solve(1, 0, leftv.second) == true)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}

	return 0;
}
