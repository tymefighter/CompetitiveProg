#include<iostream>

using namespace std;

const int N = 55;
int n, m;
char a[N][N];
bool visited[N][N];

void readInput() {
    cin >> n >> m;

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            cin >> a[i][j];
            visited[i][j] = false;
        }
    }
}

int ar[] = {1, -1, 0, 0};
int ac[] = {0, 0, 1, -1};

void dfs(int i, int j) {
    visited[i][j] = true;

    for(int k = 0;k < 4;k++) {
        int id = i + ar[k], jd = j + ac[k];
        if(id >= 0 && id < n && jd >= 0 && jd < m && !visited[id][jd] && a[id][jd] != '#') {
            dfs(id, jd);
        }
    }
}

bool solve() {
    if(a[n - 1][m - 1] == 'B')
        return false;

    bool foundG = false;

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            if(a[i][j] == 'G')
                foundG = true;

            if(i < n - 1) {
                if((a[i][j] == 'G' && a[i + 1][j] == 'B') || (a[i][j] == 'B' && a[i + 1][j] == 'G')) // adjacent
                    return false;
            }
            if(j < m - 1) {
                if((a[i][j] == 'G' && a[i][j + 1] == 'B') || (a[i][j] == 'B' && a[i][j + 1] == 'G')) // adjacent
                    return false;
            }
        }
    }

    if(!foundG)
        return true;

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            if(a[i][j] == 'B') {
                for(int k = 0;k < 4;k++) {
                    int id = i + ar[k], jd = j + ac[k];
                    if(id >= 0 && id < n && jd >= 0 && jd < m && a[id][jd] != 'B')
                        a[id][jd] = '#';
                }
            }
        }
    }

    if(a[n - 1][m - 1] == '#')
        return false;

    dfs(n - 1, m - 1);

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            if(a[i][j] == 'G') {
                if(!visited[i][j])
                    return false;
            }
        }
    }

    return true;
}

int main() {
    int t;
    cin >> t;
    while(t --) {
        readInput();
        if(solve())
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}