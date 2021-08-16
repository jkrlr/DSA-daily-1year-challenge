// Time : Insert,Search - O(KeyLength), Space = O(N)
// Delete funtion of trie - implement it by yourself

#include<iostream>
#include<unordered_map>
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
	string words[] = {"apple", "ape", "no", "news", "not", "never"};
	Trie t;
	for(auto word : words){
		t.insert(word);
	}
	
	int q;
	cin>>q;
 
	string search_word;
	while(q--){
		cin>>search_word;
		if(t.search(search_word)){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
}
