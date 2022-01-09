// https://leetcode.com/problems/robot-bounded-in-circle/

// Medium

// Topic Tags - Math - Co-ordinate geometry, Simulation, String

// Companies Tags - Amazon top most asked question in 2021

// What this problem wants to teach me?
// If problems look like unknown and don't understand what to do
// Then, try to find the patterns by dry running on example test case and by seeing constraints

#include<bits/stdc++.h>
using namespace std;

// Math - Co-ordinate geometry, Simulation | Time = O(N), Space = O(1)

// Change in position
// Change in direction
class Solution {
public:
    bool isRobotBounded(string instructions) {
        int dirX = 0, dirY = 1;
        int x = 0, y = 0;
        
        for(char instruction : instructions){
            if(instruction == 'G')
                x = x + dirX, y = y + dirY;
                
            else if(instruction == 'L'){
                int tmp = dirX;
                dirX = -1*dirY, dirY = tmp;
            }      
            else{
                int tmp = dirX;
                dirX = dirY, dirY = -1*tmp;
            }     
        }
        
        return ((x==0 && y==0) || (dirX!=0 || dirY!=1));   
    }
};