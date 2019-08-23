#include<iostream>

using namespace std;

const int CHAR_SIZE = 128;

class Trie
{
    public:

    bool isWord;
    Trie *character[CHAR_SIZE];
    
    Trie()
    {
        this->isWord = false;
        for(int i = 0;i < CHAR_SIZE;i++)
            this->character[i] = nullptr;
    }
};

void insert(Trie* &node, string key)
{
    if(node == nullptr)
        node = new Trie();
    
    Trie *curr = node;

    for(char x : key)
    {
        if(curr->character[x] == nullptr)
            curr->character[x] = new Trie();
        
        curr = curr->character[x];
    }

    curr->isWord = true;
}

bool search(Trie* curr, string key)
{
    if(curr == nullptr)
        return false;

    for(char x : key)
    {
        if(curr->character[x] == nullptr)
            return false;
        curr = curr->character[x];
    }

    return curr->isWord;
}

bool hasChildren(Trie* curr)
{
    for(int i = 0;i < CHAR_SIZE;i++)
    {
        if(curr->character[i] != nullptr)
            return true;
    }
    return false;
}

bool deletion(Trie* &curr, int idx, const string &key)
{
    if(curr == nullptr)
        return false;
    
    if(idx == key.size())
    {
        if(!hasChildren(curr))
        {
            delete curr;
            curr = nullptr;
            return true;
        }
        else
        {
            curr->isWord = false;
            return false;
        }
    }

    if(deletion(curr->character[key[idx]], idx + 1, key) && curr->isWord == false && hasChildren(curr) == false)
    {
        delete curr;
        curr = nullptr;
        return true;
    }

    return false;
}


void solve()
{
    Trie *root = nullptr;
    int q, no;
    cin>>q;
    string s;

    while(q--)
    {
        cin>>no>>s;
        if(no == 0)             // insert
            insert(root, s);
        else if(no == 1)        // searcg
        {
            if(search(root, s))
                cout<<s<<" is present\n";
            else
                cout<<s<<" is not present\n";
        }
        else if(no == 2)
        {
            if(search(root, s))
                deletion(root, 0, s);
        }
    }
}

int main()
{
    solve();
    return 0;
}

