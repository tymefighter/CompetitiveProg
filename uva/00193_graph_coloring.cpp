#include<iostream>
#include<vector>
#include<bitset>

using namespace std;

vector<vector<int> > adj;
int n, m;
int ans;
bitset<101> ans_choice, choice, dont;

void resetAll()
{
	ans = 0;
	ans_choice.reset();
	choice.reset();
	dont.reset();
	adj.clear();
}

void read()
{
	int i, a, b;

	cin>>n>>m;

	adj.resize(n);

	for(i = 0;i < m;i++)
	{
		cin>>a>>b;
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
	}
}

void solve(int i, int val)
{
	if(i == n)
	{
		if(ans < val)
		{
			ans = val;
			ans_choice = choice;
		}

		return;
	}


	if(val + n - i < ans) // Would give TLE without this ---- very important 1
		return;
	
	solve(i + 1, val);
	

	if(dont.test(i))
		return;
	
	vector<int> now_set; // Won't work without this array ---- very important 2
	choice.set(i);

	for(int x : adj[i])
	{
		if(! dont.test(x))
		{
			now_set.push_back(x); // We place only those nodes which were set just now
			dont.set(x);
		}
	}
	
	solve(i + 1, val + 1);

	choice.reset(i);

	for(int x : now_set)
		dont.reset(x); // We reset only those nodes which were set just before the above recursion
	now_set.clear();
}

void print_choice()
{
	int i, ct = 0;

	for(i = 0;i < n;i++)
	{
		if(ans_choice.test(i))
		{
			if(ct)
				cout<<" ";
			cout<<i+1;
			ct++;
		}
	}
	cout<<'\n';
}

int main()
{
	int t, i;
	cin>>t;

	while(t--)
	{
		resetAll();
		read();
		solve(0, 0);
		cout<<ans<<'\n';
		print_choice();
	}

	return 0;
}
