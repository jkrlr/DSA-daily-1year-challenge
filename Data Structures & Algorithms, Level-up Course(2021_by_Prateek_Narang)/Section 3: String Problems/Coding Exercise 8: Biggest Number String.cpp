// https://leetcode.com/problems/largest-number/solution/

/* Input  : 10,11,20,303,3
After Sorting : 3, 303, 30, 11, 10
Output : 3303201110 => largestNum */

// Time = O(Sort) = O(NlogN * log(Max_Size_of_Int)) = O(NlogN*9) = O(NlogN) , Space = O(1) // N is length of array

#include <bits/stdc++.h>
using namespace std;

bool comp(int a, int b)
{
    string comb1 = to_string(a) + to_string(b);
    string comb2 = to_string(b) + to_string(a);

    return comb1 > comb2;
}

string concatenate(vector<int> numbers)
{
    // Sort
    sort(numbers.begin(), numbers.end(), comp);

    // If, after being sorted, the largest number is 0,
    // the entire number is zero.
    if (numbers[0] == 0)
        return "0";

    string largestNum = "";
    for (int num : numbers)
        largestNum += to_string(num); //Considering it O(1) But Typically, slicing and concatenating strings require O(n) time

    return largestNum;
}