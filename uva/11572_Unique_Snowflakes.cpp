#include<iostream>
#include<unordered_map>
#include<queue>
#include<utility>

using namespace std;

int n;
unordered_map<int, int> m;
priority_queue<pair<int, pair<int, int> > , vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > >> seg_start_ind, seg_end_ind;


void resetAll()
{
	m.clear();
	

	while(seg_start_ind.empty() == false)
	{
		//cout<<'a';
		seg_start_ind.pop();
	}
	while(seg_end_ind.empty() == false)
	{
		cout<<seg_end_ind.size()<<'\n';
		seg_end_ind.pop();
	}
}

void read_createSeg()
{
	int i, x;

	for(i = 0;i < n;i++)
	{
		cin>>x;

		if(m.find(x) == m.end())
		{
			m[x] = i;
		}
		else
		{
			seg_start_ind.push({m[x], {m[x], i}});
			seg_end_ind.push({i, {m[x], i}});

			m[x] = i;
		}
	}

	for(auto it = m.begin(); it != m.end(); it++)
	{
		x = (*it).first;
		//cout<<x<<" "<<(*it).second<<" "<<n<<"\n";

		seg_start_ind.push({m[x], {m[x], n}});
		seg_end_ind.push({n, {m[x], n}});

		m[x] = n;
	}
	//cout<<"--\n";
}

bool check_inside(pair<int, int> a, pair<int, int> b)
{
	if(a.first <= b.first && b.second <= a.second)
		return true;
	else
		return false;
}

int solve()
{
	int i;
	pair<int, pair<int, int> > element;
	pair<int, int> seg1, seg2;
	
	int max_len, len;

	max_len = len = 0;

	while(seg_start_ind.empty() == false)
	{
		element = seg_start_ind.top();
		seg1 = element.second;
		seg_start_ind.pop();

		element = seg_end_ind.top();
		//cout<<element.first<<" ";
		seg2 = element.second;
		//seg_end_ind.pop();
		
		while(seg_end_ind.empty() == false && seg2.first <= seg1.first)
		{
			seg_end_ind.pop();
			element = seg_end_ind.top();
			seg2 = element.second;
			//cout<<"a\n";
		}

		//cout<<seg1.first<<" "<<seg1.second<<" "<<seg2.first<<" "<<seg2.second<<'\n';
		
		if(check_inside(seg1, seg2))
		{
			len = seg2.second - seg1.first;
			//cout<<len<<'\n';
			if(len > max_len)
				max_len = len;

			//seg_start_ind.pop();
			seg_end_ind.pop();
		}
	}

	return max_len;
}

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		cin>>n;
		cout<<n<<" ";
		resetAll();
		read_createSeg();
		cout<<solve();//<<"--\n";
		//cout<<t<<'\n';
	}

	return 0;
}

