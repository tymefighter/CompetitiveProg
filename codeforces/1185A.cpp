#include<iostream>
#include<algorithm>

using namespace std;
int arr[3];

int main()
{
    long int a, b, c, d;
    cin>>arr[0]>>arr[1]>>arr[2]>>d;

    sort(arr, arr + 3);
    a = arr[0], b = arr[1], c = arr[2];

    long int ans = max(d - (c - b), 0l) + max(d - (b - a), 0l);
    cout<<ans<<"\n";
    return 0;
}