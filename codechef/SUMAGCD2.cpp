#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
int arr[100005];
vector<int> a;

void read()
{
    a.clear();
    cin>>n;
    int i;
    for(i = 0;i < n;i++)
        cin>>arr[i];

    sort(arr, arr+n);
    a.push_back(arr[0]);

    for(i = 1;i < n;i++)
    {
        if(arr[i] != arr[i-1])
            a.push_back(arr[i]);
    }
}

int gcd(int a, int b)
{
    if(a < b)
        swap(a, b);

    if(b == 0)
        return a;
    
    return gcd(a % b, b);
}

int get_val()
{
    int val = a[0];
    for(int i = 1;i < a.size() - 1;i++)
        val = gcd(val, a[i]);
    
    val += a[a.size()-1];
    return val;
}

int solve2()
{
    int i, min_gcd_idx = 0, min_gcd = a[0], val;
    for(i = 1;i < a.size();i++)
    {
        val = gcd(a[0], a[i]);
        if(val < min_gcd)
        {
            min_gcd = val;
            min_gcd_idx = i;
        }
    }

    return min_gcd_idx;
}

int solve()
{
    int i = 1;
    while(i < a.size())
    {
        if(gcd(a[0], a[i]) == 1)
            break;
        i++;
    }


    if(i == a.size())
        i = solve2();

    int val1 = a[0], val2 = a[i], val1n, val2n; // n: next

    int x;
    for(int j = 1;j < a.size();j++)
    {
        if(j == i)
            continue;
        x = a[j];
        val1n = gcd(a[0], x);
        val2n = gcd(a[i], x);

        if(val1n > val2n)
            val1 = val1n;
        else
            val2 = val2n;
    }

    return max(val1 + val2, get_val());
}




int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        read();
        cout<<solve()<<"\n";
    }
    return 0;
}