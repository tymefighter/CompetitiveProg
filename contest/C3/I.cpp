#include<iostream>
#include<sstream>
#include<cmath>

using namespace std;

const double root2 = sqrt(2.0);

stringstream ss;
double x, y;

void read() {
    x = y = 0.0;

    while(!ss.eof()) {
        int val;
        double numStep;
        char c1, c2;
        ss >> val;
        numStep = val;
        ss >> c1 >> c2;

        if(c2 != ',' && c2 != '.') {
            numStep /= root2;
            if(c2 == 'N')
                y += numStep;
            else if(c2 == 'S')
                y -= numStep;
            else if(c2 == 'E')
                x += numStep;
            else
                x -= numStep;
            ss >> c2;
        }

        if(c1 == 'N')
            y += numStep;
        else if(c1 == 'S')
            y -= numStep;
        else if(c1 == 'E')
            x += numStep;
        else
            x -= numStep;

        if(c2 == '.')
            break;
    }
}

void solve() {
    printf("The treasure is located at (%0.3lf,%0.3lf).\n", x, y);
    printf("The distance to the treasure is %0.3lf.\n", hypot(x, y));
}

int main() {

    int mapNumber = 1;
    string s;
    while(getline(cin, s)) {
        if(s == "END")
            break;
        
        printf("Map #%d\n", mapNumber);
        ss.clear();
        ss.str(s);

        read();
        solve();
        mapNumber ++;
        printf("\n");
    }
    return 0;
}