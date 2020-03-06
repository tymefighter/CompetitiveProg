#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>

using namespace std;

const int N = 200005;
int n, a[N], t[N];
priority_queue<int> pq;
map<int, vector<int> > m;

void read()
{
    cin>>n;
    for(int i = 0;i < n;i++)
        scanf("%d",&a[i]);

    for(int i = 0;i < n;i++)
    {
        scanf("%d",&t[i]);
        m[a[i]].push_back(t[i]);
    }
}

void solve()
{
    long long ans = 0;
    while(!m.empty())
    {
        int val = (*(m.begin())).first;
        long long curr_sum = 0;

        while(true)
        {
            for(int x : m[val])
            {
            	pq.push(x);
            	curr_sum += x;
            }
            
            m.erase(val);
            curr_sum -= pq.top();
            pq.pop();
            val ++;
            ans += curr_sum;
            if(pq.empty())
                break;
        }
    }
    
    printf("%lld\n",ans);
}

int main()
{
    read();
    solve();
    return 0;
}
