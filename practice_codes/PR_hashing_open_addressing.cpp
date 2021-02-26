#include<iostream>
#include<vector>
#include<random>
#include<cmath>

using namespace std;

class HashError {
    private:
        string err;
    public:
        HashError(const string err_):
            err(err_) {}

        ~HashError() {}

        inline string get() {return err;}
};

class HashFunction {
    public:
        HashFunction() {}

        virtual ~HashFunction() {}

        virtual long long h(long long) = 0;
};

class UniversalHashing : public HashFunction {
    private:
        long long p, a, b;
        int m;
        default_random_engine generator;
    public:
        UniversalHashing(long long p_, int m_):
            p(p_),
            m(m_) {
                uniform_int_distribution<long long> dist_a(1, p - 1);
                uniform_int_distribution<long long> dist_b(0, p - 1);
                a = dist_a(generator);
                b = dist_b(generator);
            }

        ~UniversalHashing() {}

        inline long long h(long long k) {
            return ((a * k + b) % p) % m;
        }
};

class HashFuncSeq {
    public:
        HashFuncSeq() {}

        virtual ~HashFuncSeq() {}

        virtual long long h(long long key, int i) = 0;
};

class LinearProbing : public HashFuncSeq {
    private:
        int m;
        HashFunction *hf;
    public:
        LinearProbing(int m_):
            m(m_),
            hf(new UniversalHashing(1000000007, m)) {}

        ~LinearProbing() {delete hf;}

        inline long long h(long long key, int i) {
            return (hf->h(key) + i) % m;
        }
};

class HashTable {
    private:
        int m;
        HashFuncSeq *hfSeq;
        vector<pair<bool, long long> > table;

    public:
        HashTable(int tableSize):
            m(tableSize),
            hfSeq(new LinearProbing(m)),
            table(m, {false, 0}) {}
        
        ~HashTable() {delete hfSeq;}

        bool insertKey(long long key) {
            for(int i = 0;i < m;i++) {
                long long idx = hfSeq->h(key, i);
                if(!table[idx].first) {
                    table[idx] = {true, key};
                    return true;
                }
            }

            return false;
        }

        bool searchKey(long long key) {
            for(int i = 0;i < m;i++) {
                long long idx = hfSeq->h(key, i);
                if(!table[idx].first)
                    return false;

                if(table[idx].second == key)
                    return true;
            }

            return false;
        }
};

void processOp() {
    int tableSize;
    cin >> tableSize;
    HashTable table(tableSize);

    string query;

    while(cin >> query) {
        if(query == "done") break;

        long long key;
        cin >> key;

        if(query == "insert") {
            if(!table.insertKey(key))
                cout << "Table Full\n";
        }
        else if(query == "search") {
            cout 
                << (table.searchKey(key) ? "Key present" : "Key not present")
                << "\n";
        }
    }
}

int main() {
    processOp();
    return 0;
}