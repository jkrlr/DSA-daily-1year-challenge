// https://leetcode.com/problems/word-search-ii/

// Hard

// What this problem wants to teach me?
// We can use Trie to optimize String Matching query problems
// Sometimes it is better to store ending word in trie also
// If multiples copies of word is given, Then we can store the cntOfWord int instead of endOfWord boolean
// When the input size is big and the query size is small or or
// When the input size is small i.e upto 10^2(but iterating it to find the matching query is very-very costly) and query size is mid i.e. upto 10^4 and keyLength<=10to20
// Then, in such cases most of the time it's better to insert the query strings into the Trie and
// Then, Apply reverse engineer on the given input and check whether the given input matches with the Trie of queries or not

#include<bits/stdc++.h>
using namespace std;

// Trie + DFS(Recursion + Backtracking) | Time - O(mn*mn*keyLength), Space - O(T) , T = TreeNode or (Size of Query Vector * KeyLength)

class Node{
public:
    char data;
    unordered_map<char,Node*> children;
    bool endOfWord;
    string word;
    
    Node(char d){
        data = d;
        endOfWord = false;
        word = "";
    }
};

class Trie{
 public:
    Node* root;
    
    Trie(){
        root = new Node('\0');
    }
    
    void insert(string& word){
        Node* temp = root;
        
        for(char ch: word){
            if(temp->children.count(ch)==0){
                Node* newNode = new Node(ch);
                temp->children[ch] = newNode;
            }
            
            temp = temp->children[ch];
        }
        
        temp->endOfWord = true;
        temp->word = word;
    }
};

class Solution {
private:
    void dfs(vector<vector<char>>& board, int row, int col, int& m, int& n, Node* curr, vector<string>& result){
        // base case
        if(row<0 || row>=m || col<0 || col>=n || board[row][col]=='#' || curr->children.count(board[row][col])==0){
            return;
        }
        
        // recursive case
        char ch = board[row][col];
        board[row][col] = '#';      // mark the current cell as visited
        curr = curr->children[ch];
        
        // check if current char is ending of a word or not
        if(curr->endOfWord){
            result.push_back(curr->word);
            curr->endOfWord = false;        // because all words are unique;
        }
        
        dfs(board,row-1,col,m,n,curr, result);    // Top
        dfs(board,row+1,col,m,n,curr, result);    // Down
        dfs(board,row,col-1,m,n,curr, result);    // Left
        dfs(board,row,col+1,m,n,curr, result);    // Right
        
        board[row][col] = ch;
    }
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        // Insert all the nodes in Trie
        Trie t;
        for(auto& word: words){
            t.insert(word);
        }
        
        // Search for answer
        vector<string> result;
        int m = board.size();
        int n = board[0].size();
        
        for(int row=0; row<m; row++){
            for(int col = 0; col<n; col++){
                dfs(board,row,col,m,n,t.root,result);
            }
        }        
        return result;
    }
};