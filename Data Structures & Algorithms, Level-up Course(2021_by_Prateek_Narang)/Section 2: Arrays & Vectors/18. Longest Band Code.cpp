// https://leetcode.com/problems/longest-consecutive-sequence/solution/

#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

int longestBand(vector<int> ar){
    unordered_set<int> s;

    // Data inside a set
    for(int x:ar)
        s.insert(x);

    // Iterate over the ar
    int longest = 0;

    for(auto num:s){
        int parent = num - 1;

        if(s.find(parent)==s.end()){
            //find entire band / chain starting from num
            int next_num = num + 1;
            int cnt = 1;

            while(s.find(next_num)!=s.end())
                next_num++, cnt++;

            longest = max(longest, cnt);
        }
    }

    return longest;
}

int main(){
    vector<int> ar{1, 9, 3, 0, 18, 5, 2, 4, 10, 7, 12, 6};
    cout << longestBand(ar) << endl;
    return 0;
}