// https://leetcode.com/problems/k-closest-points-to-origin/

// Medium

// Tags - Sort with Custom Comparator, Max Heap 
// Tags -  Array, Math, Divide and Conquer, Geometry, Sorting, Heap(Priority Queue), QuickSelect

// What this problem wants to teach me?
// Implicit conversions of float or double value of an expresssion into int may give WA for some test cases 
// Anytime we are tasked with finding the **k (or kth) [smallest/largest/etc.]** element(s), 
// we should always consider whether the **QuickSelect or Heap or Greedy** algorithm can be applied. 

#include <bits/stdc++.h>
using namespace std;

// Approach 1: Sort with Custom Comparator | Time - O(NLogN), Space = O(LogN)-for sorting
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Sort the vector with a custom lambda comparator function
        sort(points.begin(), points.end(), [&](vector<int>& a, vector<int>& b) {
            return squaredDistance(a) < squaredDistance(b);
        });
        
        // Return the first k elements of the sorted vector
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
    
private:
    int squaredDistance(vector<int>& point) {
        // Calculate and return the squared Euclidean distance
        return point[0] * point[0] + point[1] * point[1];
    }
};

// Approach 2: Max Heap or Max Priority Queue | Time - O(N*LogK), Space = O(K)-for max heap / multiset
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> maxPQ;
        for (int i = 0 ; i < points.size(); i++) {
            pair<int, int> entry = {squaredDistance(points[i]), i};
            if (maxPQ.size() < k) {
                // Fill the max PQ up to k points
                maxPQ.push(entry);
            } else if (entry.first < maxPQ.top().first) {
                // If the max PQ is full and a closer point is found,
                // discard the farthest point and add this one
                maxPQ.pop();
                maxPQ.push(entry);
            }
        }
        
        // Return all points stored in the max PQ
        vector<vector<int>> answer;
        while (!maxPQ.empty()) {
            int entryIndex = maxPQ.top().second;
            maxPQ.pop();
            answer.push_back(points[entryIndex]);
        }
        return answer;
    }

private:
    int squaredDistance(vector<int>& point) {
        // Calculate and return the squared Euclidean distance
        return point[0] * point[0] + point[1] * point[1];
    }
};

// Approach 3: Binary Search | Time - O(2N)-Avg Case and O(N^2)-Worst Case, Space = O(N)- arrays containing distances and reference indices.
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Precompute the Euclidean distance for each point,
        // define the initial binary search range,
        // and create a reference list of point indices
        vector<double> distances;
        vector<int> remaining;
        double low = 0, high = 0;
        for (int i = 0; i < points.size(); i++) {
            distances.push_back(euclideanDistance(points[i]));
            high = max(high, distances[i]);
            remaining.push_back(i);
        }
                
        // Perform a binary search of the distances
        // to find the k closest points
        vector<int> closest;
        while (k) {
            double mid = low + (high - low) / 2;
            vector<vector<int>> result = splitDistances(remaining, distances, mid);
            vector<int> &closer = result[0];
            vector<int> &farther = result[1];
            if (closer.size() > k) {
                // If more than k points are in the closer distances
                // then discard the farther points and continue
                remaining.swap(closer);
                high = mid;
            } else {
                // Add the closer points to the answer array and keep
                // searching the farther distances for the remaining points
                k -= closer.size();
                closest.insert(closest.end(), closer.begin(), closer.end());
                remaining.swap(farther);
                low = mid;
            }
        }
        
        // Return the k closest points using the reference indices
        vector<vector<int>> answer;
        for (int index : closest) {
            answer.push_back(points[index]);
        }
        return answer;
    }
    
private:
    vector<vector<int>> splitDistances(vector<int>& remaining, vector<double>& distances,
                                       double mid) {
        // Split the distances around the midpoint
        // and return them in separate vectors
        vector<vector<int>> result(2);
        vector<int> &closer = result[0], &farther = result[1];
        for (int index : remaining) {
            if (distances[index] <= mid) {
                closer.push_back(index);
            } else {
                farther.push_back(index);
            }
        }
        return result;
    } 
    
    double euclideanDistance(vector<int>& point) {
        // Calculate and return the Euclidean distance
        return sqrt(point[0] * point[0] + point[1] * point[1]);
    }
};

// Approach 4: QuickSelect | Time - O(2N)-Avg Case and O(N^2)-Worst Case, Space = O(1)-withot using recursion
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        return quickSelect(points, k);
    }
    
private:
    vector<vector<int>> quickSelect(vector<vector<int>>& points, int k) {
        int left = 0, right = points.size() - 1;
        int pivotIndex = points.size();
        while (pivotIndex != k) {
            // Repeatedly partition the vector
            // while narrowing in on the kth element
            pivotIndex = partition(points, left, right);
            if (pivotIndex < k) {
                left = pivotIndex;
            } else {
                right = pivotIndex - 1;
            }
        }
        
        // Return the first k elements of the partially sorted vector
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }

    int partition(vector<vector<int>>& points, int left, int right) {
        vector<int>& pivot = choosePivot(points, left, right);
        int pivotDist = squaredDistance(pivot);
        while (left < right) {
            // Iterate through the range and swap elements to make sure
            // that all points closer than the pivot are to the left
            if (squaredDistance(points[left]) >= pivotDist) {
                points[left].swap(points[right]);
                right--;
            } else {
                left++;
            }
        }
        
        // Ensure the left pointer is just past the end of
        // the left range then return it as the new pivotIndex
        if (squaredDistance(points[left]) < pivotDist)
            left++;
        return left;
    }

    vector<int>& choosePivot(vector<vector<int>>& points, int left, int right) {
        // Choose a pivot element of the vector
        return points[left + (right - left) / 2];
    }
    
    int squaredDistance(vector<int>& point) {
        // Calculate and return the squared Euclidean distance
        return point[0] * point[0] + point[1] * point[1];
    }
};