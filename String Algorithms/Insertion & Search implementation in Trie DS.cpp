// Insertion & Search implementation in Trie DS

// Whenever we're going to Insert or Search.
// We're always start with root node.

// In Insertion, If node is already exists, Then we move on pointer to that node.
// else, we first create the node, then move to it pointer to node.

#include <bits/stdc++.h>
#define REP(i, n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define endl '\n'
#define INF 1000000000
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL)

using namespace std;

const int SIZE = 26;

struct node
{
    bool endOfWord;
    node *ar[SIZE];
};

node *getNode()
{
    node *n = new node;

    for (int i = 0; i < SIZE; i++)
        n->ar[i] = NULL;

    n->endOfWord = false;

    return n;
}

void insert(node *root, string st)
{
    // We're creating the copy of root because we don't want root to be changed
    node *tempRoot = root;

    for (int i = 0; i < st.size(); i++)
    {

        int index = st[i] - 'a';

        if (tempRoot->ar[index] == NULL)
            tempRoot->ar[index] = getNode();

        tempRoot = tempRoot->ar[index];
    }
    tempRoot->endOfWord = true;
}

bool search(node *root, string st)
{

    node *tempRoot = root;

    for (int i = 0; i < st.size(); i++)
    {

        int index = st[i] - 'a';

        if (tempRoot->ar[index] == NULL)
            return false;

        tempRoot = tempRoot->ar[index];
    }
    return tempRoot->endOfWord;
}

int main()
{

    node *root = getNode();

    int t, code;
    string st;

    cin >> t;

    while (t--)
    {
        cin >> code;

        if (code == 1)
        {
            cout << "Enter the string to be inserted" << endl;
            cin >> st;
            insert(root, st);
        }
        else if (code == 2)
        {
            cout << "Enter the string to be searched" << endl;
            cin >> st;
            cout << search(root, st) << endl;
        }
    }

    return 0;
}