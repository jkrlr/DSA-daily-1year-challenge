// Input  : 10,11,20,303,3

// After Sorting : 3, 303, 30, 11, 10
// Output : 3303201110 => largestNum

// Time = O(Sort + N*N) = O(NlogN * log(Max_Size_of_Int)) = O(NlogN*9) = O(NlogN + N*N) = O(N^2) , Space = O(1) // N is length of array

#include <bits/stdc++.h>
using namespace std;

bool comp(int a, int b)
{

    int d1 = pow(10, floor(log10(a))); // pow(base, exponent) => <cmath>
    int d2 = pow(10, floor(log10(b))); // floor(log10(num)) => gives no. of digits in num

    // Comparing the leftmost digits
    while (d1 > 0 and d2 > 0)
    {
        if ((a / d1) > (b / d2))
            return true;
        else if ((a / d1) < (b / d2))
            return false;
        d1 /= 10;
        d2 /= 10;
    }

    return a < b; // This is 3 < 303 case
}

string concatenate(vector<int> numbers)
{
    //complete this method and return the largest number you can form as a string

    // Sort
    sort(numbers.begin(), numbers.end(), comp);

    string largestNum = "";
    for (int num : numbers)
        largestNum += to_string(num); //Typically, slicing and concatenating strings require O(n) time

    return largestNum;
}