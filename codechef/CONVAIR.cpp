#include<iostream>
#include<vector>

using namespace std;

class Error {
    private:
        string msg;
    public:
        Error(const string msg_):
            msg(msg_) {}

        ~Error() {}
};

template<class T>
struct Node {
    T x;
    Node<T> *next;

    Node(T x_):
        x(x_),
        next(nullptr) {}

    ~Node() {}
};

template<class T>
class List {
    private:
        int size;
        Node<T> *head, *tail;
    public:

        void reset() {
            Node<T> *node = head;
            while(node != nullptr) {
                Node<T> *temp = node->next;
                delete node;
                node = temp;
            }
            head = tail = nullptr;
            size = 0;
        }

        List():
            size(0),
            head(nullptr),
            tail(nullptr) {}

        List(const List<T> &ls):
            size(0),
            head(nullptr),
            tail(nullptr) {
                Node<T> *node = ls.head;
                while(node != nullptr) {
                    insert(node->x);
                    node = node->next;
                }
            }

        ~List() {
            reset();
        }

        const List& operator=(const List<T> &ls) {
            reset();
            Node<T> *node = ls.head;
            while(node != nullptr) {
                insert(node->x);
                node = node->next;
            }
            return *this;
        }

        void insert(T x) {
            size ++;
            Node<T> *newNode = new Node<T> (x);
            if(head == nullptr)
                head = tail = newNode;
            else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        void append(List<T> &ls) {
            if(ls.size == 0)
                return;
            
            if(size == 0) {
                size = ls.size;
                head = ls.head;
                tail = ls.tail;

                ls.size = 0;
                ls.head = ls.tail = nullptr;// remove duplicacy
                return;
            }

            size += ls.size;
            tail->next = ls.head;
            tail = ls.tail;

            ls.size = 0;
            ls.head = ls.tail = nullptr; // remove duplicacy
        }

        Node<T> *getHead() {return head;}

        int getSize() {return size;}

        T pop() {
            if(head == nullptr)
                throw *(new Error("empty list"));

            size --;

            Node<T> *temp = head;
            head = head->next;
            T val = temp->x;
            delete temp;

            if(size == 0)
                head = tail = nullptr;

            return val;
        }
};

class Comp {
    private:
        int rep;
        List<pair<int, int> > non_extra, extra;
    public:
        Comp():
            rep(-1) {}

        Comp(const Comp &c) {
            rep = c.rep;
            non_extra = c.non_extra;
            extra = c.extra;
        }

        ~Comp () {}

        const Comp& operator=(Comp &c) {
            rep = c.rep;
            non_extra = c.non_extra;
            extra = c.extra;
            return *this;
        }

        void reset() {
            non_extra.reset();
            extra.reset();
            rep = -1;
        }

        void setRep(int u) {rep = u;}
        int getRep() {return rep;}

        void insertNonExtra (pair<int, int> e) {non_extra.insert(e);}
        void insertExtra (pair<int, int> e) {extra.insert(e);}

        void append(Comp c) {
            non_extra.append(c.non_extra);
            extra.append(c.extra);
        }

        int numExtra() {return extra.getSize();}
        int numEdges() {return non_extra.getSize() + extra.getSize();}

        pair<int, int> popNonExtra () {
            return non_extra.pop();
        }

        pair<int, int> popExtra () {
            return extra.pop();
        }
};

class UnionFind {
    private:
        vector<int> rank, p;
        vector<Comp> c;
    public:
        void reset(int n) {
            rank.clear();
            p.clear();
            p.resize(n);
            c.clear();
            c.resize(n);

            rank.assign(n, 0);
            for(int i = 0;i < n;i++) {
                p[i] = i;
                c[i].setRep(i);
            } 
        }
    
        UnionFind() {}

        UnionFind(int n) {
            reset(n);
        }
        
        ~UnionFind() {}        

        int findSet(int x) {
            int repx = x, u;

            while(p[repx] != repx)
                repx = p[repx];

            while(p[x] != x) {
                u = p[x];
                p[x] = repx;
                x = u;
            }

            return repx;
        }

        bool isSame(int u, int v) {
            return findSet(u) == findSet(v);
        }

