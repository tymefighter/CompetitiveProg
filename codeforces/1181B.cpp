#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int n;
string a;
string c, d;

void read()
{
    cin>>n;
    a.resize(n);

    for(int i = 0;i < n;i++)
        cin>>a[i];
}

string get_sum(int m)
{
    string str1 = a.substr(0, m), str2 = a.substr(m, string::npos);
    
    if (str1.length() > str2.length()) 
        swap(str1, str2); 

    string str = ""; 
  
    int n1 = str1.length(), n2 = str2.length(); 

    reverse(str1.begin(), str1.end()); 
    reverse(str2.begin(), str2.end()); 
  
    int carry = 0; 
    for (int i=0; i<n1; i++) 
    { 
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
  
    for (int i=n1; i<n2; i++) 
    { 
        int sum = ((str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
  
    if (carry) 
        str.push_back(carry+'0');

    reverse(str.begin(), str.end()); 
  
    return str; 
}

bool c_is_lesser()
{
    if(c.size() < d.size())
        return true;
    else if(c.size() > d.size())
        return false;
    else if(c < d)
        return true;
    else
        return false;
}

string solve()
{
    int m;
    if(n % 2 == 0) // even
    {
        m = n / 2;
        if(a[m] != '0')
            return get_sum(m);

        int i = m, j = m;

        while(i > 0)
        {
            if(a[i] != '0')
                break;
            i--;
        }

        while(j < n)
        {
            if(a[j] != '0')
                break;
            j++;
        }

        if(i == 0 && j == n)
            return a;
        else if(i == 0)
            return get_sum(j);
        else if(j == n)
            return get_sum(i);


        c = get_sum(i);
        d = get_sum(j);

        if(c_is_lesser())
            return c;
        else
            return d;
    }
    else // odd
    {
        m = n / 2;
        int i = m, j = m + 1;

        while(i > 0)
        {
            if(a[i] != '0')
                break;
            i--;
        }

        while(j < n)
        {
            if(a[j] != '0')
                break;
            j++;
        }


        if(i == 0 && j == n)
            return a;
        else if(i == 0)
            return get_sum(j);
        else if(j == n)
            return get_sum(i);

        c = get_sum(i);
        d = get_sum(j);


        if(c_is_lesser())
            return c;
        else
            return d;
    }
}

int main()
{
    read();
    cout<<solve()<<"\n";

    return 0;
}