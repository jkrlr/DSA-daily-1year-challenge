/*
The greedy choice is to always pick the next activity whose finish time is least among the remaining activities and 
the start time is more than or equal to the finish time of the previously selected activity. 
We can sort the activities according to their finishing time so that we always consider the next activity as minimum finishing time activity.

1) Sort the activities according to their finishing time 
2) Select the first activity from the sorted array and increment the cnt. 
3) Do the following for the remaining activities in the sorted array. 

…….a) If the start time of this activity is greater than or equal to the finish time of the previously selected activity 
then select this activity and increment the cnt.
*/

// Time = O(NLogN), Space = O(1)

#include <vector>
#include <algorithm>
using namespace std;

bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
    return (b.second > a.second);
}

int countActivites(vector<pair<int, int>> activities)
{
    //Greedy Approach

    //Sort the array by the finish time of activities
    //i.e. sort by second element of pair
    sort(activities.begin(), activities.end(), sortbysec);

    int cnt = 0, prevEnd = -1;

    for (int i = 0; i < activities.size(); i++)
    {
        int currStart = activities[i].first, currEnd = activities[i].second;

        if (currStart >= prevEnd)
        {
            cnt++;
            prevEnd = currEnd;
        }
    }
    return cnt;
}