// Time = O(N), Space = O(N)
// First mistake - not declaring the map with long instead of int to avoid overflow - unless it's not mentioned
//                  because multiplication will cause overflow
// Second mistake - not checking ar[i]%r condition before finding the freqof_ar[i] in left hashmap

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
 
int countTriplets(vector<int> ar, int r){
	int triplets=0;
	// unordered_map<num,freqofNum>
    unordered_map<long, long> freqLeft, freqRight;

    // Init. the Right map with freq and left map =0
    for(int num : ar){
			freqRight[num]++;
            freqLeft[num] = 0;
    }
    for(int i=0;i<ar.size();i++){
		freqRight[ar[i]]--;

        if(ar[i]%r==0){
            long currTerm = ar[i];
            long prevTerm = ar[i] / r;
            long nextTerm = ar[i] * r;

            triplets += freqLeft[prevTerm] * freqRight[nextTerm];
        }

        freqLeft[ar[i]]++;
	}
	
	return triplets;
}
 
int main(){
    int n, r;
    cin >> n >> r;
    vector<int> v(n, 0);
    for(int i=0;i<n;i++){
		cin>>v[i];
	}
	cout<<countTriplets(v,r)<<endl;
}
