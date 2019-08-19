#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<utility>
#include<set>
#include<algorithm>

using namespace std;

char line[128];
set<int> s;
int prob_attempts[101][10];
bool prob_flag[101][10];
int penalty[101];
int probs_solved[101];
vector<pair<pair<int, int>, int> > final_vec;


bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
	if(a.first.first > b.first.first)
		return true;
	else if(a.first.first < b.first.first)
		return false;
	
	if(a.first.second < b.first.second)
		return true;
	else if(a.first.second > b.first.second)
		return false;
	
	if(a.second < b.second)
		return true;
	else
		return false;
}

void init()
{
	int i, j;
	for(i = 0;i < 101;i++)
	{
		for(j = 0;j < 10;j++)
		{
			prob_attempts[i][j] = 0;
			prob_flag[i][j] = false;
		}
		penalty[i] = 0;
		probs_solved[i] = 0;
	}
}

void clearAll()
{
	s.clear();
	final_vec.clear();
}

void read()
{
	int cont, prob, time;
	char L;

	while(fgets(line, sizeof(line), stdin))
	{
		//printf("%s",line);
		if(line[0] < '0' || line[0] > '9')
			break;

		sscanf(line, "%d %d %d %c", &cont, &prob, &time, &L);

		s.insert(cont);
		//cout<<L<<'\n';
		if(L == 'R' || L == 'U' || L == 'E')
			continue;

		if(prob_flag[cont][prob] == true)
			continue;

		if(L == 'C')
		{
			prob_flag[cont][prob] = true;
			probs_solved[cont] += 1;
			penalty[cont] += time + prob_attempts[cont][prob]*20;
		}
		else
		{
			prob_attempts[cont][prob] += 1;
		}
	}
}


void solve()
{
	int cont;
	for(auto it = s.begin(); it != s.end(); it++)
	{
		cont = *it;
		final_vec.push_back({{probs_solved[cont], penalty[cont]}, cont});
	}

	sort(final_vec.begin(), final_vec.end(), comp);

	for(auto x = final_vec.begin(); x != final_vec.end(); x++)
	{
		cout<<x->second<<" "<<(x->first).first<<" "<<(x->first).second<<'\n';
	}
	
	//cout<<'\n';
	return;
}

void re_init()
{
	int i, cont;
	for(auto it = s.begin(); it != s.end(); it++)
	{
		cont = *it;

		for(i = 0;i < 10;i++)
		{
			prob_attempts[cont][i] = 0;
			prob_flag[cont][i] = false;

		}
		penalty[cont] = 0;
		probs_solved[cont] = 0;
	}
}

int main()
{
	int t, count = 0;
	
	fgets(line, sizeof(line), stdin);
	sscanf(line, "%d", &t);
	fgets(line, sizeof(line), stdin);

	init();
	
	while(t--)
	{
		if(count != 0)
			cout<<'\n';
		clearAll();
		read();
		solve();
		re_init();
		count++;
	}
	return 0;
}
