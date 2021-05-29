#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

vector<int> pairSum(vector<int> ar, int Sum){
    // Logic
    vector<int> res;
    unordered_set<int> s;

    for (int i = 0; i < ar.size();i++){
        int x = Sum - ar[i];

        if(s.find(x)!=s.end()){
            res.push_back(ar[i]), res.push_back(x);
            return res;
        }
        // Insert the current no. inside the set    
        s.insert(ar[i]);
    }

    return res;
}

int main(){

    vector<int> ar{10, 5, 2, 3, -6, 9, 11};
    int S = 4;

    auto p = pairSum(ar, S);
    if(p.size()==0)
        cout << "No such pair";
    else
        cout << p[0] << "," << p[1] << endl;

    return 0;
}