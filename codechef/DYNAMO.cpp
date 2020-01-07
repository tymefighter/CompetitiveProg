#include<iostream>
#include<cassert>

using namespace std;

long long S, A, B, C, D, E;
int N;

void solve()
{
    cin>>N;
    cin>>A;

    long long pw_ten_N = 1;
    for(int i = 0;i < N;i++)
        pw_ten_N *= 10;
    
    S = A + pw_ten_N + pw_ten_N;
    cout<<S<<endl;

    cin>>B;
    C = pw_ten_N - B;
    cout<<C<<endl;

    cin>>D;
    E = pw_ten_N - D;
    cout<<E<<endl;

    int isCorrect;
    cin>>isCorrect;
    assert(isCorrect == 1);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();

    return 0;
}