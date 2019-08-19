#include<iostream>
#include<string>

using namespace std;

string s;

void read()
{
    getline(cin, s);
}

void analysis()
{
    char c;
    int n_v = 0, n_c = 0;                   // number of vowels and number of consonents
    for(int i = 0;i < s.size();i++)
    {
        s[i] = tolower(s[i]);
        c = s[i];
        if(c >= 'a' && c <= 'z')
        {
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                n_v ++;
            else
                n_c ++;
        }
    }

    cout<<s<<"\n";
    printf("Num vowels: %d, Num consonents: %d\n", n_v, n_c);
}

int main()
{
    read();
    analysis();
    return 0;
}