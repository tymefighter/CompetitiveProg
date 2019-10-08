#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

const int N = 31270;
long long val, s[N + 1], a[N + 1];

void generate()
{
    a[0] = s[0] = 0;
    for(int i = 1;i <= N;i++)
    {
        s[i] = s[i - 1] + log10(i) + 1;
        a[i] = a[i - 1] + s[i];
    }
}

int b_search()
{
    int low = 0, high = N, mid;

    if(a[high] <= val)
        return high;

    while(low <= high)
    {
        mid = (low + high) / 2;
        if(mid < N && a[mid] <= val && a[mid + 1] > val)
            return mid;
        else if(mid < N && a[mid + 1] <= val)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

void getDig(int idx, int no)
{
    vector<int> arr;

    while(no)
    {
        arr.push_back(no % 10);
        no /= 10;
    }

    reverse(arr.begin(), arr.end());
    cout<<arr[idx]<<"\n";
}

void solve()
{
    int k = b_search();
    val -= a[k];
    k ++;

    if(val == 0)
    {
        cout<<((k-1) % 10)<<"\n";
        return;
    }

    int val2 = 0;
    for(int i = 1;i <= k;i++)
    {
        if(val2 + log10(i) + 1 >= val)
        {
            getDig(val - val2 - 1, i);
            return;
        }

        val2 += log10(i) + 1;
    }
}

int main()
{
    int t;
    cin>>t;
    generate();
    while(t--)
    {
        cin>>val;
        solve();
    }
    return 0;
}