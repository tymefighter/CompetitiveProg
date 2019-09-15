#include<iostream>

using namespace std;

char line[128];

int check_string()
{
    int a, b, c;
    char op, ch;
    sscanf(line, "%d%c%d=%c", &a, &op, &b, &ch);

    if(ch == '?')
        return 0;
    
    sscanf(line, "%d%c%d=%d", &a, &op, &b, &c);

    if(op == '+' && a + b == c)
        return 1;
    if(op == '-' && a - b == c)
        return 1;
    
    return 0;
}

int main()
{
    int ans = 0;
    while(fgets(line, sizeof(line), stdin) != NULL)
        ans += check_string();
    cout<<ans<<"\n";
    return 0;
}