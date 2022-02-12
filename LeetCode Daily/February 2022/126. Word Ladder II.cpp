// https://leetcode.com/problems/word-ladder-ii/

// Hard[Revision]

// Tags - Hash Table - Unordered_Map, Unordered_Set, BFS-Shortest Path from src to Dest, DFS-Backtracking, String

// What this problem wants to teach me?
// In case of unorderd_map we have key of basic data type 
// but we can put the value as any complex data structure or any user defined class type
// How to use unordered_map to create the graph, if data types are string
// Another variation of graph problem having tougher implementation

#include<bits/stdc++.h>
using namespace std;

//  Hash Table - Hash Table - Unordered_Map, Unordered_Set, BFS-Shortest Path from src to Dest, DFS-Backtracking | Time - O(26*W*N + V*E), Space - O(N*W + V*E), N==WordList.
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // Build the special type adjacency list 
        // contains link only parent to child according to their depth level
        unordered_map<string, unordered_set<string>> adjList;   //Adjacency List
        unordered_set<string> dict(wordList.begin(), wordList.end());  //Insert WordList in SET - for fast lookup
        
        //1. Find min-depth using BFS
        queue<string> q;                     //For BFS traversal
        unordered_map<string, int> visited; //Key->String (Node)...Value->Level (Depth of traversal)
        q.push(beginWord);                  //Push start node (beginWord)
        visited[beginWord] = 0;             //Start node will always be at level 0
        
        while(!q.empty()){
            string curWord = q.front();
            q.pop();
            
            for(int i=0; i<curWord.size(); i++){    //For all characters
                string nextWord = curWord;

                for(char ch ='a'; ch<='z'; ch++){   //Try all possible 26 letters
                                        
                    if(ch==curWord[i])              //Skip if letter is same as in original word
                        continue;
                    
                    nextWord[i] = ch;
                    if(dict.count(nextWord)>0){     //Check if new word is present in wordLis
                        
                        if(visited.count(nextWord)==0){                     //check if the new word was already visited
                            visited[nextWord] = visited[curWord] + 1;
                            adjList[curWord].insert(nextWord);
                            q.push(nextWord);
                        }
                        else if(visited[nextWord] == visited[curWord] + 1)  //If already visited and new word is the child (We should always move down)
                            adjList[curWord].insert(nextWord);
                    }
                }
            }
        }
        
        // 2. Apply DFS to find the paths at min-depth
        vector<vector<string>> paths;           //Find all possible paths with min-depth
        vector<string> curPath;
        dfs(adjList, paths,curPath,beginWord, endWord);  //Find all possible paths with min-depth
        
        return paths;
    }
private:
    void dfs(unordered_map<string, unordered_set<string>>& adjList, vector<vector<string>>& paths, vector<string>& curPath, string& beginWord, string endWord){
        // Insert the current insert into the current path
        curPath.push_back(beginWord);
        
        // base case
        if(beginWord==endWord){
            paths.push_back(curPath);
            curPath.pop_back();
            return;
        }
        
        // recursive case
        // check for all the childs of current beginWord
        for(auto nextWord: adjList[beginWord]){
            dfs(adjList, paths, curPath, nextWord, endWord);
        }
        
        // backtracking
        curPath.pop_back();
    }
};