// Time = O(M*N + n*w), Space = O(n*w + M*N)

#include <bits/stdc++.h>
using namespace std;

#define M 3
#define N 4

class Node
{
public:
    char data;
    unordered_map<char, Node *> children;
    bool isTerminal;
    string word;

    Node(char data)
    {
        this->data = data;
        isTerminal = false;
        word = "";
    }
};

class Trie
{
public:
    Node *root;

    Trie()
    {
        root = new Node('\0');
    }

    void addWord(string word)
    {
        Node *temp = root;

        for (char ch : word)
        {
            if (temp->children.count(ch) == 0)
            {
                temp->children[ch] = new Node(ch);
            }
            temp = temp->children[ch];
        }
        // last node
        temp->isTerminal = true;
        temp->word = word;
    }
};

// main algorithm (8-way dfs + trie guided search)
void dfs(char board[M][N], Node *node, int row, int col, bool visited[][N], unordered_set<string> &output)
{
    // base case
    char ch = board[row][col];
    if (node->children.count(ch) == 0)
    {
        return;
    }

    // otherwise trie contains this node
    visited[row][col] = true;
    node = node->children[ch];

    // If it is terminal node in the trie
    if (node->isTerminal)
    {
        output.insert(node->word);
        // we shouldn't return from here - explore other nodes in same trie branch because this word can be prfix for multiple words
    }

    // explore the neighbours
    int dx[] = {0, 1, 1, 1, 0, -1, -1,-1};
    int dy[] = {-1,-1,0, 1, 1, 1, 0, -1};

    for (int k = 0; k < 8; k++)
    {
        int nRow = row + dx[k];
        int nCol = col + dy[k];

        // if it is in bound and is not visited
        if (nRow >= 0 && nRow < M && nCol >= 0 && nCol < N && visited[nRow][nCol] == false)
        {
            dfs(board, node, nRow, nCol, visited, output);
        }
    }

    // last step (backtracking)
    visited[row][col] = false;
    return;
}

int main()
{
    string words[] = {"SNAKE", "FOR", "QUEZ", "SNACK", "SNACKS", "SENS", "TUNES", "CAT"};

    char board[M][N] = {
        {'S', 'E', 'R', 'T'},
        {'U', 'N', 'K', 'S'},
        {'T', 'C', 'A', 'T'}};

    //1. Trie
    Trie t;
    for (auto word : words)
    {
        t.addWord(word);
    }

    // 2. Take a container to store words that found in dfs
    // what container you should choose, list, vector, map or set?
    // Ans - unordered_set => because in dfs same word can be formed in multiply ways
    // To avoid duplicates - unordered_set is used
    unordered_set<string> output;

    // 3. 8-way dfs from every cell
    bool visited[M][N] = {0};
    for (int row = 0; row < M; row++)
    {
        for (int col = 0; col < N; col++)
        {
            dfs(board, t.root, row, col, visited, output);
            // reset the visited aray after every call(while backtracking can also do this)
        }
    }

    // 4. print the output
    for (auto word : output)
    {
        cout << word << endl;
    }
    return 0;
}
