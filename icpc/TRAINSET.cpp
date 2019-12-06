#include<iostream>
#include<vector>
#include<map>
#include<set>

using namespace std;

#define inf 1000000007
#define pb push_back

typedef long long int ll;
typedef vector<int> vi;

string st;
int t,m,n,a,b,f=0;
int main()
{
ios::sync_with_stdio(false);
cin.tie(NULL);

cin>>t;
while(t--)
{
cin>>n;

set<string>s;
map<string,int> mp0;
map<string,int> mp1;
int ans=0;

for(int i=0; i<=n-1; i++)
{
cin>>st>>a;
s.insert(st);
if(a) mp1[st]++;
else mp0[st]++;
}

int a1, a2;
for(auto e: s)
{
a1=mp1[e]; a2=mp0[e];
ans+=max(a1, a2);
}

cout<<ans<<"\n";
}

return 0;
}




