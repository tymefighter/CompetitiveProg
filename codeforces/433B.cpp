#include<iostream>
#include<algorithm>

using namespace std;

int n, m;
long long int cf[100005], s_cf[100005];
int v[100005], v_sorted[100005];

void read()
{
    int i;
    for(i = 0;i < n;i++)
    {
        cin>>v[i];
        cf[i] = v[i] * 1ll + (i > 0 ? cf[i-1] : 0ll);
        v_sorted[i] = v[i];
    }

    sort(v_sorted, v_sorted + n);

    for(i = 0;i < n;i++)
        s_cf[i] = v_sorted[i] * 1ll + (i > 0 ? s_cf[i-1] : 0ll);
}


int main()
{
    cin>>n;
    read();
    cin>>m;
    int q_type, l, r;

    while(m--)
    {
        cin>>q_type>>l>>r;
        l--, r--;

        if(q_type == 1)
            printf("%lld",(r >= 0 ? cf[r] : 0ll) - (l > 0 ? cf[l - 1] : 0ll));
        else
            printf("%lld", (r >= 0 ? s_cf[r] : 0ll) - (l > 0 ? s_cf[l - 1] : 0ll));
        
        cout<<'\n';
    }

    return 0;
}