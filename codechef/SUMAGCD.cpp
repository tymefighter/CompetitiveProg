#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
int arr[100005];
vector<int> a;

void read()
{
    cin>>n;
    int i;
    for(i = 0;i < n;i++)
        cin>>arr[i];

    sort(arr, arr+n);
    a.clear();
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

int solve()
{
    if(a.size() == 1)
        return 2 * a[0];

    int val1 = a[a.size()-1], val2 = a[a.size()-2], val1n, val2n;

    for(int i = 0;i < a.size() - 2;i++)
    {
        val1n = gcd(val1, a[i]);
        val2n = gcd(val2, a[i]);

        if(val1n > val2n)
            val1 = val1n;
        else
            val2 = val2n;
    }
    return max(val1 + val2, get_val());
}

int main()
{
    long int t;
    cin>>t;

    while(t--)
    {
        read();
        cout<<solve()<<"\n";
    }
    return 0;
}