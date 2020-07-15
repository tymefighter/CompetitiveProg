#include<iostream>
#include<vector>

using namespace std;

class AlgoError {
    private:
        string msg;
    public:
        AlgoError(const string &msg_):
            msg(msg_) {}

        ~AlgoError() {}

        string what() {return msg;}
};

const int INF = static_cast<int>(1e8);

void readInput(
    string &a,
    string &b,
    int &costDelete,
    int &costInsert,
    int &costSwap
) {
    cin >> a;
    cin >> b;
    cin >> costDelete >> costInsert >> costSwap;
}

void editDistance(
    const string &a,
    const string &b,
    int costDelete,
    int costInsert,
    int costSwap
) {
    int n = a.size(), m = b.size();
    vector<vector<int> > dp(n + 1, (vector<int> (m)));
    vector<vector<char> > op(n + 1, (vector<char> (m, '\0')));

    dp[0][0] = 0;
    for(int i = 1;i <= n;i++)
        dp[i][0] = costDelete * i;

    for(int j = 1;j <= m;j++)
        dp[0][j] = costInsert * j;

    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            dp[i][j] = INF;

            if(dp[i][j] > dp[i - 1][j] + costDelete) {
                dp[i][j] = dp[i - 1][j] + costDelete;
                op[i][j] = 'd';
            }

            if(dp[i][j] > dp[i][j - 1] + costInsert) {
                dp[i][j] = dp[i][j - 1] + costInsert;
                op[i][j] = 'i';
            }

            if(dp[i][j] > dp[i - 1][j - 1] + costSwap) {
                dp[i][j] = dp[i - 1][j - 1] + costSwap;
                op[i][j] = 's';
            }

            if(a[i - 1] == b[j - 1] && dp[i][j] > dp[i - 1][j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
                op[i][j] = 'n';
            }
        }
    }

    int i = n, j = m;
    while(i > 0 && j > 0) {
        switch (op[i][j]) {
            case 'd':
                cout << "delete " << a[i - 1] << " at position " << i << "\n";
                i --;
                break;
            case 'i':
                cout << "insert " << b[j - 1] << " after position " << i << "\n";
                j --;
                break;
            case 's':
                cout << "swap " << a[i - 1] << " at position " << i << " with "
                    << b[j - 1] << "\n";
            case 'n':
                i --;
                j --;
                break;
            default:
                string msg = "found char ";
                msg.push_back(op[i][j]);
                throw *(new AlgoError (msg));
                break;
        }
    }

    while(i > 0) {
        cout << "delete " << a[i - 1] << " at position " << i << "\n";
        i --;
    }
    while(j > 0) {
        cout << "insert " << b[j - 1] << " after position " << i << "\n";
        j --;
    }
}

int main() {

    string a, b;
    int costDelete, costInsert, costSwap;

    readInput(a, b, costDelete, costInsert, costSwap);
    editDistance(a, b, costDelete, costInsert, costSwap);
    return 0;
}