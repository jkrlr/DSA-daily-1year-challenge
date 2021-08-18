// Time = O(N^3), Space = (N*W) ; N= input.size(), W = input[i].length()

// Hash map can solve this problem in N^3 same as trie for smaller input
// But for larger input due to more no. of collisions hashmap complexity is worse than Trie due to more no. of re-Hashing

// Suffix Trie is not used - because we've to exactly match the complete strings

// Problem is quite similar to Hashing Section problems. - 163. Quick Brown Fox or coding exercise 49. Minimum Bars

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    char data;
    unordered_map<char, Node *> children;
    bool isTerminal;

    Node(char d){
        data = d;
        isTerminal = false;
    }
};

class Trie{
public:
    Node *root;

    Trie(){
        root = new Node('\0');
    }

    void insert(string word){
        Node *temp = root;

        for(char ch : word){
            if(temp->children.count(ch)==0){
                temp->children[ch] = new Node(ch);
            }
            temp = temp->children[ch];
        }
        temp->isTerminal = true;
    }
};

int searchHelper(Node *root, string word, int start){
    // base case
    if(word[start]=='\0'){
        return 0;
    }

    // recursive case
    Node *temp = root;
    int ans = INT_MIN;
    for (int i = start; i < word.size() && (temp->children.count(word[i]) > 0); i++){
        temp = temp->children[word[i]];
        
        if(temp->isTerminal){
            int remainingSubproblem = searchHelper(root, word, i + 1);

            if(remainingSubproblem!=INT_MIN){
                ans = max(ans, 1 + remainingSubproblem);
            }
        }
    }

    return ans;
}

//Function should return a vector of googly strings
vector<string> googlyStrings(vector<string> input){
    Trie t;

    // 1. Insert all inp. str into Trie
    for(auto word : input){
        t.insert(word);
    }

    // 2. Find Googly String
    vector<string> res;
    for (auto word : input){
        int start = 0;

        int strCnt = searchHelper(t.root, word, start);
        if (strCnt >= 2){   // curr_string is made up of exactly greater than 2 strings
            res.push_back(word);
        }
    }

    return res;
}
