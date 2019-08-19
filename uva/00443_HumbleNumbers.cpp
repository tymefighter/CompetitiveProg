#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<long long int> vals;
int a[] = {2, 3, 5, 7};

void generate_no()
{
    vals.push_back(1);
    int i, j, sz;
    long long int x;

    for(i = 0;i < 4;i++)
    {
        sz = vals.size();
        for(j = 0;j < sz;j++)
        {
            x = vals[j] * a[i];

            while(x <= 2000000000ll)
            {
                vals.push_back(x);
                x *= a[i];
            }
        }
    }

    sort(vals.begin(), vals.end());
}

int main()
{
    int n;
    generate_no();

    while(cin>>n)
    {
        if(!n)
            break;
        if(n % 10 == 1 && (n / 10) % 10 != 1)
            printf("The %dst humble number is %lld.\n", n, vals[n - 1]);
        else if(n % 10 == 2 && (n / 10) % 10 != 1)
            printf("The %dnd humble number is %lld.\n", n, vals[n - 1]);
        else if(n % 10 == 3 && (n / 10) % 10 != 1)
            printf("The %drd humble number is %lld.\n", n, vals[n - 1]);
        else
            printf("The %dth humble number is %lld.\n", n, vals[n - 1]);
    }
    return 0;
}