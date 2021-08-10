// We've to define and pass Comparator to set because we're using own user defined class not inbuilt class. 
// Since, map or set stores data in sorted order =>comparator is necessary

// Time = O(N^2*LogN) , Space = O(N)
#include<iostream>
#include<set>
#include<vector>
using namespace std;
 
// Point Class
class Point{
public:
   int x;
   int y;
 
   Point(int x, int y){
       this->x = x;
       this->y = y;
   }
};
 
// Comparator Class
class Compare{
public:
	bool operator()(const Point p1, const Point p2){
		if(p1.x == p2.x){
			return p1.y < p2.y;
		}
		return p1.x < p2.x;
	}
};
 
int countRectangles(vector<Point> points){
	int n = points.size();
	int rectangles = 0;
 
	// 1. Insert all the Points into the set
    set<Point,Compare> s;
    for(Point p: points){
        s.insert(p);
    }
	
	// 2. Logic Brute Force Two points + Lookup fo other Two Points
	for(auto it=s.begin();it!=prev(s.end());it++){
		for(auto jt=next(it);jt!=s.end();jt++){
			Point p1 = *it;
			Point p2 = *jt;
 
			// small checkup - second point lies on same horizontal or vetical line of first point
			if(p2.x==p1.x || p2.y==p1.y){
				continue;
			}
 
			// P3, P4
			Point p3(p1.x,p2.y);
			Point p4(p2.x,p1.y);
		
			// Lookup
			if(s.find(p3)!=s.end() && s.find(p4)!=s.end()){
				rectangles+=1;
			}
		}
	}
	
 
	return rectangles/2;
}
 
int main(){
	int n;
	cin>>n;
	vector<Point> points;
	
	int x,y;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		Point p(x,y);
		points.push_back(p);
	}
	cout<<countRectangles(points)<<endl;
}
