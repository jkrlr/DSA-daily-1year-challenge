#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int highest_mountain(vector<int> ar){
    int largest = 0, L = 0;

    for (int i = 1; i < ar.size()-1;i++){

        // Check ar[i] is peak or not
        if(ar[i]>ar[i-1] && ar[i]>ar[i+1]){
            
            // do some work
            L = i;
            int curr_width = 1;

            // count backwards (left)
            while (L>0 && (ar[L] > ar[L - 1]))
            {
                curr_width++;
                L--;
            }

            // count forwards(right)
            while ((i<ar.size()-1) && (ar[i]>ar[i+1]))
            {
                curr_width++;
                i++;
            }
            largest = max(largest, curr_width);
        }
    }
        return largest;
}

int main(){
    vector<int> ar{5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};
    cout << highest_mountain(ar) << endl;
    return 0;
}