        void unionSet(int u, int v) {
            int pu = findSet(u), pv = findSet(v);

            if(pu == pv) {
                c[pu].insertExtra({u, v});
                return;
            }
            
            int node, parent;
            if(rank[pu] > rank[pv]) {
                parent = pu;
                node = pv;
            }
            else if(rank[pu] < rank[pv]) {
                parent = pv;
                node = pu;
            }
            else {
                parent = pu;
                node = pv;
                rank[pu] ++;
            }

            p[node] = parent;
            c[parent].append(c[node]);
            c[parent].insertNonExtra({u, v});
        }

        inline int isRoot(int u) {return p[u] == u;}

        Comp getComp(int u) {return c[u];}
};

UnionFind ufds;
int n, m;
Comp nonTree;
vector<Comp> tree;
vector<int> singleton;
vector<pair<int, int> > chosenEdges;
bool foundNonTree;
int cost;

void readInput() {
    scanf("%d %d ", &n, &m);
    ufds.reset(n);

    for(int i = 0;i < m;i++) {
        int u, v;
        scanf("%d %d ", &u, &v);
        u --, v --;
        ufds.unionSet(u, v);
    }
}

void mergeWithNonTree(Comp &c) {
    pair<int, int> ex1 = nonTree.popExtra();
    pair<int, int> ex2 = c.popExtra();

    nonTree.append(c);
    nonTree.insertExtra({ex1.first, ex2.first});
    nonTree.insertNonExtra({ex1.second, ex2.second});
}

void mergeTree() {
    for(int i = 0;i < tree.size();i++) {
        if(!foundNonTree || nonTree.numExtra() == 0) {
            int a = nonTree.getRep();
            int b = tree[i].getRep();

            nonTree.insertNonExtra({a, b});
            nonTree.append(tree[i]);
            cost += 2;
        }
        else {
            pair<int, int> e1 = nonTree.popExtra();
            pair<int, int> e2 = tree[i].popNonExtra();
            nonTree.insertNonExtra({e1.first, e2.first});
            nonTree.insertNonExtra({e1.second, e2.second});
            nonTree.append(tree[i]);
        }
    }
}

void mergeSingleton() {
    if(static_cast<int>(singleton.size()) % 2 == 1) {
        int a = nonTree.getRep();
        int b = singleton[singleton.size() - 1];
        singleton.pop_back();

        nonTree.insertNonExtra({a, b});
        cost += 2;
    }

    int i = 0;
    while(i < singleton.size()) {
        if(!foundNonTree || nonTree.numExtra() == 0) {
            int a = nonTree.getRep();
            int b = singleton[i];

            nonTree.insertNonExtra({a, b});
            cost += 2;

            i ++;
        }
        else {
            pair<int, int> e = nonTree.popExtra();
            int a = singleton[i];
            int b = singleton[i + 1];

            nonTree.insertNonExtra({e.first, a});
            nonTree.insertNonExtra({e.second, b});
            cost += 2;

            i += 2;
        }
    }
}

void solve() {
    cost = 0;
    nonTree.reset();
    tree.clear();
    singleton.clear();
    chosenEdges.clear();
    
    foundNonTree = false;
    for(int u = 0;u < n;u++) {
        if(ufds.isRoot(u)) {
            Comp c = ufds.getComp(u);
            if(c.numEdges() == 0)
                singleton.push_back(u);
            else if(c.numExtra() == 0)
                tree.push_back(c);
            else {
                if(!foundNonTree) {
                    nonTree = c;
                    foundNonTree = true;
                }
                else
                    mergeWithNonTree(c);
            }
        }
    }

    if(!foundNonTree) {
        if(tree.size() > 0) {
            nonTree = tree[tree.size() - 1];
            tree.pop_back();
        }
        else {
            nonTree.reset();
            nonTree.setRep(singleton[singleton.size() - 1]);
            singleton.pop_back();
        }
    }

    mergeTree();
    mergeSingleton();

    printf("%d %d\n", cost, nonTree.numEdges());
    while(nonTree.numExtra() > 0) {
        pair<int, int> e = nonTree.popExtra();
        printf("%d %d\n", e.first + 1, e.second + 1);
    }
    while(nonTree.numEdges() > 0) {
        pair<int, int> e = nonTree.popNonExtra();
        printf("%d %d\n", e.first + 1, e.second + 1);
    }
}

int main() {
    int t;
    scanf("%d ", &t);
    while(t --) {
        readInput();
        solve();
    }
    return 0;
}