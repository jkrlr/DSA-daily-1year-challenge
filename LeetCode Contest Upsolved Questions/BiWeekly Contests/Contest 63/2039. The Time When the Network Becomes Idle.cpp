// https://leetcode.com/problems/the-time-when-the-network-becomes-idle/

// Medium

// Tags - BFS-SSSP + Math

// What this problem wants to teach me?
// BFS variations with some tricky math logic

// Time - O(V + E), Space = O(V+E)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> bfs(vector<vector<int>> &adj){
        int n = adj.size();

        vector<int> time(n, -1);    // distance array
        queue<int> q;
        int src = 0;
        q.push(src); // Insert the src node into queue

        time[src] = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int nbr : adj[node]){
                if(time[nbr]==-1){  // here distance array can be used as visited array also
                    time[nbr] = time[node] + 1;
                    q.push(nbr);
                }
            }
        }

        return time;
    }

    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = edges.size();   // nodes in graph - all nodes are connected here

        // create the graph
        vector<vector<int>> adj(n);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> time = bfs(adj);    // return the shortest time to reach the src i.e. node 0  from the particular node

        int networkIdleTime = 0;

        for(int i = 1; i < patience.size(); i++){
            int extraSentMsgCount = (2 * time[i] - 1) / patience[i];

            int lastExtraMsgOutTime = extraSentMsgCount * patience[i];
            int lastMsgInTime = lastExtraMsgOutTime + 2 * time[i];   // 2*time[i] => going + returning time

            networkIdleTime = max(networkIdleTime, lastMsgInTime);
        }


		// since the problem is asking for min time when there is no message is passing.
		// and at "networkIdleTime" time the last message has arrived at one of the data servers.
		// so at networkIdleTime + 1 no message will be passing between servers.

        return networkIdleTime + 1;
    }
};