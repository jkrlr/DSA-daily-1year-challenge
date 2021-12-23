// https://leetcode.com/problems/course-schedule-ii/

// Medium

// Tags - Topological Sorting, BFS, DFS

// What this problem wants to teach me?
/* This problem is equivalent to finding the topological order in a directed graph. 
If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.*/

#include<bits/stdc++.h>
using namespace std;

// Topological Sorting | Time = O(V+E), Space = O(V + E)
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {        
        
        vector<vector<int>> adjList(numCourses);
        vector<int> indegree(numCourses,0);
        
        // 1.Build the Adjacency List of graph
        for(int i=0; i<prerequisites.size(); ++i){
                int to = prerequisites[i][0];
                int from = prerequisites[i][1];
            
                adjList[from].push_back(to);
                ++indegree[to];
        }
        
        // 2. Topological Sorting
        queue<int> q;
        for(int course = 0; course<numCourses; ++course){
            if(indegree[course]==0){
                q.push(course);
            }
        }
        
        vector<int> coursesOrdering;
        
        while(!q.empty()){
            int prevCourse = q.front();
            q.pop();
            coursesOrdering.push_back(prevCourse);
            
            for(int nextCourse : adjList[prevCourse]){
                
                --indegree[nextCourse];
                if(indegree[nextCourse]==0){
                    q.push(nextCourse);
                }
            }
        }
        
        if(coursesOrdering.size()==numCourses){
            return coursesOrdering;
        }
        else{
            return {};
        }
    }
};