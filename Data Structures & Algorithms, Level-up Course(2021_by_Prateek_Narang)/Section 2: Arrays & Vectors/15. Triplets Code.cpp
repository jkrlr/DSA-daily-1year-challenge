#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector< vector<int> > triplets(vector<int> ar, int target){
    // Logic
    sort(ar.begin(), ar.end());
    vector<vector<int>> res;
    int n = ar.size();

    // Pick every a[i], pair sum for remaining part
    for (int i = 0; i <= n-3;i++){
        int x = target - ar[i];
        int L = i + 1, R = n - 1;

        // Two pointer approach
        while (L<R)
        {
            if(ar[L]+ar[R]==x){
                res.push_back({ar[i], ar[L], ar[R]});
                L++, R--;
            }
            else if(ar[L]+ar[R]< x)
                L++;
            else
                R--;
        }
    }

    return res;
}

int main(){
    vector<int> ar{1,2,3,4,5,6,7,8,9,15};
    int target = 18;

    auto res = triplets(ar, target);
    if (res.size() == 0)
        cout << "No such triplet";
    else{
        for (auto v:res){
            for(int num:v)
                cout << num << ",";
            cout << endl;
        }
    }
    return 0;
}