// Time : O(N*W + D*W), Space = O(N*W)
 
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Node{
public:
   char data;
   unordered_map<char,Node*>children;
   bool isTerminal;
   Node(char d){
       // hash map by default is empty - no need to initialize it
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
      
       for(char ch: word){
           if(temp->children.count(ch)==0){
               Node *newNode = new Node(ch);
               temp->children[ch] = newNode;
           }
           temp = temp->children[ch];
       }
       temp->isTerminal = true;
   }
};

void searchHelper(string document, Trie t, unordered_map<string,bool> &m, int start){
    Node *temp = t.root;

    for (int end = start; end < document.length(); end++){
        char ch = document[end];

        if (temp->children.count(ch)==0){
            return;
        }

        temp = temp->children[ch];

        if (temp->isTerminal){
            // history part
            string key = document.substr(start, end - start + 1);
            m[key] = true;
        }
    }

    return;
}

void documentSearch(string document,vector<string> words){
    
    // 1. Create a trie of words
    Trie t;
    for(auto word : words){
        t.insert(word);
    }

    // 2. Searching (Helper Fn)
    unordered_map<string, bool> m;
    for (int i = 0; i < document.length(); i++){
        searchHelper(document, t, m, i);
    }

    // 3. You can check which word are marked as True inside the Hashmap
    for(auto word : words){
        if(m[word]==true){
            cout << word <<" : True" << endl;
        }
        else{
            cout << word << " : False" << endl;
        }
    }
}

int main(){
    string document = "little cute cat loves to code in c++, java & python";
    vector<string> words = {"cute cat", "ttle", "cat", "quick", "big"};

    documentSearch(document, words);
    return 0;
}
