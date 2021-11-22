// https://leetcode.com/problems/most-beautiful-item-for-each-query/

// Medium

// Tags - Array, Sorting, Binary Seach

// What this problem wants to teach me?
/* For vector<pair<int, int>> type input while apply sorting,
    we have to sort according to that part of the pair (pair.first or pair.second) for which
    we are making comparision to query input to find the answer  
    If the answer giving pair is not sorted by the previous sorting than we have to read the question again and
    try to find and decode the some information, so that we can sort the answer giving pair part also in next loop
    So, that we can apply Binary Search */
/* If the current input ans depends upon all the previous smaller elements ans/all the next greater elements ans 
    Then in this we can use prefix-sum/suffix-sum or store the previous/next ans in a variable and use that for current ans 
    You will clearly see this repetetion in your brute-force code and then If question can be solved greedily 
    Then this approach will surely work (Otherwise dp will be used). */
/* In-buit Sort() function of STL sort according to first difference in match of given input data-types according to 
    increasing by default condition or decreasing by using greater<T> */
/* When we required sorting in question and Then question can be solved using lower_bound() or upper_bound() i.e some variation of Binary Search 
    Then we can use map<T,T> (for pair<int,int> type input data-types) or set<T> or multiset<T> (<T> can be here any pair<T,T>) 
    for elements to keep in sorted order and use inBuit library function lower_bound() and upper_bound() to solve the question 
    i.e similar question that can be solved using vector + sorting + Custom BS, sometimes map/set/mutiset + InBuit-BS can simplify the impementations */

#include<bits/stdc++.h>
using namespace std;

// Sorting | Time - O(NLogN + MLogM + (N+M)), Space - O(2*N)
class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<pair<int,int>> queriesPair;
        
        for(int i=0; i<queries.size(); i++){
            queriesPair.push_back({queries[i], i});
        }
        
        sort(queriesPair.begin(), queriesPair.end());
        sort(items.begin(), items.end());
        
        int itemsIndex = 0;
        int maxBeauty = 0;
        
        vector<int> result(queries.size());
        
        for(int i = 0; i<queriesPair.size(); i++){
            int maxPriceAllowed = queriesPair[i].first;
            int queryOriginalIndex = queriesPair[i].second;
            
            while(itemsIndex<items.size() && items[itemsIndex][0]<=maxPriceAllowed){
                maxBeauty = max(maxBeauty, items[itemsIndex][1]);
                itemsIndex++;
            }
            
            result[queryOriginalIndex] = maxBeauty;
        }
        
        return result;
    }
};

// Sorting  + Binary Seach | Time = O(NLogN + N + MLogN), Space = O(1)

class Compare{
    bool operator()(vector<int>& a, vector<int>&b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        
        return a[0] < b[0];
    }  
};

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size();

        // 1. Sort items into increasing order of prices
        sort(items.begin(),items.end());
        
        // 2. Use previous item beauty to maximize the beauty of current item
        // Now, both prices and beauty wil be in increasing order for all items
        for(int i=1; i<n; i++){
            items[i][1] = max(items[i][1],items[i-1][1]);
        }
        
        // 3. Process each query in Log(n) time
        int m = queries.size();
        vector<int> result(m,0);
        
        for(int i=0; i<m; i++){
            int queryVal = queries[i];
            
            result[i] = weakLowerBound(items, queryVal);
        }
        
        return result;
    }
    
    int weakLowerBound(vector<vector<int>>& items, int val){
        int lo = 0;
        int hi = items.size()-1;
        int beauty = 0;
        
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            
            if(items[mid][0]<= val){
                beauty = items[mid][1];
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        
        return beauty;
    }
};

//  Map + lower_bound() | Time - O(NLogN + MLogN), Space - O(N)
class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {               int n = items.size();                                                                                 
        map<int,int> m;                                                                 
                                                                                 
        for(int i=0; i<n; i++){
            int price = items[i][0];
            int beauty = items[i][1];            
            
            if(m.find(price) == m.end()){
                m[price] = beauty;
            }
            else{
                int prevBeauty = m[price];
                m[price] = max(prevBeauty, beauty); // maximum beauty possible till price [1,price]

            }
        }
        
        int maxBeauty = -1;
        for(auto& p : m){
            int currPrice = p.first;
            int currBeauty = p.second;
            
            maxBeauty = max(maxBeauty,currBeauty);
            m[currPrice] = maxBeauty;
        }
       
       vector<int> result(queries.size(),0);
       for(int i = 0; i<queries.size(); i++){
           int queryPrice = queries[i];
           
           if(m.find(queryPrice)!=m.end()){
               result[i] = m[queryPrice];
           }
           else{
               auto it = m.lower_bound(queryPrice); // checking beauty for price just lower than for given query
               if(it!=m.begin()){
                   --it;
                    result[i] = it->second;
               }               
           }
       }
       
       return result;
    }
};