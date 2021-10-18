// https://leetcode.com/problems/second-minimum-time-to-reach-destination/

// Hard

// Juspay Hiring OA Hackerearth question

// Revision

// Tags - BFS, Modified Dijkstra

// What this problem wants to teach me?
// You're missing slightly tricky part of Hard questions, you're quite close to answer
// How to do slight modifications in Dijkstra(BFS) to get the answer

// Time = O((V + E)*LogV), Space = O(V + E)

#include<bits/stdc++.h>
using namespace std;

// Soln using priority_queue

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adjList(n+1);   // n+1 because nodes start from 1...n
        // create the graph
        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<int> visitCountTo(n + 1, 0);
        vector<int> visitTimeTo(n + 1, INT_MAX);  // This is like as distance array and can be used as visited array also.

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;     // min heap

        int src = 1;
        visitTimeTo[src] = 0;
        visitCountTo[src] = 1;
        pq.push({visitTimeTo[src], src});

        int minTimeToDest = INT_MAX;

        while(!pq.empty()){
            int prev = pq.top().second;
            int prevTime = pq.top().first;
            pq.pop();

            int waitTime = 0;
            bool isRed = (prevTime / change) % 2;
            if (isRed){ // check if signal is red
                waitTime = change - (prevTime % change);
            }

            for(auto& next : adjList[prev]){

                int nextTime = prevTime + waitTime + time;

                if(next == n && minTimeToDest == INT_MAX){
                    minTimeToDest = nextTime;
                }

                else if(next==n && nextTime > minTimeToDest){
                    return nextTime;
                }

                if(visitTimeTo[next] != nextTime && visitCountTo[next] < 2){ // to ensure to re-visit atmost 1 time
                    visitTimeTo[next] = nextTime;
                    visitCountTo[next] += 1;

                    pq.push({visitTimeTo[next], next});
                }
            }
        }

        return -1;
    }
};

// Soln using set
class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adjList(n+1);   // n+1 because nodes start from 1...n
        // create the graph
        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<int> visitCountTo(n + 1, 0);
        vector<int> visitTimeTo(n + 1, INT_MAX);  // This is like as distance array and can be used as visited array also.

        set<pair<int,int>> s;

        int src = 1;
        visitTimeTo[src] = 0;
        visitCountTo[src] = 1;
        s.insert({visitTimeTo[src], src});

        int minTimeToDest = INT_MAX;

        while(!s.empty()){
            
            auto it = s.begin();
            int prev = it->second;
            int prevTime = it->first;
            s.erase(it);

            int waitTime = 0;
            bool isRed = (prevTime / change) % 2;
            if (isRed){ // check if signal is red
                waitTime = change - (prevTime % change);
            }

            for(auto& next : adjList[prev]){

                int nextTime = prevTime + waitTime + time;

                if(next == n && minTimeToDest == INT_MAX){
                    minTimeToDest = nextTime;
                }

                else if(next==n && nextTime > minTimeToDest){
                    return nextTime;
                }

                if(visitTimeTo[next] != nextTime && visitCountTo[next] < 2){ // to ensure to re-visit atmost 1 time
                    
                    visitTimeTo[next] = nextTime;
                    visitCountTo[next] += 1;

                    s.insert({visitTimeTo[next], next});
                }
            }
        }

        return -1;
    }
};

// dijkstra using priority_queue

/* void dijkstra(int n, vector<vector<int>>& edges, int wt){

    vector<vector<pair<int, int>>> adjList(n+1);

    for(auto& e : edges){
        adjList[e[0]].push_back({wt, e[1]});
        adjList[e[1]].push_back({wt, e[0]});

    }

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq; // min heap
    vector<int> distanceTo(n + 1, INT_MAX);

    // Init
    pq.push({0, 1});
    distanceTo[1] = 0;

    while(!pq.empty()){
        int prev = pq.top().second;
        int dist = pq.top().first;

        pq.pop();

        for(auto& nbr : adjList[prev]){
            int next = nbr.second;
            int nextDist = nbr.first;

            if(distanceTo[next] > distanceTo[prev] + nextDist){
                distanceTo[next] = distanceTo[prev] + nextDist;

                pq.push({distanceTo[next], next});
            }
        }
    }
}
 */

// dijkstra using set

/* void dijkstra(int n, vector<vector<int> >& edges, int wt){
    vector<vector<pair<int, int>>> adjList(n + 1);

    for(auto& e: edges){
        adjList[e[0]].push_back({e[1], wt});
        adjList[e[1]].push_back({e[0], wt});

    }

    vector<int> distTo(n + 1, INT_MAX);
    set<pair<int, int>> s;

    int src = 1;
    distTo[src] = 0;
    s.insert({distTo[src], src});

    while(!s.empty()){
        int prev = s.begin()->second;
        int dist = s.begin()->first;

        s.erase(s.begin());

        for(auto& nbr : adjList[prev]){
            int next = nbr.first;
            int nextDist = nbr.second;

            if(distTo[next] > distTo[prev] + nextDist){

                auto found = s.find({distTo[next], next});
                if(found!=s.end()){
                    s.erase(found);
                }

                distTo[next] = distTo[prev] + nextDist;
                s.insert({distTo[next], next});
            }
        }
    }
} */