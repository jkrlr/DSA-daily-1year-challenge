// https://leetcode.com/problems/product-of-array-except-self/
// Time = O(n) and space = O(1)

#include <vector>
using namespace std;

vector<int> productArray(vector<int> ar)
{

    int n = ar.size();
    vector<int> res(n, 1);

    int leftProd = 1, rightProd = 1;

    for (int i = 0; i < n; i++)
    {
        res[i] *= leftProd;
        leftProd *= ar[i];

        res[n - 1 - i] *= rightProd;
        rightProd *= ar[n - 1 - i];
    }

    return res;
}