// https://www.hackerrank.com/challenges/and-product/problem

// Decimal	    Binary
// 0	        0000
// 1	        1000
// 2	        1000
// 3	        1100
// 4	        1000
// 5	        1010
// 6	        1100
// 7	        1110
// 8	        1000
// 9	        1001
// 10	        1010
// 11	        1011
// 12	        1100
// 13	        1101
// 14	        1110
// 15	        1111

// Observation : ith bit have 2^i consecutive 1's & 0's 

// Query : 5 8
// d = 8-5+1
// res=0

// Claim: if d>2^i, then ith bit will be 0 in result.
// Claim : if d<=2^i then if ith bit of a and b both are set then in result ith bit is also set.

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


int main()
{       
    int t;
    lli a,b;

    cin>>t;

    while(t--)
    {           

        cin>>a>>b;

        lli d = b-a;
        lli result = 0;
        lli f =1;
        for(lli i=0;i<32;i++){ 
		// If no. is 64 bit then we run loop from 0 to 63                        
            lli power_2 = f<<i;
            
            if(d>(power_2))
                continue;
            else
            {
                if((a&(power_2)) && (b&(power_2)))
                    result+=(power_2);
            }
        }
        cout<<result<<endl;
    }
    return 0;
}