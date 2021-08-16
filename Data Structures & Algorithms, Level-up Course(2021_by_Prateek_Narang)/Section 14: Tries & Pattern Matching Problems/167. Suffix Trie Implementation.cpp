// Time - Insert = O(N^2*W) , Search = O(W), Space = (nC2 = N^2)

#include<iostream>
#include<unordered_map>
using namespace std;
 
class Node{
public:
    char data;
    unordered_map<char,Node*>children; // hash map by default is empty
    bool isTerminal;
 
    Node(char d){
        data = d;
        isTerminal = false;
    }
};
 
class SuffixTrie{
public:
    Node *root;
 
    SuffixTrie(){
        root = new Node('\0');
    }
 
    void insert_helper(string word){
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
    
    void insert(string word){
        // pick all the substrings from (i,eos) and call insert_helper
        for(int i=0; word[i]!='\0'; i++){
            insert_helper(word.substr(i));
        }
    }
 
    bool search(string word){
        Node *temp = root;
        
        for(char ch : word){
            if(temp->children.count(ch)==0){
                return false;
            }
            temp = temp->children[ch];
        }
        
        return temp->isTerminal;
    }
};
 
int main(){
    string input = "hello";
    string suffixes[] = {"lo", "ell", "hello"};
    
    SuffixTrie t;
    t.insert(input);
    
    for(auto suffix : suffixes){
        if(t.search(suffix)){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
