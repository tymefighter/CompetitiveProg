#include<iostream>
#include<cassert>

using namespace std;

class Node
{
    public:
    char val;
    Node *left, *right;

    Node(char u)
    {
        val = u;
        left = right = NULL;
    }
};

int n;
string preord, inord;

Node *getTree(int p_start, int p_end, int i_start, int i_end)
{
    char u = preord[p_start];
    Node *node = new Node(u);

    int p_t1_start, p_t1_end, p_t2_start, p_t2_end;
    int i_t1_start, i_t1_end, i_t2_start, i_t2_end;

    int j;
    for(j = i_start;j <= i_end;j++)
    {
        if(inord[j] == u)
        {
            j --;
            break;
        }
    }
    i_t1_start = i_start;
    i_t1_end = j;

    i_t2_start = i_t1_end + 2;
    i_t2_end = i_end;

    p_t1_start = p_start + 1;
    p_t1_end = p_t1_start + (i_t1_end - i_t1_start);

    p_t2_start = p_t1_end + 1;
    p_t2_end = p_end;

    if(i_t1_start <= i_t1_end)
        node->left = getTree(p_t1_start, p_t1_end, i_t1_start, i_t1_end);
    
    if(i_t2_start <= i_t2_end)
        node->right = getTree(p_t2_start, p_t2_end, i_t2_start, i_t2_end);

    return node;
}

void postOrder(Node *node)
{
    if(node == NULL)
        return;
    
    postOrder(node->left);
    postOrder(node->right);
    cout<<node->val;
}

void solve()
{
    n = preord.size();
    assert(n == inord.size());

    Node *tree = getTree(0, n - 1, 0, n - 1);
    postOrder(tree);
    cout<<"\n";
}

int main()
{
    while(cin>>preord>>inord)
        solve();
    return 0;
}
