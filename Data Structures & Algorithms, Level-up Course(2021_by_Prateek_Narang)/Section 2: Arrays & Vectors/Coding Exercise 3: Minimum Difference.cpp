#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

// Time = O(NLogN), Space = O(1)

pair<int,int> minDifference(vector<int> a,vector<int> b){
    pair<int,int> res;
    
    // Sort the arrays
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    
    int MinDiff = INT_MAX;
    
    int idxA=0, idxB=0;
    
    // Scan both the arrays upto size of arrays
    while(idxA<a.size() and idxB<b.size()){
        int CurrDiff = abs(a[idxA] - b[idxB]);
        
        if(CurrDiff<MinDiff){
            MinDiff=CurrDiff;
            res = {a[idxA], b[idxB]};
        }
        
        // Move Smaller Value
        if(a[idxA]<b[idxB])
            idxA++;
        else
            idxB++;
    }
    return res;
}