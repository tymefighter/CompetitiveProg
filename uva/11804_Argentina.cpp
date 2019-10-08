#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

typedef struct Player
{
    int attk, def;
    char name[30];
}Player;

bool comp(const Player &a, const Player &b)
{
    if(a.attk != b.attk)
        return a.attk > b.attk;
    else if(a.def != b.def)
        return a.def < b.def;
    else
        return (strcmp(a.name, b.name) <= 0);
}

bool lex_comp(const Player &a, const Player &b)
{
    return (strcmp(a.name, b.name) <= 0);
}

Player p[10];

void read_solve(int cno)
{
    for(int i = 0;i < 10;i++)
        scanf("%s %d %d", p[i].name, &p[i].attk, &p[i].def);

    sort(p, p + 10, comp);

    sort(p, p + 5, lex_comp);
    sort(p + 5, p + 10, lex_comp);
    
    printf("Case %d:\n(", cno);
    for(int i = 0;i < 5;i++)
    {
        if(i)
            printf(", ");
        printf("%s", p[i].name);
    }
    printf(")\n(");
    for(int i = 5;i < 10;i++)
    {
        if(i != 5)
            printf(", ");
        printf("%s", p[i].name);
    }
    printf(")\n");
}

int main()
{
    int t;
    cin>>t;
    for(int i = 1;i <= t;i++)
        read_solve(i);
    return 0;
}