// Time = O(NLogN), Space = O(N)
 
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
 
int main(){
	priority_queue<int> leftHeap;	// max heap
	priority_queue<int, vector<int>,greater<int>> rightHeap;	// min heap
	
	int num;
    cin>>num;
    leftHeap.push(num);
    
    float median = num;
    cout<<num<<" ";
    
    cin>>num;
	while(num!=-1){	
		/* if no. of element in one heap more than one than other and next coming element is pushed in that heap
        => Then, pop into the next heap and push into another heap and push coming to the current heap */
		/* if current element is smaller than median, then push into min heap 
        => left heap else push into the max heap => right heap */

        // left or right or equal
        if(leftHeap.size() > rightHeap.size()){
            if(num < median){
                    rightHeap.push(leftHeap.top());	// push root of left heap into right heap
                    leftHeap.pop();
                    leftHeap.push(num);	// now push current element into left heap
            }
            else{
                    rightHeap.push(num);
            }
            int mid1 = leftHeap.top();
            int mid2 = rightHeap.top();
            median  = mid1 + (mid2-mid1)/2.0;
        }
        else if(leftHeap.size() == rightHeap.size()){
                if(num < median){
                    leftHeap.push(num);
                    median = leftHeap.top();
                }
                else{
                    rightHeap.push(num);
                    median = rightHeap.top();
                }
        }
        else{
            if(num < median){
                    leftHeap.push(num);
            }
            else{
                    leftHeap.push(rightHeap.top());	// push root of right heap into left heap
                    rightHeap.pop();
                    rightHeap.push(num);	// now push current element into right heap
            }
            int mid1 = leftHeap.top();
            int mid2 = rightHeap.top();
            median  = mid1 + (mid2-mid1)/2.0;
        }

		cout<<median<<" ";
		cin>>num;
	}
}
 
 
