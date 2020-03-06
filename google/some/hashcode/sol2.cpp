#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
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

void visualize()
{
    // for(int x : bk[100])
    //     cout<<x<<"\n";
    
    map<int, int> m;
    for(int i = 0;i < l;i++)
        m[num_bk_max[i]] ++;

    for(auto x : m)
        cout<<x.first<<" "<<x.second<<"\n";

    m.clear();
    for(int i = 0;i < l;i++)
        m[sign_lib[i]] ++;

    cout<<"----\n";
    for(auto x : m)
        cout<<x.first<<" "<<x.second<<"\n";

    map<int, int> st;
    for(int i = 0;i < bk.size();i++)
    {
        for(int x : bk[i])
        {
            // if(st.find(x) != st.end())
            // {
            //     printf("rep !!!\n");
            //     return;
            // }
            st[x] ++;
        }
    }

    for(auto x : st)
        cout<<x.first<<" "<<x.second<<"\n";
}

int main()
{
    read();
    visualize();
    return 0;
}