#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<string>
#include<sstream>

using namespace std;

vector<vector<int> > adj;
vector<bool> visited;
vector<int> tin;
vector<int> fup;
set<int> s;
int timer = 0;
vector<int> ans;

using namespace std;

void explore(int x, int parent_x)
{
	visited[x] = true;
	fup[x] = tin[x] = timer++;
	int num_child = 0;

	for(int y : adj[x])
	{
		if(y == parent_x)
			continue;
		else if(visited[y])
			fup[x] = min(fup[x], tin[y]);
		else
		{
			explore(y, x);
			fup[x] = min(fup[x], fup[y]);
			num_child++;

			if(parent_x != -1 && tin[x] <= fup[y])
				s.insert(x);
		}
	}

	if(parent_x == -1 && num_child > 1)
		s.insert(x);
	return;
}

void dfs()
{
	for(int i = 0;i < adj.size();i++)
	{

		if(visited[i] == false)
			explore(i, -1);
	}

	return;
}



void extractIntegerWords(string str) 
{ 
    stringstream ss;     
  
    /* Storing the whole string into string stream */
    ss << str; 
  
    /* Running loop till the end of the stream */
    string temp; 
    int found; 
	ans.clear();
    while (!ss.eof()) { 
  
        /* extracting word by word from stream */
        ss >> temp; 
  
        /* Checking the given word is integer or not */
        if (stringstream(temp) >> found) 
            ans.push_back(found);
  
        /* To save from space at the end of string */
        temp = ""; 
    }
} 

int main()
{
	int n, a, b, count, i;
	string str;

	while(getline(cin, str))
	{
		extractIntegerWords(str); 
		n = ans[0];


		if(n==0)
			break;

		adj.clear();
		visited.clear();
		tin.clear();
		fup.clear();
		s.clear();


		adj.resize(n);
		visited.assign(n, false);
		tin.resize(n);
		fup.resize(n);

		while(getline(cin, str))
		{
			if(str[0] == '0')
				break;
			
			extractIntegerWords(str); 
			a = ans[0];
			//cout<<a<<" ";
			
			for(i = 1;i < ans.size();i++)
			{
				b = ans[i];
				adj[a-1].push_back(b-1);
				adj[b-1].push_back(a-1);
				//cout<<b<<" ";
			}
			//cout<<'\n';
		}
		
		dfs();
		cout<<s.size()<<'\n';
		//print_adj();
	}

	return 0;
}
