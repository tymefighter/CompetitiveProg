#include<iostream>

using namespace std;

const int NCHAR = 256;
class Node;
class Trie;

class Node {
    private:
        bool isEndOfWord;
        Node *children[NCHAR];
    public:
        Node():
            isEndOfWord(false) {
                for(int i = 0;i < NCHAR;i++)
                    children[i] = nullptr;
            }
        
        ~Node() {}

        friend class Trie;
};

class Trie {
    private:
        Node *root;

        inline int char2int(char c) {return static_cast<int>(c);}

        bool hasNonNullChild(Node *node) {
            for(int i = 0;i < NCHAR;i++) {
                if(node->children[i] != nullptr)
                    return true;
            }
            return false;
        }

        void deleteSubtree(Node *node) {
            if(node == nullptr)
                return;

            for(int i = 0;i < NCHAR;i++)
                deleteSubtree(node->children[i]);

            delete node;
        }

        void insertString(Node *node, int i, const string &s) {
            if(i == s.size()) {
                node->isEndOfWord = true;
                return;
            }

            if(node->children[char2int(s[i])] == nullptr)
                node->children[char2int(s[i])] = new Node();

            insertString(node->children[char2int(s[i])], i + 1, s);
        }

        bool searchString(Node *node, int i, const string &s) {
            if(i == s.size())
                return node->isEndOfWord;

            if(node->children[char2int(s[i])] == nullptr)
                return false;

            return searchString(node->children[char2int(s[i])], i + 1, s);
        }

        bool deleteString(Node *node, int i, const string &s) {
            if(i == s.size()) {
                if(!node->isEndOfWord) // string not present
                    return false;

                node->isEndOfWord = false;
                if(hasNonNullChild(node))
                    return false;
                else {
                    delete node;
                    return true;
                }
            }

            // string not present
            if(node->children[char2int(s[i])] == nullptr)
                return false;

            // unable to delete child
            if(!deleteString(node->children[char2int(s[i])], i + 1, s))
                return false;

            node->children[char2int(s[i])] = nullptr; // nullify child
            if(!node->isEndOfWord && !hasNonNullChild(node)) { // can delete
                delete node;
                return true;
            }

            return false;
        }

    public:
        Trie():
            root(nullptr) {}

        ~Trie() {deleteSubtree(root);}

        void insertString(const string &s) {
            if(root == nullptr)
                root = new Node();

            insertString(root, 0, s);
        }

        bool searchString(const string &s) {
            if(root == nullptr)
                return false;

            return searchString(root, 0, s);
        }

        void deleteString(const string &s) {
            if(deleteString(root, 0, s))
                root = nullptr;
        }
};

void processOp() {
    string query;
    Trie trie;

    while(cin >> query) {
        if(query == "done") break;

        string s;
        cin >> s;
        if(query == "insert")
            trie.insertString(s);
        else if(query == "search")
            cout
                << (trie.searchString(s) ? "Present" : "Not Present")
                << "\n";
        else if(query == "delete")
            trie.deleteString(s);
    }
}

int main() {
    processOp();
    return 0;
}