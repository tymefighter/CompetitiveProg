#include<iostream>

using namespace std;

int ct;

void read()
{
    ct = 0;
    char c;
    while(scanf("%c", &c) == 1)
    {
        if(c == '\n')
            break;
        ct ++;
    }
}

int main()
{
    read();
    printf("Number of characters: %d\n", ct);
    return 0;
}