#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<cassert>

using namespace std;

const int N = 100005;
int b, l, d;
int s[N], sign_lib[N], num_bk_max[N];
vector<set<int> > bk;
vector<vector<int> > book_to_lib;
bool signedup[N];

void read()
{
    scanf("%d%d%d",&b,&l,&d);
    book_to_lib.resize(b);
    for(int i = 0;i < b;i++)
        scanf("%d",&s[i]);
    
    bk.resize(l);
    for(int i = 0;i < l;i++)
    {
        signedup[i] = false;
        int nb;
        scanf("%d%d%d",&nb, &sign_lib[i], &num_bk_max[i]);

        for(int j = 0;j < nb;j++)
        {
            int book_id;
            scanf("%d",&book_id);
            bk[i].insert(book_id);

            book_to_lib[book_id].push_back(i);
        }
    }
}

void solve()
{
    vector<int> signup;
    vector<vector<int> > books_taken;
    int num_days_signup = 0, max_lib;

    for(int i = 0;i < l;i++)
    {
        max_lib = -1;
        for(int j = 0;j < l;j++)
        {
            if(!signedup[j] && (max_lib == -1 || bk[max_lib].size() < bk[j].size()))
                max_lib = j;
        }

        if(bk[max_lib].size() == 0 || num_days_signup + sign_lib[max_lib] > d)
            break;


        int books_count = 0;
        vector<int> bks_sel;

        for(int bk_id : bk[max_lib])
        {
            if(books_count + 1 > (d - num_days_signup) * num_bk_max[max_lib])
                break;

            bks_sel.push_back(bk_id);
            books_count ++;
        }

        signedup[max_lib] = true;
        if(books_count == 0)
            continue;

        signup.push_back(max_lib);

        books_taken.push_back(bks_sel);

        for(int bk_id : bks_sel)
        {
            for(int lib : book_to_lib[bk_id])
                bk[lib].erase(bk_id);
        }

        num_days_signup += sign_lib[max_lib];
    }

    assert(books_taken.size() == signup.size());

    cout<<signup.size()<<"\n";

    for(int i = 0;i < signup.size();i++)
    {
        cout<<signup[i]<<" "<<books_taken[i].size()<<"\n";
        for(int book_id : books_taken[i])
            cout<<book_id<<" ";
        cout<<"\n";
    }

}

int main()
{
    read();
    solve();
    return 0;
}