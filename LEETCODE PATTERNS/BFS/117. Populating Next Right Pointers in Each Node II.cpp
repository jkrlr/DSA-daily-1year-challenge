// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

// Medium

// What this problem wants to teach me?
// Modified Level Order Traversal + how to store the elements in reverse order in vector
// while adding the elements in the vector first time (not using the reverse fn at all)

// Time = O(N), Space = O(N)- for storing the queue and row vector , maxsize of both of these are N/2 
// Here N is total no. of tree nodes

#include<bits/stdc++.h>
using namespace std;