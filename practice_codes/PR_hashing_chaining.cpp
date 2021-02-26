#include<iostream>
#include<vector>
#include<random>
#include<cmath>

using namespace std;

enum HashFunctionSelect {DIV, MUL, UNIV};

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

class DivisionMethod : public HashFunction {
    private:
        int m;
    public:
        DivisionMethod(int m_):
            m(m_) {}

        ~DivisionMethod() {}

        inline long long h(long long k) {
            k %= m;
            if(k < 0)
                k += m;
            return k;
        }
};

class MultiplicationMethod : public HashFunction {
    private:
        double A;
        int m;
    public:
        MultiplicationMethod(double A_, int m_):
            A(A_),
            m(m_) {}

        ~MultiplicationMethod() {}

        inline long long h(long long k) {
            double val = k * A;
            long long fracPart = val - floor(val);
            return m * fracPart;
        }
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

class Node {
    private:
        long long key;
        Node *next;
    public:
        Node(long long key_):
            key(key_),
            next(nullptr) {}

        ~Node() {}

        friend class HashTable;
};

class HashTable {
    private:
        int m;
        HashFunction *hf;
        vector<Node *> table;

    public:
        HashTable(HashFunctionSelect hfSelect, int tableSize):
            m(tableSize),
            table(m, nullptr) {
                if(hfSelect == DIV)
                    hf = new DivisionMethod(m);
                else if(hfSelect == MUL)
                    hf = new MultiplicationMethod((sqrt(5) - 1) / 2, m);
                else if(hfSelect == UNIV)
                    hf = new UniversalHashing(1000000007, m);
                else
                    throw *(new HashError ("Invalid Hash Function"));
            }

        ~HashTable() {delete hf;}

        bool searchKey(long long key) {
            Node *node = table[hf->h(key)];
            
            while(node != nullptr) {
                if(node->key == key)
                    return true;

                node = node->next;
            }

            return false;
        }

        bool deleteKey(long long key) {
            long long idx = hf->h(key);
            Node *node = table[idx];

            if(node == nullptr)
                return false;

            if(node->key == key) {
                table[idx] = node->next;
                delete node;
                return true;
            }

            Node *prev = node;
            node = node->next;
            while(node != nullptr) {
                if(node->key == key) {
                    prev->next = node->next;
                    delete node;
                    return true;
                }

                prev = node;
                node = node->next;
            }

            return false;
        }

        bool insertKey(long long key) {
            if(searchKey(key))
                return false;

            long long idx = hf->h(key);

            Node *node = new Node(key);
            node->next = table[idx];
            table[idx] = node;
            return true;
        }
};

void processOp() {
    int tableSize;
    string hashFunctionSelect;
    cin >> hashFunctionSelect >> tableSize;
    HashFunctionSelect hfSelect;

    if(hashFunctionSelect == "div")
        hfSelect = DIV;
    else if(hashFunctionSelect == "mul")
        hfSelect = MUL;
    else if(hashFunctionSelect == "univ")
        hfSelect = UNIV;
    else {
        cout
            << "Invalid Hash Function\n"
            << "Terminating\n";

        return;
    }

    HashTable table(hfSelect, tableSize);
    string query;

    while(cin >> query) {
        if(query == "done") break;

        long long key;
        cin >> key;

        if(query == "insert") (void) table.insertKey(key);
        else if(query == "search")
            cout 
                << (table.searchKey(key) ? "Key present" : "Key not present")
                << "\n";
        else if(query == "delete") (void) table.deleteKey(key);
    }
}

int main() {
    processOp();
    return 0;
}