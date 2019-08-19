#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int bottomUp(const vector<int> &h)
{
	vector<int> dp(h.size());
	int n = h.size() - 1;

	dp[n] = 0;
	dp[n-1] = dp[n] + abs(h[n - 1] - h[n]);

	for(int i = n-2; i >= 1;i--)
		dp[i] = min(dp[i + 1] + abs(h[i] - h[i + 1]), dp[i + 2] + abs(h[i] - h[i + 2]));
	
	return dp[1];
}



int main()
{
	int n;
	cin>>n;

	vector<int> h(n+1);

	for(int i = 1;i < h.size();i++)
		cin>>h[i];
	
	cout<<bottomUp(h)<<'\n';
	return 0;

}
