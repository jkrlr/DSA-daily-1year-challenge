// Time = O(N), Space = O(N)
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
 
int countTriangles(vector<pair<int,int>> points){
	int triangles = 0;
	// unordered_map<X,cntX>
	unordered_map<int,int> freqX,freqY;
	
    // Count the frequency by iterating over all the points
	for(int i=0;i<points.size();i++){
		int x = points[i].first;
		int y = points[i].second;
 
		freqX[x]++;
		freqY[y]++;
	}
 
	// Consider each point as right angle - cnt the triangles
	for(int i=0;i<points.size();i++){
		int x = points[i].first;
		int y = points[i].second;

        int fx = freqX[x];
        int fy = freqY[y];
        triangles += (fx - 1) * (fy - 1);
    }
	return triangles;
}
 
int main(){
	int n;
	cin>>n;
	vector<pair<int,int>> points;
	
	int x,y;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		points.push_back({x,y});
	}
	cout<<countTriangles(points)<<endl;
}
