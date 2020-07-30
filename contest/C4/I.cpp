#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

ifstream ifs;
ofstream ofs;

int main() {

    ifs.open("perechi3.in");
    ofs.open("perechi3.out");

    int t;

    ifs >> t;
    while(t --) {
        long long n, k, ans = 0;
        ifs >> n;

        k = sqrt(n);
        for(int i = 1;i <= k;i++)
            ans += n / i;
        
        ans = 2 * ans - k * k;
        ofs << ans << "\n";
    }

    ifs.close();
    ofs.close();

    return 0;
}