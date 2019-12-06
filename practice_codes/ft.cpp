#include<iostream>
#include<vector>

using namespace std;

class FenwickTree
{
    private:

    int n;
    vector<int> ft;

    int LSone(int i)
    {
        return i & (-i);
    }
    
    public:

    int rsq(int i)
    {
        int sum = 0;
        while(i > 0)
        {
            sum += ft[i];
            i -= LSone(i);
        }

        return sum;
    }

    int rsq(int i, int j)
    {
        return rsq(j) - (i == 1 ? 0 : rsq(i - 1));
    }

    void adjust(int i, int val)
    {
        while(i <= n)
        {
            ft[i] += val;
            i += LSone(i);
        }
    }

    void reset(const vector<int> &a)
    {
        n = a.size();
        ft.assign(n + 1, 0);

        for(int i = 1;i <= n;i++)
            adjust(i, a[i - 1]);
    }
};

int n;
FenwickTree ft;
vector<int> a;

void read()
{
    cin>>n;
    a.resize(n);
    for(int i = 0;i < n;i++)
        cin>>a[i];

    ft.reset(a);
}

void solve()
{
    int i, j;
    int idx, val;
    string s;
    while(true)
    {
        cin>>s;

        if(s == "rsq")
        {
            cin>>i>>j;
            cout<<ft.rsq(i, j)<<"\n";
        }
        else if(s == "adj")
        {
            cin>>idx>>val;
            ft.adjust(idx, val);
        }
        else
            break;
    }
}

int main()
{
    read();
    solve();
    return 0;
}