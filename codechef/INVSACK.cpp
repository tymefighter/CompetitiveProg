#include<iostream>
#include<cassert>

using namespace std;

const int N = 105;
int n, p[N], w[N];
int p_sum, w_sum;

void b_search(int i)
{
    int w_low, w_mid, w_high, new_w_sum = -1;
    int p_val, new_p_sum;

    w_low = w_sum;
    w_high = w_low + 100;
    cout<<"1 "<<i + 1<<" "<<w_high<<endl;
    cin>>new_p_sum;

    while(w_low <= w_high)
    {
        w_mid = (w_low + w_high) / 2;
        cout<<"1 "<<i + 1<<" "<<w_mid<<"\n";
        cin>>p_val;

        if(p_val == new_p_sum)
        {
            new_w_sum = w_mid;
            w_high = w_mid - 1;
        }
        else
            w_low = w_mid + 1;
    }

    p[i] = new_p_sum - p_sum;
    w[i] = new_w_sum - w_sum;
    p_sum = new_p_sum;
    w_sum = new_w_sum;
}

void solve()
{
    p_sum = 0, w_sum = 0;
    for(int i = 0;i < n;i++)
        b_search(i);

    cout<<"2"<<endl;
    for(int i = 0;i < n;i++)
        cout<<w[i]<<" ";
    cout<<endl;
    for(int i = 0;i < n;i++)
        cout<<p[i]<<" ";
    cout<<endl;
}

int main()
{
    cin>>n;
    solve();
    return 0;
}