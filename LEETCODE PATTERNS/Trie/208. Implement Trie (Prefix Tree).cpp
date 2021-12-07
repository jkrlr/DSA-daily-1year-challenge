// https://leetcode.com/problems/implement-trie-prefix-tree/

// Medium

// What this problem wants to teach me?
// How to implement Prefix Trie

#include<bits/stdc++.h>
using namespace std;

// Total queries Search-Time = O(q*W), Space = O(N), W-maxLen of query, N = Total Trie Nodes

class Node{
public:
    char data;
    unordered_map<char, Node*> children;
    bool endOfWord;
    
   Node(char d){
       data = d;
       endOfWord = false;
   }
};

class Trie {
public:
    Node* root;
    
    Trie() {
        root = new Node('\0');
    }
    
    // Time - O(keyLength)
    void insert(string word) {
        Node* temp = root;
        
        for(char ch: word){
            if(temp->children.count(ch)==0){
                Node* newNode = new Node(ch);
                temp->children[ch] = newNode;
            }
            
            temp = temp->children[ch];
        }
        
        temp->endOfWord = true;
    }
    
    // Time - O(keyLength)
    bool search(string word) {
        Node* temp = root;
        
        for(char ch: word){
            if(temp->children.count(ch)==0){
                return false;
            }
            
            temp = temp->children[ch];
        }
        
        return temp->endOfWord;
    }
    
    // Time - O(keyLength)
    bool startsWith(string prefix) {
        Node* temp = root;
        
        for(char ch: prefix){
            if(temp->children.count(ch)==0){
                return false;
            }
            
            temp = temp->children[ch];
        }
        
        return true;
    }
};