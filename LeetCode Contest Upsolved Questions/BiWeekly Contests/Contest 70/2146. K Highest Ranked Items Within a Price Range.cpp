// https://leetcode.com/problems/k-highest-ranked-items-within-a-price-range/

// Medium

// Tags - BFS on Grid, Custom Sort

// What this problem wants to teach me?
/* In Grid question most of the time you have to simply apply the BFS or DFS according to the question
    and then in later part while processing a node after the queue or stack do some work according to the question*/
// In contest/coding test think only for time complexity don't think to optimize the space complexity
/* If in some question we've to find the k nearest/farthest points or
   If in some question if we've to continuously push and pop the elements from the ongoing answer vector according to the some constraints
   ans we've required to maintain the order of elements to be sorted by some property while doing push/pop operations
   Then, In such type of question we can use the priority_queue (max_heap or min_heap according to question)
   or alternatively we can use multiset also instead of heap*/
// In case of heap, for user defined data types, we've required the user defined compare class by doing overloading of operator()

#include<bits/stdc++.h>
using namespace std;

// BFS on Grid + Custom Sort | Time - O(MN + MN*Log(MN) + K), Space - O(MN)
class Cell{
public:
    int dist, price;
    int x,y;
    
    Cell(int x, int y, int price, int dist=0){
        this->x = x;
        this->y = y;
        this->price = price;
        this->dist = dist;
    }
};

bool cellCompare(Cell& c1, Cell& c2){
    if(c1.dist != c2.dist)
        return c1.dist < c2.dist;
    else if(c1.price != c2.price)
        return c1.price < c2.price;
    else if(c1.x != c2.x)
        return c1.x < c2.x;
    else
        return c1.y < c2.y;
    
}

class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        vector<Cell> store;
        
        queue<Cell> q;
        q.push(Cell(start[0], start[1], grid[start[0]][start[1]], 0));
        
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        visited[start[0]][start[1]] = true;
        
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        
        while(!q.empty()){
            Cell prev = q.front();
            q.pop();
            
            // do some work_______
            // if price!=1 then insert it into answer vector
            if(prev.price != 1 && prev.price>= pricing[0] && prev.price <= pricing[1]){
                store.push_back(prev);
            }
            
            // 4 - directional visit
            for(int i=0; i<4; i++){
                int newX = prev.x + dx[i];
                int newY = prev.y + dy[i];
                
                if(newX >=0 && newX<grid.size() && newY>=0 && newY < grid[0].size() && grid[newX][newY]!=0 && visited[newX][newY]==false){
                    q.push(Cell(newX, newY, grid[newX][newY], prev.dist + 1));
                    visited[newX][newY] = true;
                }
            }
        }
        
        sort(store.begin(), store.end(), cellCompare);
        vector<vector<int>> ans;
        
        for(int i = 0;i<k && i<store.size(); i++){
            vector<int> tmp = {store[i].x, store[i].y};
            ans.push_back(tmp);
        }
        return ans;
    }
};

// BFS on Grid + Priority queue | Time - O(MN + MN*Log(K) +  2*K), Space - O(MN)
class Cell{
public:
    int dist, price;
    int x,y;
    
    Cell(int x, int y, int price, int dist=0){
        this->x = x;
        this->y = y;
        this->price = price;
        this->dist = dist;
    }
};

class CellCompare{
public:
    bool operator()(Cell& c1, Cell& c2){
        if(c1.dist != c2.dist)
            return c1.dist < c2.dist;
        else if(c1.price != c2.price)
            return c1.price < c2.price;
        else if(c1.x != c2.x)
            return c1.x < c2.x;
        else
            return c1.y < c2.y;        
    }
};

class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        priority_queue<Cell, vector<Cell>, CellCompare> max_heap;
        
        queue<Cell> q;
        q.push(Cell(start[0], start[1], grid[start[0]][start[1]], 0));
        
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        visited[start[0]][start[1]] = true;
        
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        
        while(!q.empty()){
            Cell prev = q.front();
            q.pop();
            
            // if price!=1 then insert it into answer max_heap
            if(prev.price != 1 && prev.price>= pricing[0] && prev.price <= pricing[1]){
                max_heap.push(prev);
                if(max_heap.size() > k) // if size of heap more than k than pop the top element
                    max_heap.pop();
            }
            
            // 4 - directional visit
            for(int i=0; i<4; i++){
                int newX = prev.x + dx[i];
                int newY = prev.y + dy[i];
                
                // check if a cell is valid or not
                if(newX >=0 && newX<grid.size() && newY>=0 && newY < grid[0].size() && grid[newX][newY]!=0 && visited[newX][newY]==false){
                    q.push(Cell(newX, newY, grid[newX][newY], prev.dist + 1));
                    visited[newX][newY] = true;
                }
            }
        }
        
        vector<vector<int>> ans;
        while(!max_heap.empty()){
            Cell cell = max_heap.top();
            max_heap.pop();
            ans.push_back({cell.x, cell.y});
        }
        
        reverse(ans.begin(), ans.end());    // reverse the ans to get in ascesnding order
        
        return ans;
    }
};