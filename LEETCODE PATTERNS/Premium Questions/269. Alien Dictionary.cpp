// https://www.lintcode.com/problem/892/description
// https://leetcode.ca/all/269.html

// Hard

/* Constraints:
    You may assume all letters are in lowercase.
    The dictionary is invalid, if a is prefix of b and b is appear before a.
    If the order is invalid, return an empty string.
    There may be multiple valid order of letters, return the smallest in normal lexicographical order */

#include<bits/stdc++.h>
using namespace std;

// Topological Sorting | Time - O(N*W*LogN), Space - O(N*W), N==words.length, W==words[i].length
class Solution {
public:
    string alienOrder(vector<string> &words) {
        // 1. Initialaize the indegree map with all the different chars of input
        unordered_map<char, int> indegree;
        for(auto& word: words){
            for(auto& ch: word)
                indegree[ch] = 0;
        }

        // 2. Build the graph
        unordered_map<char, unordered_set<char>> graph;
        for (int i = 0; i < words.size()-1; i++){
            string cur = words[i];
            string next = words[i + 1];

            bool fountMisMatch = false;
            for (int j = 0; j < min(cur.length(), next.length()); j++){
                char from = cur[j];
                char to = next[j];
                if(from!=to){
                    if(graph.count(from)==0){
                        if(graph[from].count(to)==0){
                            graph[from].insert(to);
                        }
                        indegree[to]++;
                    }
                    fountMisMatch = true;
                    break;
                }
            }

            if(fountMisMatch==false && cur.length() > next.length())    // To handle the edge case like, cur = "abcd", next = "abc" => wrong input
                return "";
        }

        // 3. Apply Topological Sorting
        // There may be multiple valid order of letters, return the smallest in normal lexicographical order
        // So, Use priority_queue(min_heap) instead of normal queue
        priority_queue<char, vector<char>, greater<char>> q;    
        string result;
        for (auto &[ch, ind] : indegree){
            if(ind==0)
                q.push(ch);
        }

        while(!q.empty()){
            char curChar = q.top();
            q.pop();
            result.push_back(curChar);

            for(auto& nextChar : graph[curChar]){
                indegree[nextChar]--;

                if(indegree[nextChar]==0)
                    q.push(nextChar);
            }
        }

        if(result.length()==indegree.size())
            return result;

        return "";
    }
};