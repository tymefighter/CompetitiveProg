#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
    
	
	long int n, f, s, t, x;

    priority_queue<int> pq;

    cin>>n;
    
    for(long int i = 0;i < n;i++)
    {
        cin>>x;
        
        pq.push(x);
        
        if(i == 0 || i == 1)
        {
            cout<<"-1\n";
            continue;
        }
        f = pq.top();
        pq.pop();
        s = pq.top();
        pq.pop();
        t = pq.top();
        
        cout<<f*s*t<<'\n';
        
        pq.push(s);
        pq.push(f);    
    }
    return 0;
}


