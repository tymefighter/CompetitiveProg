#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

const int NUM_ALPHA = 26;

inline void enable_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

inline char int2char(int n) {return static_cast<char>('a' + n);}
inline int char2int(char c) {return static_cast<int>(c - 'a');}

/**
 * string_arr: array of strings
 * string_map: unordered map of strings
 * indices_with_head[p]: indices of all those strings whose
 * head is int2char(p)
 * heads: all characters which are heads of any string
 * 
 * time complexity = amortized O(n * (m + NUM_ALPHA))
 * where m = maximum possible string length
 */
void read_and_compute(
    vector<string> &string_arr,
    unordered_set<string> &string_map,
    vector<vector<int> > &indices_with_head,
    vector<char> &heads
) {
    int n;
    cin >> n;

    indices_with_head.assign(NUM_ALPHA, vector<int>());
    string_arr.resize(n);
    heads.clear();

    for(int i = 0;i < n;i++) {
        cin >> string_arr[i];

        string_map.insert(string_arr[i]);
        indices_with_head[char2int(string_arr[i][0])].push_back(i);

        if(find(heads.begin(), heads.end(), string_arr[i][0])
            == heads.end())
            heads.push_back(string_arr[i][0]);
    }
}

/**
 * alpha[i]: array of alphabets, where each alphabet a is such
 * that when ith string's head is replaced by a, the transformed
 * string does not remain a "funny word"
 * 
 * time complexity = amortized O(n * m * NUM_ALPHA)
 * where m = maximum possible string length
 */
void compute_alpha(
    vector<string> &string_arr,
    const unordered_set<string> &string_map,
    const vector<char> &heads,
    vector<vector<char> > &alpha
) {
    int n = string_arr.size();
    alpha.assign(n, vector<char>());

    for(int i = 0;i < n;i++) {
        char prev_head = string_arr[i][0];

        for(char new_head : heads) {
            string_arr[i][0] = new_head;

            if(string_map.find(string_arr[i]) == string_map.end())
                alpha[i].push_back(new_head);
        }

        string_arr[i][0] = prev_head;
    }
}

/**
 *  num_strings[p][q]: number of strings with head int2char(p)
 *  whose head when replaced by int2char(q), the string is not
 *  present in "funny words"
 *
 *  time complexity: O(n * NUM_ALPHA * NUM_ALPHA)
 */
void compute_num_strings(
    const vector<vector<int> > &indices_with_head,
    const vector<char> &heads,
    const vector<vector<char> > &alpha,
    vector<vector<int> > &num_strings
) {
    num_strings.assign(NUM_ALPHA, vector<int>(NUM_ALPHA, 0));

    for(char char_p : heads) {
        for(char char_q : heads) {
            for(int idx : indices_with_head[char2int(char_p)]) {
                if(find(alpha[idx].begin(), alpha[idx].end(), char_q) 
                    != alpha[idx].end())
                    num_strings[char2int(char_p)][char2int(char_q)] ++;
            }
        }
    }
}

long long compute_num_team_names(
    const vector<vector<int> > &indices_with_head,
    const vector<char> &heads,
    const vector<vector<char> > &alpha,
    const vector<vector<int> > &num_strings
) {
    long long num_team_names = 0;
    for(char char_p : heads) {
        for(int idx : indices_with_head[char2int(char_p)]) {
            for(char char_q : alpha[idx])
                num_team_names += 
                    num_strings[char2int(char_q)][char2int(char_p)];
        }
    }

    return num_team_names;
}

int main() {

    enable_fast_io();

    int t;
    cin >> t;

    while(t --) {
        vector<string> string_arr;
        unordered_set<string> string_map;
        vector<vector<int> > indices_with_head;
        vector<char> heads;
        read_and_compute(string_arr, string_map, indices_with_head, heads);

        vector<vector<char> > alpha;
        compute_alpha(string_arr, string_map, heads, alpha);

        vector<vector<int> > num_strings;
        compute_num_strings(indices_with_head, heads, alpha, num_strings);

        cout << compute_num_team_names(
            indices_with_head,
            heads, 
            alpha, 
            num_strings
        ) << "\n";
    }

    return 0;
}
