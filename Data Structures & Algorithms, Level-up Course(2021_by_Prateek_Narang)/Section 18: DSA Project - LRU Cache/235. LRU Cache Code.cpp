// STL containers list and unordered_map is used to implement LRU Cache
 
#include<iostream>
#include<list>
#include<unordered_map>
using namespace std; 
 
// Node to store the data (Linked List)
class Node{
public:
	string key;
	int value;
 
	Node(string key, int value){
		this->key = key;
		this->value = value;
	}
};
 
// LRU Cache Data Structure
class LRUCache{
public:
	int maxSize;
	list<Node> l;
	unordered_map<string,list<Node>::iterator> m;	// this ways you can get the address of STL container object
 
	LRUCache(int maxSize){
		this->maxSize = maxSize > 1 ? maxSize : 1;
	}
 
	void insertKeyValue(string key, int value){
		// 2 cases
		// 1. Update : check if key is already present
		if(m.count(key) > 0){
			// replace the old value and update
			list<Node>::iterator it = m[key];
			it->value = value;
		}
		else{ // 2. Insert new key 
			
			// 2.a check if Cache is full or not
			// remove the least recently used item from cache
			if(l.size() == maxSize){
				// delete the last node 
				Node last = l.back();
				m.erase(last.key);	// remove from hashmap
				l.pop_back();	// remove from the linked list
			}
			
			Node newNode(key,value);
			l.push_front(newNode);
			m[key] = l.begin();
		}
	}
 
	int *getValue(string key){
		if(m.count(key) > 0){
			auto it = m[key];
 
			int value =  it->value;
			l.push_front(*it);
			l.erase(it);
			m[key] = l.begin();
			return &l.begin()->value;
		}
		return NULL;
	}
 
	string mostRecentKey(){
		return l.front().key;
	}
};
 
int main(){
	LRUCache lru(3);
	lru.insertKeyValue("mango",10);
	lru.insertKeyValue("apple",20);
	lru.insertKeyValue("guava",30);
 
	lru.insertKeyValue("mango",40);
	
	cout<<lru.mostRecentKey()<<endl;
 
	int *orders = lru.getValue("mango");
	if(orders!=NULL){
		cout<<"Order of Mango "<<*orders<<endl;
	}
 
	lru.insertKeyValue("banana",20);
 
	if(lru.getValue("apple") == NULL){
		cout<<"apple doesn't exist"<<endl;
	}
 
	if(lru.getValue("guava") == NULL){
		cout<<"guava doesn't exist"<<endl;
	}
 
	if(lru.getValue("banana") == NULL){
		cout<<"banana doesn't exist"<<endl;
	}
 
	if(lru.getValue("mango") == NULL){
		cout<<"mango doesn't exist"<<endl;
	}
}
