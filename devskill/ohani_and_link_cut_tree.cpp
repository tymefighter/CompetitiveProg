#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

/** Based on UnionFind */
class TreeMerge {
    private:

    vector<int> p, rank, root;

    int find_set(int x) {
        int rep_x = x, u;

        while(p[rep_x] != rep_x) rep_x = p[rep_x];

        while(p[x] != x) { // Path Compression
            u = p[x];
            p[x] = rep_x;
            x = u;
        }

        return rep_x;
    }

    public:

    TreeMerge(int n):
        p(n), rank(n, 0), root(n) {
            for(int i = 0;i < n;i++)
                root[i] = p[i] = i;
        }

    ~TreeMerge() {}

    void merge_trees(int parent_node, int child_node) {
        int u = find_set(parent_node), v = find_set(child_node);

        if(u == v) return;

        if(rank[u] > rank[v])
            p[v] = u;
        else if(rank[u] < rank[v]) {
            p[u] = v;
            root[v] = root[u];
        }
        else {
            p[v] = u;
            rank[u] ++;
        }
    }

    inline int get_root(int u) {return root[find_set(u)];}
};

inline void enable_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void read_input(
    vector<int> &parent, 
    vector<int> &cost,
    vector<pair<int, int> > &queries
) {
    int n;
    cin >> n;

    parent.resize(n, -1);
    cost.resize(n, -1);

    for(int i = 1;i < n;i++) {
        cin >> parent[i];
        parent[i] --;
    }

    for(int i = 1;i < n;i++) cin >> cost[i];

    int q;
    cin >> q;
    queries.resize(q);

    for(int i = 0;i < q;i++) {
        cin >> queries[i].first >> queries[i].second;
        queries[i].second --;
    }
}

vector<vector<pair<int, int> > > construct_graph(
    const vector<int> &parent, 
    const vector<int> &cost
) {
    int n = parent.size();
    vector<vector<pair<int, int> > > a(n);

    for(int i = 0;i < n;i++) {
        if(parent[i] != -1) {
            a[parent[i]].push_back({i, cost[i]});
            a[i].push_back({parent[i], cost[i]});
        }
    }

    return a;
}

vector<long long> bfs(const vector<vector<pair<int, int> > > &a, int s) {
    int n = a.size();
    queue<int> q;
    vector<long long> dist(n, -1);

    q.push(s);
    dist[s] = 0;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(pair<int, int> v : a[u]) {
            if(dist[v.first] == -1) {
                dist[v.first] = dist[u] + v.second;
                q.push(v.first);
            }
        }
    }

    return dist;
}

void solve_queries(
    const vector<int> &parent, 
    const vector<int> &cost,
    const vector<pair<int, int> > &queries
) {
    int n = parent.size();
    vector<long long> dist = bfs(construct_graph(parent, cost), 0);
    TreeMerge tree_merge(n);

    set<int> s;

    for(pair<int, int> query : queries)
        if(query.first == 1) s.insert(query.second);

    for(int i = 0;i < n;i++) {
        if(parent[i] != -1 && s.find(i) == s.end())
            tree_merge.merge_trees(parent[i], i);
    }

    vector<pair<int, long long> > result;
    for(auto it = queries.rbegin();it != queries.rend();it++) {
        if(it->first == 1) {
            if(parent[it->second] != -1)
                tree_merge.merge_trees(parent[it->second], it->second);
        }
        else {
            int root = tree_merge.get_root(it->second);
            result.push_back({root, dist[it->second] - dist[root]});
        }
    }

    for(auto it = result.rbegin();it != result.rend();it++)
        cout << it->first + 1 << " " << it->second << "\n";
}

int main() {

    vector<int> parent, cost;
    vector<pair<int, int> > queries;

    read_input(parent, cost, queries);
    solve_queries(parent, cost, queries);

    return 0;
}