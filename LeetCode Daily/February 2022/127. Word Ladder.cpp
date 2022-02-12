// https://leetcode.com/problems/word-ladder/

// Hard

// Tags - Hash Table - Unordered_Map, BFS-Shotest Path Src to Dest, String

// What this problem wants to teach me?
/* BFS can be used to find the shortest path from src to dest in both graph and trees but
    DFS only used in case of trees to find the shortest path from src to dest not in case of graphs
    because in case of trees between two nodes their only exist unique path but in case of graph multiple paths are possible
    DFS takes exponential time but BFS take polynomial time to find the shortest path in case of graphs*/
/* How we can apply Shortes path Algo in case of some string problem asking for shortest path sequence */

#include<bits/stdc++.h>
using namespace std;

//  Hash Table - Unordered_Map + BFS-Shotest Path Src to Dest | Time - O(26*W*W*N), Space - O(N*W), N==WordList.
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool isPresent = false;
        unordered_set<string> s;
        for(auto& word: wordList){
            s.insert(word);
            
            if(endWord.compare(word)==0)
                isPresent = true;
        }
        
        if(isPresent==false)
            return 0;
        
        // BFS
        queue<string> q;
        q.push(beginWord);
        int depth = 0;
        while(!q.empty()){
            depth += 1;
            
            int levelSize = q.size();   // No. of elements at a level
            
            // check for all possible 1 depth words
            for(int i=0; i<levelSize; i++){
                string curWord = q.front();
                q.pop();
                
                for(int j=0; j<curWord.size(); j++){
                    string tmp = curWord;
                    
                    for(char ch = 'a'; ch<='z'; ch++){  // try out all the possible chars
                        // skip the current character of curWord
                        if(ch==curWord[j])
                            continue;
                        
                        tmp[j] = ch;    // replace the j character of curWord
                        
                        if(tmp.compare(endWord)==0) // endWord found
                            return depth + 1;
                        if(s.find(tmp)!=s.end()){
                            q.push(tmp);
                            
                            s.erase(tmp);
                        }
                    }
                }
            }
        }
        
        return 0;
        
    }
};