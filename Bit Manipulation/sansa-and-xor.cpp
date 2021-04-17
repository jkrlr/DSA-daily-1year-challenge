// Sansa and XOR
// https://www.hackerrank.com/challenges/sansa-and-xor/problem

// Hint 1 : It's all about Odd-Even (that means when their is a Q of XOR always think in terms of odd and even)
// Hint 2 : For each element count how many subarrays it appears in
// No. of subarray ith element appears in : (i)*(n-i+1)

#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define endl '\n'
#define INF 1000000000
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL)

using namespace std;

int ar[100001];

int main()
{       
    int t;
    cin>>t;

    while(t--)
    {           
        lli result = 0;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>ar[i];

// If n is even => each element appears even no. of times in subarrays
// If n is odd => 
// element at odd index in array(considering 1 based indexing) appears => odd no. of times in subarrays
// whereas element at even index in array(considering 1 based indexing) appears => even no. of times in subarrays

        if(n%2){
            for(int i=1;i<=n;i+=2)
                result^=ar[i];
        } 
        cout<<result<<endl;
    }
    return 0;
}


// int main()
// {
//     lli t , n;
//     cin>>t;
//     while(t--)
//     {
//         cin>>n;
//         REP(i , n) cin>>ar[i];
 
//         lli cnt;
//         lli res = 0;
//         for(lli i=1;i<=n;i++)
//         {
//             cnt = (i) * (n - i + 1);         // No. of subarray ith element appears in : (i)*(n-i+1)

//             if(cnt % 2) res ^= ar[i];
//         }
 
//         cout<<res<<endl;
//     }
// }