// Time = O(n), Space=O(1)

#include <iostream>
using namespace std;

void housing(int *plots, int n, int k)
{
    int currSum = 0;
    int i = 0, j = 0;

    while (j < n)
    {
        // Expand to right
        currSum += plots[j];
        j++;

        // Remove the elemnts from left till currSum>k and i<j(=>atlest one element in window)
        while (currSum > k and i < j)
        {
            currSum -= plots[i];
            i++;
        }

        // Check if any given point
        if (currSum == k)
        {
            // Print that window
            cout << i << " - " << j - 1 << endl;
        }
    }
}

int main()
{
    int plots[] = {1, 3, 2, 1, 4, 1, 3, 2, 1, 1};
    int n = sizeof(plots) / sizeof(int);
    int k = 8;

    housing(plots, n, k);
}

/* 
    Assignment:
    Smallest Window that contains the required Sum
    handle if you have -ve integers in the array
*/