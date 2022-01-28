// https://leetcode.com/problems/design-add-and-search-words-data-structure/

// Medium

// Tags - Prefix Trie, DFS(Recursion)

// What this problem wants to teach me?
// How to use Trie with DFS
// In a question, If you're facing difficuly for implementing a particular condition...
// Then, in such cases first write the code for other easy conditions and Then try to write the code for
// tougher condition and make modifications/modularization in code along the way while writing the code
// Conclusion - don't just only think...sometimes you're able to write the code along the way 

#include<bits/stdc++.h>
using namespace std;

// Prefix Trie, DFS(Recursion) | Time - O(W)-insertion, Space - O(N*W) , where N==total no. of queries, W == key.length
// Time - O(W) - for searching in best case, O(26^W) - for searching in worst case 
class Node{
public:
    char data;
    unordered_map<char, Node*> children;
    bool endOfWord;
    
    Node(char data){
        this->data = data;
        this->endOfWord = false;
    }
};

class WordDictionary {
private:
    Node* root;
public:
    WordDictionary() {
        root = new Node('\0');        
    }
    
    void addWord(string word) {
        Node* currNode = root;
        
        for(char& ch: word){
            if(currNode->children.count(ch)==0){
                currNode->children[ch] = new Node(ch);
            }
            
            currNode = currNode->children[ch];
        }
        
        currNode->endOfWord = true;
    }
    
    bool search(string word) {
        return dfs(word,0,root);
    }

private:
    bool dfs(string word, int idx, Node* root){
        Node* currNode = root;
        
        for(int i=idx; i<word.length(); i++){
            char ch = word[i];
            
            if(ch == '.'){
                for(auto& [ch, nextNode] : currNode->children){
                    if(dfs(word, i+1, nextNode)==true)
                        return true;
                }
                
                return false;
            }
            else{
                if(currNode->children.count(ch)==0)
                    return false;
                else 
                    currNode = currNode->children[ch];
            }
        }
        
        return currNode->endOfWord;
    }
};