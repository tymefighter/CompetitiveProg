#include<iostream>
#include<vector>

using namespace std;


typedef struct constraint
{
	int a, b, c;
}constraint;


void printVec(vector<int> a)
{
	for(int i = 0;i < a.size();i++)
		cout<<a[i]<<" ";
	//cout<<'\n';
	return;
}

void solve(vector<int> &p, const vector<constraint> &cs, int &count, int idx, vector<int> &ind)
{
	//ind[p[idx]] = idx;
	int i, j;

	if(idx >= p.size())
		return;	

	
	if(idx == p.size()-1)
	{
		//printVec(p);
		//cout<<" : ";
		ind[p[idx]] = idx;
		//printVec(ind);
		//cout<<'\n';
		int flag = false;

		for(i = 0;i < cs.size();i++)
		{
			if(cs[i].c > 0)
			{
				if(abs(ind[cs[i].a] - ind[cs[i].b]) > abs(cs[i].c))
					break;
			}
			else
			{
				if(abs(ind[cs[i].a] - ind[cs[i].b]) < abs(cs[i].c))
					break;
			}
		}

		if(i == cs.size())
			count++;
	}

	for(i = idx;i < p.size();i++)
	{
		swap(p[idx], p[i]);
		ind[p[idx]] = idx;
		solve(p, cs, count, idx+1, ind);
		swap(p[idx], p[i]);
	}

	return;
}

int fact(int n)
{
	int i, j = 1;

	for(i = 2;i <= n;i++)
		j *= i;

	return j;
}

int main()
{
	int n, m, i, count;
	vector<constraint> cs;
	vector<int> p, ind;


	while(cin>>n>>m)
	{
		if((n|m) == 0)
			break;

		cs.clear();
		p.clear();
		ind.clear();
		cs.resize(m);
		p.resize(n);
		ind.resize(n);

		for(i = 0;i < n;i++)
			p[i] = i;

		for(i = 0;i < m;i++)
		{
			cin>>cs[i].a>>cs[i].b>>cs[i].c;
		}
	
		count = 0;
		if(m != 0)
			solve(p, cs, count, 0, ind);
		else
			count = fact(n);

		cout<<count<<'\n';
	}

	return 0;
}
