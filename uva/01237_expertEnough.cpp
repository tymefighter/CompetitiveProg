#include<iostream>
#include<vector>
#include<string>
#include<utility>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<pair<pair<int, int>, string> >a;

	int ct = 0, t, d, i, q, p, j;
	string make;
	bool flag;

	cin>>t;

	while(t--)
	{
		if(ct != 0)
			cout<<'\n';

		cin>>d;
		a.clear();

		a.resize(d);

		for(i = 0;i < d;i++)
		{
			cin>>a[i].second>>a[i].first.first>>a[i].first.second;
		}

		cin>>q;

		for(i = 0;i < q;i++)
		{
			cin>>p;
			flag = false;
			//cout<<p<<"--\n";

			for(j = 0;j < d;j++)
			{
				//cout<<p<<" "<<a[i].first.first<<" "<<a[i].first.second<<'\n';
				if(p >= a[j].first.first && p <= a[j].first.second && flag == false)
				{
					make = a[j].second;
					flag = true;
				}
				else if(p >= a[j].first.first && p <= a[j].first.second && flag == true)
				{
					flag = false;
					break;
				}
			}


			if(flag == false)
				cout<<"UNDETERMINED\n";
			else
				cout<<make<<'\n';
		}
		ct++;
	}

	return 0;
}
