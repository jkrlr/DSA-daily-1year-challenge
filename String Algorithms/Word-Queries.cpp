// Word Queries[Hackerearth : Solved using Trie DS]
// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/practice-problems/algorithm/dummy4-2/

/*Problem Statement :
You will get a list of words and some queries. 
You will be asked, to find out how many words in the list have a query word as a prefix.*/

// Time Complexity = O(q*logN) or O(n*logN) -> N is total number of nodes in tree. 
// Space Complexity = O(N)

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
    int wordCount;
    node *ar[SIZE];
};

node *getNewNode()
{
    node *n = new node;

    for (int i = 0; i < SIZE; i++)
        n->ar[i] = NULL;

    n->endOfWord = false;
    n->wordCount = 0;

    return n;
}

void insert(node *root, string st)
{
    node *tempRoot = root;

    for (int i = 0; i < st.size(); i++)
    {

        int index = st[i] - 'a';

        if (tempRoot->ar[index] == NULL)
            tempRoot->ar[index] = getNewNode();

        tempRoot = tempRoot->ar[index];
        tempRoot->wordCount++;
    }
    tempRoot->endOfWord = true;
}

int search(node *root, string qst)
{
    node *tempRoot = root;

    for (int i = 0; i < qst.size(); i++)
    {

        int index = qst[i] - 'a';

        if (tempRoot->ar[index] == NULL)
            return 0;

        tempRoot = tempRoot->ar[index];
    }
    return tempRoot->wordCount;
}

int main()
{
    node *root = getNewNode();
    int n, q;
    string st, qst;

    cin >> n >> q;

    for (int i = 0; i < n; i++)
    {
        cin >> st;
        insert(root, st);
    }

    for (int i = 0; i < q; i++)
    {
        cin >> qst;
        cout << search(root, qst) << endl;
    }

    return 0;
}
