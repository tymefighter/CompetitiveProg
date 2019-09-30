#include<iostream>
#include<cstring>

using namespace std;

/*
    Greedy solution

    - Iterate through the string and whenever a 
    character can be placed on top of a used 
    stack, place it. If it cannot, then create
    a new stack for it

    - Whenever the current character is added
    to a stack, the stack would belong to that
    character (i.e. change of ownership if
    previously owned by a larger character)

    - Hence, atmost 26 stacks would be used,
    one belonging to each character
*/

int ans;
string s;
char head[26];

void solve()
{
    int i;
    ans = 0;
    for(char x : s)
    {
        for(i = 0;i < 26;i++)
        {
            if(head[i] != '\0' && x <= head[i])
            {
                head[i] = x;
                break;
            }
            else if(head[i] == '\0')
            {
                head[i] = x;
                ans ++;
                break;
            }
        }
    }
}

int main()
{
    int cno = 1;

    while(cin>>s)
    {
        if(s == "end")
            break;
        memset(head, '\0', sizeof(head));
        solve();
        printf("Case %d: %d\n", cno, ans);
        cno ++;
    }
    return 0;
}