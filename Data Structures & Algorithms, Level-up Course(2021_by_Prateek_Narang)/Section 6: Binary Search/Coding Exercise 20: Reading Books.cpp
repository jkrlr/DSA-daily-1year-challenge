// Time = O(NLog(Max_Sum)), Space = O(1)

#include <bits/stdc++.h>
using namespace std;

bool isPagesSumPossible(vector<int> books, int pages, int m)
{
    int students = 1;
    int curr_pages = 0;

    for (int i = 0; i < books.size(); i++)
    {
        if (books[i] + curr_pages > pages)
        {
            students += 1;
            curr_pages = books[i];

            if (students > m)
            {
                return false;
            }
        }
        else
        {
            curr_pages += books[i];
        }
    }
    return true;
}

int minPages(vector<int> books, int m)
{
    // If no. of students is greater than size of array
    if (m > books.size())
    {
        return -1;
    }

    // Binary Search
    int start = 0;
    int end = 0;
    int ans = -1;

    for (int i = 0; i < books.size(); i++)
    {
        end += books[i];
        start = max(start, books[i]);
    }

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (isPagesSumPossible(books, mid, m))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return ans;
}