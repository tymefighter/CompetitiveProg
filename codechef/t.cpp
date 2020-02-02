#include<stdio.h>
#include<string.h>
int main()
{
    int n,q; scanf("%d%d",&n,&q);
    long long int a[n];
    for(int i=0;i<n;i++) scanf("%lld",&a[i]);
    while(q--){
        int l,r;
        scanf("%d%d",&l,&r);
    if ((a[l-1]<a[l] && a[r-2]<a[r-1]) || (a[l-1]>a[l] && a[r-2]>a[r-1]))
        printf("NO\n");
    else
        printf("YES\n");
        
    }
}
