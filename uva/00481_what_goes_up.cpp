#include<iostream>
#include<vector>

using namespace std;

int n;
vector<int> a, prevInd, tailInd;

void read()
{
    int x;
    while(cin>>x)
        a.push_back(x);

    n = a.size();
    prevInd.assign(n, -1);
    tailInd.assign(n, 0);
}

int b_search(int low, int high, int val)
{
    int mid = (low + high) / 2;

    while(low <= high)
    {
        if(mid > 0 && a[tailInd[mid]] >= val && a[tailInd[mid-1]] < val)
            return mid;
        
        if(mid > 0 && a[tailInd[mid-1]] > val)
            high = mid - 1;
        else
            low = mid + 1;
        
        mid = (low + high) / 2;
    }

    return -1;
}

void displayLIS(int i)
{
    if(i == -1)
        return;
    displayLIS(prevInd[i]);
    cout<<a[i]<<"\n";
}

void solve()
{
    int i, len = 1, pos;
    for(i = 1;i < n;i++)
    {
        if(a[i] < a[tailInd[0]])
            tailInd[0] = i;
        
        else if(a[i] > a[tailInd[len-1]])
        {
            prevInd[i] = tailInd[len-1];
            tailInd[len] = i;
            len ++;
        }
        else
        {
            pos = b_search(0, len-1, a[i]);
            prevInd[i] = tailInd[pos-1];
            tailInd[pos] = i;
        }
    }

    cout<<len<<"\n-\n";
    displayLIS(tailInd[len-1]);
}


int main()
{
    read();
    solve();
    return 0;
}